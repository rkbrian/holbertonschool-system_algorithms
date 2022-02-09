#include "heap.h"

/**
 * heap_create - function that creates a Heap data structure
 * @data_cmp: a pointer to a comparison function
 * Return: a pointer to the created heap_t structure, or NULL if it fails
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *hypocrite;

	hypocrite = malloc(sizeof(heap_t));
	if (!hypocrite)
		return (NULL);
	hypocrite->root = NULL, hypocrite->size = 0;
	hypocrite->data_cmp = data_cmp;
	return (hypocrite);
}
