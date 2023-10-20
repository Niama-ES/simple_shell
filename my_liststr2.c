#include "shell.h"
/**
 * list_len - determines length of linked list list h list
 * @h: pointer to first node node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
size_t length = 0;
int i;

for (i = 0; h; i++, h = h->next)
length++;
return (length);
}

/**
 * list_to_strings - returns an array array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t count = list_len(head);
char **strs;
char *str;
size_t i;

if (!head || !count)
return (NULL);

strs = malloc(sizeof(char *) * (count + 1));
if (!strs)
return (NULL);

for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
while (i > 0)
free(strs[--i]);
free(strs);
return (NULL);
}

_strcpy(str, node->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}

/**
 * print_list - prints al allll elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
size_t count = 0;

while (h)
{
printf("%ld: %s\n", (long)convert_number(h->num, 10, 0)
, h->str ? h->str : "(nil)");
h = h->next;
count++;
}

return (count);
}

/**
 * node_starts_with - returns noooooode whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to matttch
 * @c: the next character after prefix to match hjd
 *
 * Return: match node or null or slit
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *match = NULL;

while (node)
{
match = starts_with(node->str, prefix);

if (match && ((c == -1) || (*match == c)))
return (node);

node = node->next;
}

return (NULL);
}

/**
 * get_node_index - gets the index of a node klf
 * @head: pointer to list hhhead
 * @node: pointer to the node klf
 *
 * Return: index of node or -1 orrr 2
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t index = 0;

while (head)
{
if (head == node)
return (index);

head = head->next;
index++;
}

return (-1);
}
