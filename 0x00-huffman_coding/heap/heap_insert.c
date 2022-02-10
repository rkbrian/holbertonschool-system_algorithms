#include "heap.h"

/**
 * heap_insert - function that inserts a value in a Min Binary Heap
 * @heap: a pointer to the heap in which the node has to be inserted
 * @data: a pointer containing the data to store in the new node
 * Return: a pointer to the created node containing data, or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *leftmost = NULL, *tmp, *shorty = NULL;
	int left_h = 1;

	if (!heap || !data)
		return (NULL);
	if (heap->root == NULL)
	{
		heap->root = binary_tree_node(NULL, data), heap->size++;
		return (heap->root);
	}
	leftmost = heap->root;
	if (heap->size == 1)
	{
		tmp = binary_tree_node(NULL, data);
		if (tmp)
			leftmost->parent = tmp, tmp->left = leftmost, heap->size++, heap->root = tmp;
		return (tmp);
	}
	while (leftmost && leftmost->left)
		leftmost = leftmost->left, left_h++;
	imba(heap->root, 0, left_h), shorty = imba_node(NULL), imba_node(shorty);
	if (shorty)
	{
		if (shorty->left)
			tmp = binary_tree_node(shorty, data), shorty->right = tmp;
		else
		{
			tmp = binary_tree_node(shorty->parent, data);
			if (tmp)
				shorty->parent = tmp, tmp->left = shorty;
		}
	}
	else
	{
		tmp = binary_tree_node(leftmost->parent, data);
		if (tmp)
			leftmost->parent->left = tmp, leftmost->parent = tmp, tmp->left = leftmost;
	}
	heap->size++;
	return (tmp);
}

/**
 * imba - function to locate the 1st leaf of short branches in an imperfect
 *  heap tree. If the heap tree is perfect, do nothing.
 * @node: heap tree node
 * @height: height of the node
 * @left_h: height of the heap tree
 */
void imba(binary_tree_node_t *node, int height, int left_h)
{
	int h = height + 1;

	if (node->left)
		imba(node->left, h, left_h);
	if (node->right)
		imba(node->right, h, left_h);
	if (node->right == NULL && h < left_h && imba_node(NULL) == NULL)
	{
		if (node->left && node->left->left == NULL && node->left->right == NULL)
			imba_node(node);
		else if (node->left == NULL)
			imba_node(node);
	}
}

/**
 * imba_node - function to store a heap tree leaf, and clear it when needed.
 * @node: the 1st leaf of short branches in an imperfect heap tree, or NULL
 * Return: stored leaf, or NULL
 */
binary_tree_node_t *imba_node(binary_tree_node_t *node)
{
	static binary_tree_node_t *im_shorty = NULL;

	if (node && im_shorty != node)
		im_shorty = node;
	else if (im_shorty == node)
		im_shorty = NULL;
	return (im_shorty);
}
