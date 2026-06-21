#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * _update_value - Updates the value of an existing node
 * @node: The node to update
 * @value: The new value
 *
 * Return: 1 on success, 0 on failure
 */
static int _update_value(hash_node_t *node, const char *value)
{
	char *value_copy;

	value_copy = malloc(strlen(value) + 1);
	if (!value_copy)
		return (0);
	strcpy(value_copy, value);
	free(node->value);
	node->value = value_copy;
	return (1);
}

/**
 * _create_node - Creates a new hash table node
 * @key: The key for the node
 * @value: The value for the node
 *
 * Return: Pointer to new node, or NULL on failure
 */
static hash_node_t *_create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (NULL);

	node->key = malloc(strlen(key) + 1);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	strcpy(node->key, key);

	node->value = malloc(strlen(value) + 1);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	strcpy(node->value, value);
	node->next = NULL;

	return (node);
}

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add to
 * @key: The key of the element
 * @value: The value to associate with the key
 *
 * Description: Adds a new key/value pair to the hash table, or updates
 * an existing key. Handles collisions with chaining.
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !key || key[0] == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (_update_value(node, value));
		node = node->next;
	}

	node = _create_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
