#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Frees a hash table
 * @ht: The hash table to free
 *
 * Description: Frees all memory associated with the hash table,
 * including all nodes and their key/value strings.
 *
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *next;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}

	free(ht->array);
	free(ht);
}
