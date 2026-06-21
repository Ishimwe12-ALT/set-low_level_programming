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
/**
 * struct shash_node_s - Node of a sorted hash table
 * @key: The key string
 * @value: The value string
 * @next: Pointer to next node (collision chain)
 * @sprev: Pointer to previous element in sorted list
 * @snext: Pointer to next element in sorted list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table
 * @size: Size of the array
 * @array: Array of shash_node_t pointers
 * @shead: Pointer to first element of sorted list
 * @stail: Pointer to last element of sorted list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

/* Sorted hash table functions */
shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */
#endif /* HASH_TABLES_H */
