#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * create_node - Creates a new hash node
 * @key: The key for the node
 * @value: The value for the node
 *
 * Return: Pointer to new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
hash_node_t *node = malloc(sizeof(hash_node_t));

if (!node)
return (NULL);

node->key = strdup(key);
if (!node->key)
{
free(node);
return (NULL);
}

node->value = strdup(value);
if (!node->value)
{
free(node->key);
free(node);
return (NULL);
}

node->next = NULL;
return (node);
}

/**
 * hash_table_set - Adds or updates an element in the hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *new_node, *tmp;
char *val_copy;
unsigned long int idx;

if (!ht || !key || !*key || !value)
return (0);

idx = key_index((const unsigned char *)key, ht->size);
tmp = ht->array[idx];

while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
val_copy = strdup(value);
if (!val_copy)
return (0);
free(tmp->value);
tmp->value = val_copy;
return (1);
}
tmp = tmp->next;
}

new_node = create_node(key, value);
if (!new_node)
return (0);

new_node->next = ht->array[idx];
ht->array[idx] = new_node;

return (1);
}
