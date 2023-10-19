#include "shell.h"
/**
 * input_buf - Buffers chained commands.
 * @info: Parameter struct.
 * @buf: Address of buffer.
 * @len: Address of len var.
 *
 * Return: Bytes read.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t bytes_read = 0;
size_t new_len = 0;

if (!*len) /* If nothing left in the buffer, fill it */
{
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);

#if USE_GETLINE
bytes_read = getline(buf, &new_len, stdin);
#else
bytes_read = _getline(info, buf, &new_len);
#endif

if (bytes_read > 0)
{
if ((*buf)[bytes_read - 1] == '\n')
{
(*buf)[bytes_read - 1] = '\0'; /* Remove trailing newline */
bytes_read--;
}

info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);

/* Check if it's a command chain */
if (_strchr(*buf, ';'))
{
*len = bytes_read;
info->cmd_buf = buf;
}
}
}
return (bytes_read);
}

/**
 * get_input - Gets a line minus the newline.
 * @info: Parameter struct.
 *
 * Return: Bytes read.
 */
ssize_t get_input(info_t *info)
{
static char *chain_buffer; /* The ';' command chain buffer */
static size_t chain_pos, current_pos, chain_length;
ssize_t bytes_read = 0;
char **command_buffer_ptr = &(info->arg), *command;
_putchar(BUF_FLUSH);
bytes_read = input_buf(info, &chain_buffer, &chain_length);
if (bytes_read == -1) /* EOF */
return (-1);
if (chain_length) /* There are commands left in the chain buffer */
{
current_pos = chain_pos;
command = chain_buffer + chain_pos; /* Get a pointer for the return */
check_chain(info, chain_buffer, &current_pos, chain_pos, chain_length);
while (current_pos < chain_length) /* Iterate to semicolon or end */
{
if (is_chain(info, chain_buffer, &current_pos))
break;
current_pos++;
}
chain_pos = current_pos + 1; /* Increment past null character (';') */

if (chain_pos >= chain_length) /* Reached the end of the buffer? */
{
chain_pos = chain_length = 0; /* Reset position and length */
info->cmd_buf_type = CMD_NORM;
}
*command_buffer_ptr = command;
return (_strlen(command));
}
*command_buffer_ptr = chain_buffer;
return (bytes_read); /* Return length from _getline() */
}

/**
 * read_buf - Reads a buffer.
 * @info: Parameter struct.
 * @buf: Buffer.
 * @i: Size.
 *
 * Return: Number of bytes read (r).
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t bytes_read = 0;
if (*i)
return (0);
bytes_read = read(info->readfd, buf, READ_BUF_SIZE);
if (bytes_read >= 0)
*i = bytes_read;
return (bytes_read);
}

/**
 * _getline - Gets the next line of input from STDIN.
 * @info: Parameter struct.
 * @ptr: Address of a pointer to the buffer, preallocated or NULL.
 * @length: Size of the preallocated ptr buffer if not NULL.
 *
 * Return: The number of characters read (s).
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buffer[READ_BUF_SIZE];
static size_t buffer_index, buffer_length;
size_t k;
ssize_t read_result = 0, chars_read = 0;
char *current_ptr = NULL, *new_ptr = NULL, *newline;
current_ptr = *ptr;
if (current_ptr && length)
chars_read = *length;
if (buffer_index == buffer_length)
buffer_index = buffer_length = 0;
read_result = read_buf(info, buffer, &buffer_length);
if (read_result == -1 || (read_result == 0 && buffer_length == 0))
return (-1);
newline = _strchr(buffer + buffer_index, '\n');
k = newline ? 1 + (unsigned int)(newline - buffer) :
buffer_length;
new_ptr = _realloc(current_ptr, chars_read,
(current_ptr && chars_read) ? chars_read + k : k + 1);

if (!new_ptr) /* MALLOC FAILURE! */
return (current_ptr ? free(current_ptr), -1 : -1);
if (chars_read)
_strncat(new_ptr, buffer + buffer_index, k - buffer_index);
else
_strncpy(new_ptr, buffer + buffer_index,
k - buffer_index + 1);
chars_read += k - buffer_index;
buffer_index = k;
current_ptr = new_ptr;
if (length)
*length = chars_read;
*ptr = current_ptr;
return (chars_read);
}

/**
 * sigintHandler - Blocks Ctrl-C signal.
 * @sig_num: The signal number (unused).
 *
 * Return: Void.
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
_puts("\n$ ");
_putchar(BUF_FLUSH);
}

