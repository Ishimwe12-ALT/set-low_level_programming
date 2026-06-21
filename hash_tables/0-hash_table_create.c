#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a new hash table
 * @size: The size of the hash table array
 *
 * Description: Allocates memory for a new hash table structure
 * and its array of pointers. Initializes all pointers to NULL.
 *
 * Return: Pointer to the newly created hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
		return (NULL);

	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}
