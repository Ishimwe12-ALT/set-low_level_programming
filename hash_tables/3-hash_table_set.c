#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in the hash table
 * @ht: The hash table to add or update key/value
 * @key: The key (cannot be empty)
 * @value: The value associated with the key (must be duplicated)
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *new_node, *tmp;
char *value_copy;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

value_copy = strdup(value);
if (value_copy == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);
tmp = ht->array[index];

while (tmp != NULL)
{
if (strcmp(tmp->key, key) == 0)
{
free(tmp->value);
tmp->value = value_copy;
return (1);
}
tmp = tmp->next;
}

new_node = malloc(sizeof(hash_node_t));
if (new_node == NULL)
{
free(value_copy);
return (0);
}

new_node->key = strdup(key);
if (new_node->key == NULL)
{
free(value_copy);
free(new_node);
return (0);
}

new_node->value = value_copy;
new_node->next = ht->array[index];
ht->array[index] = new_node;

return (1);
}
