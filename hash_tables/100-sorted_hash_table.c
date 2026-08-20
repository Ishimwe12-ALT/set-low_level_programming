#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the array
 *
 * Return: Pointer to the newly created sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int i;

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

for (i = 0; i < size; i++)
ht->array[i] = NULL;

ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

/**
 * add_sorted_node - Inserts a node into the sorted doubly linked list
 * @ht: Pointer to the sorted hash table
 * @node: Node to insert
 */
static void add_sorted_node(shash_table_t *ht, shash_node_t *node)
{
shash_node_t *tmp;

if (ht->shead == NULL)
{
ht->shead = node;
ht->stail = node;
node->sprev = NULL;
node->snext = NULL;
return;
}

if (strcmp(ht->shead->key, node->key) > 0)
{
node->snext = ht->shead;
node->sprev = NULL;
ht->shead->sprev = node;
ht->shead = node;
return;
}

tmp = ht->shead;
while (tmp->snext != NULL && strcmp(tmp->snext->key, node->key) < 0)
tmp = tmp->snext;

node->snext = tmp->snext;
node->sprev = tmp;
if (tmp->snext == NULL)
ht->stail = node;
else
tmp->snext->sprev = node;
tmp->snext = node;
}

/**
 * shash_table_set - Adds or updates an element in the sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: Key string (cannot be empty)
 * @value: Value associated with key (must be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *new_node, *tmp;
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

new_node = malloc(sizeof(shash_node_t));
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

add_sorted_node(ht, new_node);
return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: Pointer to the sorted hash table
 * @key: Key to search for
 *
 * Return: Value associated with key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];

while (node != NULL)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}

return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table using the sorted list
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;
char flag = 0;

if (ht == NULL)
return;

printf("{");
node = ht->shead;
while (node != NULL)
{
if (flag == 1)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
flag = 1;
node = node->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;
char flag = 0;

if (ht == NULL)
return;

printf("{");
node = ht->stail;
while (node != NULL)
{
if (flag == 1)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
flag = 1;
node = node->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and frees memory
 * @ht: Pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node, *tmp;

if (ht == NULL)
return;

node = ht->shead;
while (node != NULL)
{
tmp = node->snext;
free(node->key);
free(node->value);
free(node);
node = tmp;
}

free(ht->array);
free(ht);
}
