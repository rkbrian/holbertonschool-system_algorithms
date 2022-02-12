#include "heap.h"
#include "huffman.h"

/**
 * huffman_priority_queue - function that creates a priority queue for
 *  the Huffman coding algorithm
 * @data: an array of characters of size
 * @freq: an array containing the associated frequencies (of size too)
 * @size: array size
 * Return: a ptr to the created min heap (also called priority queue)
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap;
	binary_tree_node_t *current = NULL;
	symbol_t *symbiote = NULL;
	size_t i = 0;

	if (!data || !freq || !size)
		return (NULL);
	heap = heap_create(freak_cmp);
	if (!heap)
		return (NULL);
	while (i < size)
	{
		symbiote = symbol_create(data[i], freq[i]);
		current = binary_tree_node(NULL, symbiote);
		current = heap_insert(heap, current), i++;
	}
	return (heap);
}

/**
 * freak_cmp - Compares two frequencies
 * @p1: First pointer
 * @p2: Second pointer
 * Return: Difference between the two strings
 */
int freak_cmp(void *p1, void *p2)
{
	size_t n1, n2;

	n1 = ((symbol_t *)(((binary_tree_node_t *)p1)->data))->freq;
	n2 = ((symbol_t *)(((binary_tree_node_t *)p2)->data))->freq;
	if (n1 > n2)
		return (1);
	else if (n1 < n2)
		return (-1);
	return (0);
}
