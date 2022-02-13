#include "heap.h"
#include "huffman.h"

/**
 * huffman_extract_and_insert - function that extracts the two nodes of the
 *  priority queue and insert a new one
 * @priority_queue: a pointer to the priority queue to extract from
 * Return: 1 on success or 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	size_t ab, data_a, data_b;
	binary_tree_node_t *new_node = NULL;
	symbol_t *symbiote = NULL;
	char data = -1;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	if (priority_queue->data_cmp == freak_cmp)
	{
		new_node = (binary_tree_node_t *)heap_extract(priority_queue);
		data_a = ((symbol_t *)new_node->data)->freq;
		/*free(new_node->data), */free(new_node);
		new_node = (binary_tree_node_t *)heap_extract(priority_queue);
		data_b = ((symbol_t *)new_node->data)->freq;
		ab = data_a + data_b, ((symbol_t *)new_node->data)->data = data;
		((symbol_t *)new_node->data)->freq = ab;
		heap_insert(priority_queue, new_node);
	}
	else if (priority_queue->data_cmp == regular_cmp)
	{
		symbiote = (symbol_t *)heap_extract(priority_queue);
		data_a = symbiote->freq/*, free(symbiote)*/;
		symbiote = (symbol_t *)heap_extract(priority_queue);
		data_b = symbiote->freq, ab = data_a + data_b;
		symbiote->data = data, symbiote->freq = ab;
		heap_insert(priority_queue, symbiote);
	}
	return (1);
}

/**
 * regular_cmp - Compares two frequencies in 2 unzipped data
 * @p1: First pointer
 * @p2: Second pointer
 * Return: Difference between the two frequencies
 */
int regular_cmp(void *p1, void *p2)
{
	size_t n1, n2;

	n1 = ((symbol_t *)(p1))->freq;
	n2 = ((symbol_t *)(p2))->freq;
	if (n1 > n2)
		return (1);
	else if (n1 < n2)
		return (-1);
	return (0);
}
