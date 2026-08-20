#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: a pointer to the newly created sorted hash table, or NULL on fail
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
 * make_shash_node - creates a new sorted hash node
 * @key: the key (duplicated inside)
 * @value: the value (duplicated inside)
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
shash_node_t *node;

node = malloc(sizeof(shash_node_t));
if (node == NULL)
return (NULL);

node->key = strdup(key);
if (node->key == NULL)
{
free(node);
return (NULL);
}

node->value = strdup(value);
if (node->value == NULL)
{
free(node->key);
free(node);
return (NULL);
}

node->next = NULL;
node->sprev = NULL;
node->snext = NULL;

return (node);
}

/**
 * insert_sorted - inserts a node into the sorted (by key) doubly linked list
 * @ht: the sorted hash table
 * @node: the node to insert
 */
void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
shash_node_t *tmp;

if (ht->shead == NULL)
{
ht->shead = node;
ht->stail = node;
return;
}

tmp = ht->shead;
while (tmp != NULL && strcmp(tmp->key, node->key) < 0)
tmp = tmp->snext;

if (tmp == NULL)
{
/* insert at the tail */
node->sprev = ht->stail;
ht->stail->snext = node;
ht->stail = node;
}
else if (tmp == ht->shead)
{
/* insert at the head */
node->snext = ht->shead;
ht->shead->sprev = node;
ht->shead = node;
}
else
{
/* insert in the middle, right before tmp */
node->sprev = tmp->sprev;
node->snext = tmp;
tmp->sprev->snext = node;
tmp->sprev = node;
}
}

/**
 * shash_table_set - adds an element to a sorted hash table
 * @ht: the sorted hash table
 * @key: the key (cannot be empty string)
 * @value: the value associated with key
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *tmp, *node;
char *new_value;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);

tmp = ht->array[index];
while (tmp != NULL)
{
if (strcmp(tmp->key, key) == 0)
{
new_value = strdup(value);
if (new_value == NULL)
return (0);
free(tmp->value);
tmp->value = new_value;
return (1);
}
tmp = tmp->next;
}

node = make_shash_node(key, value);
if (node == NULL)
return (0);

node->next = ht->array[index];
ht->array[index] = node;

insert_sorted(ht, node);

return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the sorted hash table
 * @key: the key
 *
 * Return: the value associated with key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *tmp;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);

tmp = ht->array[index];
while (tmp != NULL)
{
if (strcmp(tmp->key, key) == 0)
return (tmp->value);
tmp = tmp->next;
}

return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table in key order
 * @ht: the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *tmp;
int first;

if (ht == NULL)
return;

first = 1;
printf("{");
tmp = ht->shead;
while (tmp != NULL)
{
if (!first)
printf(", ");
printf("'%s': '%s'", tmp->key, tmp->value);
first = 0;
tmp = tmp->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse key order
 * @ht: the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *tmp;
int first;

if (ht == NULL)
return;

first = 1;
printf("{");
tmp = ht->stail;
while (tmp != NULL)
{
if (!first)
printf(", ");
printf("'%s': '%s'", tmp->key, tmp->value);
first = 0;
tmp = tmp->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *tmp, *next;

if (ht == NULL)
return;

tmp = ht->shead;
while (tmp != NULL)
{
next = tmp->snext;
free(tmp->key);
free(tmp->value);
free(tmp);
tmp = next;
}

free(ht->array);
free(ht);
}
