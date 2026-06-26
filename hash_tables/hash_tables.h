#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stddef.h>

/**
 * struct s_hash_node - Node in the linked list
 * @key: The key string
 * @value: The value string
 * @next: Pointer to the next node
 */
typedef struct s_hash_node
{
	char *key;
	char *value;
	struct s_hash_node *next;
} hash_node_t;

/**
 * struct s_hash_table - Hash table
 * @size: Size of the array
 * @array: Array of hash_node_t pointers
 */
typedef struct s_hash_table
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* Function prototypes */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

#endif /* HASH_TABLES_H */
