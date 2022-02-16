#include "heap.h"

/**
 * heap_extract - function that extracts the root value of a Min Binary Heap
 * @heap: a pointer to the heap from which to extract the value
 * Return: a ptr to the data that was stored in the root node of the heap,
 *  or NULL if function fails or heap is NULL.
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *leftmost = NULL, *q_cur = NULL, *ret, *last_node = NULL;
	int left_h = 1;
	void *ret_d;

	if (!heap)
		return (NULL);
	if (heap->root->left == NULL && heap->root->right == NULL)
	{
		ret = heap->root, ret_d = ret->data, heap->root = NULL;
		free(ret), heap->size--;
		return (ret_d);
	}
	leftmost = heap->root, q_cur = heap->root;
	while (leftmost && leftmost->left)
		leftmost = leftmost->left, left_h++;
	last_node = keep_going(q_cur, 1, left_h);
	ret_d = swapme(heap, last_node);
	return (ret_d);
}

/**
 * keep_going - function to find the last node recursively
 * @node: current node to be tested if it is the last node
 * @cur: current node height
 * @h: max tree height
 * Return: the last node
 */
binary_tree_node_t *keep_going(binary_tree_node_t *node, int cur, int h)
{
	static binary_tree_node_t *lastn;

	if (cur == h)
	{
		lastn = node;
		return (lastn);
	}
	if (node->left)
		keep_going(node->left, cur + 1, h);
	if (node->right)
		keep_going(node->right, cur + 1, h);
	return (lastn);
}

/**
 * swapme - function to swap the last node with the root (to be extracted)
 * @heap: a pointer to the heap from which to extract the value
 * @lastn: the last node of the heap tree
 * Return: extracted data
 */
void *swapme(heap_t *heap, binary_tree_node_t *lastn)
{
	binary_tree_node_t *ret = NULL;
	void *ret_data;

	ret = heap->root, ret_data = ret->data, heap->root = lastn;
	if (lastn->parent->left == lastn)
		lastn->parent->left = NULL;
	else if (lastn->parent->right == lastn)
		lastn->parent->right = NULL;
	lastn->parent = NULL;
	if (heap->size > 3)
	{
		lastn->left = ret->left, lastn->right = ret->right;
		ret->left->parent = lastn, ret->right->parent = lastn;
	}
	else if (heap->size == 3)
		lastn->left = ret->left, ret->left->parent = lastn;
	free(ret), heap->size--, ret = heap->root, titanic(heap, ret);
	return (ret_data);
}

/**
 * titanic - function to sink the larger heap data
 * @heap: a pointer to the heap from which to extract the value
 * @root: heap node with large data
 */
void titanic(heap_t *heap, binary_tree_node_t *root)
{
	binary_tree_node_t *c = root;
	void *t;

	while (c->left || c->right)
	{
		if (c->left && c->right)
		{
			if (heap->data_cmp(c->left->data, c->right->data) < 0 &&
			heap->data_cmp(c->left->data, c->data) < 0)
				t = c->left->data, c->left->data = c->data, c->data = t, c = c->left;
			else if (heap->data_cmp(c->left->data, c->right->data) > 0 &&
			heap->data_cmp(c->right->data, c->data) < 0)
				t = c->right->data, c->right->data = c->data, c->data = t, c = c->right;
			else
				break;
		}
		else if (c->left)
		{
			if (heap->data_cmp(c->left->data, c->data) < 0)
				t = c->left->data, c->left->data = c->data, c->data = t, c = c->left;
			else
				break;
		}
		else
		{
			if (heap->data_cmp(c->right->data, c->data) < 0)
				t = c->right->data, c->right->data = c->data, c->data = t, c = c->right;
			else
				break;
		}
	}
}
