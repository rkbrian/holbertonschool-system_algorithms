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
	binary_tree_node_t *par = NULL, *l_node = NULL, *r_node = NULL;
	char data = -1;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	priority_queue->data_cmp = freak_cmp;
	l_node = (binary_tree_node_t *)heap_extract(priority_queue);
	data_a = ((symbol_t *)l_node->data)->freq;
	r_node = (binary_tree_node_t *)heap_extract(priority_queue);
	data_b = ((symbol_t *)r_node->data)->freq, ab = data_a + data_b;
	par = binary_tree_node(NULL, symbol_create(data, ab));
	par->left = l_node, par->right = r_node;
	r_node->parent = par, l_node->parent = par;
	heap_insert(priority_queue, par);
	return (1);
}
