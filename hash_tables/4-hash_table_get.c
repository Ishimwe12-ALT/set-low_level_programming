#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value from a hash table
 * @ht: The hash table to search
 * @key: The key to look up
 *
 * Description: Searches the hash table for the given key and returns
 * the associated value.
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
