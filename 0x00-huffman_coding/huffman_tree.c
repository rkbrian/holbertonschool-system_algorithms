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
	size_t i = 2, arr_size = size * 2 - 1;
        binary_tree_node_t **arr;
	int flag = 0;

	if (size < 2)
		return (NULL);
	huff_t = huffman_priority_queue(data, freq, size);
	if (!huff_t)
		return (NULL);
        arr = malloc(sizeof(binary_tree_node_t) * arr_size);
        if (!arr)
                return (NULL);
	huff_t->data_cmp = regular_cmp, unzip_data(huff_t->root);
        arr[0]->data = huff_t->root->data, arr[1]->data = huff_t->root->left->data;
	while (i < arr)
	{
		flag = huffman_extract_and_insert(huff_t);
                if ((huff_t->root-data))
                arr[i]->data = huff_t->root;
                arr[i + 1]->data = huff_t->root->left;
                printf("new root: %lu\n", ((symbol_t *)huff_t->root->data)->freq);
		if (!flag)
		{
			heap_delete(huff_t, NULL);
			return (NULL);
		}
		i++;
	}
	return (huff_t->root);
}

void unzip_data(binary_tree_node_t *root)
{
	binary_tree_node_t *curr = NULL, *curr_left = NULL, *curr_right = NULL;

	if (!root)
		return;
	curr = root, curr_left = curr->left, curr_right = curr->right;
	curr->data = (symbol_t *)(((binary_tree_node_t *)(curr->data))->data);
	unzip_data(curr_left), unzip_data(curr_right);
}
