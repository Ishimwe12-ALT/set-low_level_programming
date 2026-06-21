#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add to
 * @key: The key of the element
 * @value: The value to associate with the key
 *
 * Description: Adds a new key/value pair to the hash table, or updates
 * an existing key. Handles collisions with chaining.
 * In case of collision, adds new node at beginning of list.
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;
	char *value_copy;

	if (!ht || !key || key[0] == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			value_copy = malloc(strlen(value) + 1);
			if (!value_copy)
				return (0);
			strcpy(value_copy, value);
			free(node->value);
			node->value = value_copy;
			return (1);
		}
		node = node->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);

	node->key = malloc(strlen(key) + 1);
	if (!node->key)
	{
		free(node);
		return (0);
	}
	strcpy(node->key, key);

	node->value = malloc(strlen(value) + 1);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (0);
	}
	strcpy(node->value, value);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
