#include "heap.h"
#include "huffman.h"

/**
 * huffman_tree - function that builds the Huffman tree
 * @data: an array of characters of size
 * @freq: an array containing the associated frequencies (of size too)
 * @size: array size
 * Return: a ptr to the root node of the Huffman tree, or NULL if it fails
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *huff_t;
	binary_tree_node_t *node = NULL;
	int i;

	huff_t = huffman_priority_queue(data, freq, size);
	if (!huff_t)
		return (NULL);
	i = huffman_extract_and_insert(huff_t);
	while (i)
		i = huffman_extract_and_insert(huff_t);
	node = (binary_tree_node_t *)(huff_t->root->data);
	heap_delete(huff_t, NULL);
	return (node);
}
