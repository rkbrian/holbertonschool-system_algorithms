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
	binary_tree_node_t **node_arr;
	symbol_t *symbiote = NULL;
	size_t i = 0, level = 1;

	if (!data || !freq || !size)
		return (NULL);
	heap = heap_create(NULL);
	if (!heap)
		return (NULL);
	node_arr = malloc(sizeof(binary_tree_node_t) * size);
	if (!node_arr)
	{
		free(heap);
		return (NULL);
	}
	sortof(data, freq, size);
	while (i < size)
	{
		symbiote = symbol_create(data[i], freq[i]);
		node_arr[i] = binary_tree_node(NULL, symbiote);
		node_arr[i] = binary_tree_node(NULL, node_arr[i]), i++;
	}
	heap->root = node_arr[0], i = 1, heap->size++;
	while (i < size)
	{
		while (i < size && i < (size_t)(1 << level))
		{
			node_arr[i]->parent = node_arr[(i - 1) / 2];
			if (i % 2)
				node_arr[(i - 1) / 2]->left = node_arr[i];
			else
				node_arr[(i - 1) / 2]->right = node_arr[i];
			i++, heap->size++;
		}
		level++;
	}
	free(node_arr);
	return (heap);
}

/**
 * sortof - function to sort data and frequency arrays in increasing order
 *  of frequency, bubble sort -- yeah, I know it's slow, but I'm asked NOT
 *  to write too many functions as quicksort requires.
 * @data: an array of characters of size
 * @freq: an array containing the associated frequencies (of size too)
 * @size: array size
 */
void sortof(char *data, size_t *freq, size_t size)
{
	char tmp_data;
	size_t i, j, tmp, need_more_sort_flag;

	if (!data || !freq || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		need_more_sort_flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (freq[j] > freq[j + 1])
			{
				tmp = freq[j], tmp_data = data[j];
				freq[j] = freq[j + 1], data[j] = data[j + 1];
				freq[j + 1] = tmp, data[j + 1] = tmp_data;
				need_more_sort_flag = 1;
			}
		}
		if (need_more_sort_flag == 0)
			break;
	}
}
