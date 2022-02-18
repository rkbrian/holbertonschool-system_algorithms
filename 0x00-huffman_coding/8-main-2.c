#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));
void _binary_tree_node_delete(binary_tree_node_t *node, void (*free_data)(void *));

/**
 * symbol_print - Prints a symbol structure
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int symbol_print(char *buffer, void *data)
{
	symbol_t *symbol;
	char c;
	int length;

	symbol = (symbol_t *)data;
	c = symbol->data;
	if (c == -1)
		c = '$';
	length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
	return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	binary_tree_node_t *root;
	char data[] = {
		'H', 'o', 'l', 'b', 'e', 'r', 't', 'o', 'n'
	};
	size_t freq[] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1
	};
	size_t size = sizeof(data) / sizeof(data[0]);

	root = huffman_tree(data, freq, size);
	if (!root)
	{
		fprintf(stderr, "Failed to build Huffman tree\n");
		return (EXIT_FAILURE);
	}
	binary_tree_print(root, symbol_print);

	/*_binary_tree_node_delete(root, &free);*/
	return (EXIT_SUCCESS);
}