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
	size_t ab, data_a, data_b, size, level = 1;
	binary_tree_node_t *new_node = NULL, **node_arr;
	char data = -1;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	new_node = (binary_tree_node_t *)priority_queue->root->data;
	data_a = ((symbol_t *)new_node->data)->freq;
	new_node = (binary_tree_node_t *)priority_queue->root->left->data;
	data_b = ((symbol_t *)new_node->data)->freq;
        size = node_count(priority_queue->root);
	node_arr = malloc(sizeof(binary_tree_node_t) * size);
	if (!node_arr)
		return (0);
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

	/*data_b = ((symbol_t *)((binary_tree_node_t *)heap_extract(priority_queue))->data)->freq;*/
	ab = data_a + data_b, ((symbol_t *)new_node->data)->freq = ab;
	((symbol_t *)new_node->data)->data = data;
	new_node = priority_queue->root;
	kitchen_sink(new_node);
	return (1);
}

/**
 * node_count - measure the size of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: size of binary tree, or 0 if tree is null
 */
size_t node_count(const binary_tree_node_t *tree)
{
	size_t i = 0, l_i, r_i;

	if (!tree)
		return (0);
	else if (tree->left == NULL && tree->right == NULL)
		return (1);
	l_i = binary_tree_size(tree->left), r_i = binary_tree_size(tree->right);
	i = l_i + r_i;
	return (i + 1);
}

/**
 * kitchen_sink - function to sink the larger heap data for prio queue
 * @root: heap node with large data
 */
void kitchen_sink(binary_tree_node_t *root)
{
	binary_tree_node_t *c = root;
	void *t;
	size_t lv, rv, pv;

	while (c->left || c->right)
	{
		pv = ((symbol_t *)((binary_tree_node_t *)c->data)->data)->freq, printf("pv: %lu\n", pv);
		if (c->left && c->right)
		{
			lv = ((symbol_t *)((binary_tree_node_t *)c->left->data)->data)->freq, printf("lv: %lu\n", lv);
			rv = ((symbol_t *)((binary_tree_node_t *)c->right->data)->data)->freq, printf("rv: %lu\n", rv);
			if (lv < rv && pv > lv)
				t = c->left->data, c->left->data = c->data, c->data = t, c = c->left;
			else if (lv > rv && pv > rv)
				t = c->right->data, c->right->data = c->data, c->data = t, c = c->right;
			else
				break;
		}
		else if (c->left)
		{
			lv = ((symbol_t *)((binary_tree_node_t *)c->left->data)->data)->freq, printf("lv: %lu\n", lv);
			if (lv < pv)
				t = c->left->data, c->left->data = c->data, c->data = t, c = c->left;
			else
				break;
		}
		else
		{
			rv = ((symbol_t *)((binary_tree_node_t *)c->right->data)->data)->freq, printf("rv: %lu\n", rv);
			if (rv < pv)
				t = c->right->data, c->right->data = c->data, c->data = t, c = c->right;
			else
				break;
		}
	}
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
