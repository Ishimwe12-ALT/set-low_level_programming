#include "hash_tables.h"

/**
 * key_index - Returns the index of a key in a hash table array
 * @key: The key to hash
 * @size: The size of the hash table array
 *
 * Description: Uses the djb2 algorithm to generate a hash and
 * returns the index where the key should be stored.
 *
 * Return: The index in the array
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
