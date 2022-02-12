#include "heap.h"
#include "huffman.h"

int bested_print(char *buffer, void *data)
{
    binary_tree_node_t *nested;
    symbol_t *symbol;
    char c;
    int length;

    nested = (binary_tree_node_t *)data;
    symbol = (symbol_t *)nested->data;
    c = symbol->data;
    if (c == -1)
        c = '$';
    length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
    return (length);
}

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
        symbol_t *symbiote;
	char data = -1;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	new_node = (binary_tree_node_t *)heap_extract(priority_queue);
	data_a = ((symbol_t *)new_node->data)->freq, printf("data a: %lu\n", data_a);
        free(new_node->data), free(new_node);

        binary_tree_print(priority_queue->root, bested_print);
        printf("bested print\n");

	new_node = (binary_tree_node_t *)heap_extract(priority_queue);
	data_b = ((symbol_t *)new_node->data)->freq, printf("data b: %lu\n", data_b);
        free(new_node->data), symbiote = malloc(sizeof(symbol_t));
        if (!symbiote)
        {
                free(new_node);
                return (0);
        }
        ab = data_a + data_b, symbiote->data = data, symbiote->freq = ab;
        new_node->data = symbiote;

        binary_tree_print(priority_queue->root, bested_print);
        printf("bested print bbbbbbb\n");

        heap_insert(priority_queue, new_node);
	return (1);
}
