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
	while (leftmost && leftmost->left)
		leftmost = leftmost->left, left_h++;
	imba(heap->root, 0, left_h), shorty = imba_node(NULL), imba_node(shorty);
	if (shorty)
	{
		if (shorty->left)
			tmp = binary_tree_node(shorty, data), shorty->right = tmp;
		else
			tmp = binary_tree_node(shorty, data), shorty->left = tmp;
	}
	else
		tmp = binary_tree_node(leftmost, data), leftmost->left = tmp;
	heap->size++, heap->root = bubble_up(heap, tmp);
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
	static binary_tree_node_t *im_shorty;

	if (node && im_shorty != node)
		im_shorty = node;
	else if (im_shorty == node)
		im_shorty = NULL;
	return (im_shorty);
}

/**
 * bubble_up - function to switch newly inserted nodes by function data_cmp
 * @heap: a pointer to the heap in which the node has to be inserted
 * @node: newly inserted node
 * Return: new root
 */
binary_tree_node_t *bubble_up(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *tmp = NULL, *tmp_left = NULL, *tmp_right = NULL;
	binary_tree_node_t *node_left = NULL, *node_right = NULL;

	while (node->parent && heap->data_cmp(node->data, node->parent->data) < 0)
	{
		tmp = node->parent, tmp_left = tmp->left, tmp_right = tmp->right;
		node_left = node->left, node_right = node->right; /*inits*/
		if (tmp->parent && tmp->parent->left == tmp)
			tmp->parent->left = node;
		else if (tmp->parent && tmp->parent->right == tmp)
			tmp->parent->right = node;
		node->parent = tmp->parent, tmp->left = node_left, tmp->right = node_right;
		if (node_left)
			node_left->parent = tmp;
		if (node_right)
			node_right->parent = tmp;
		if (tmp_left == node)
		{
			node->right = tmp_right, node->left = tmp, tmp->parent = node;
			if (tmp_right)
				tmp_right->parent = node;
		}
		else if (tmp_right == node)
		{
			node->left = tmp_left, node->right = tmp, tmp->parent = node;
			if (tmp_left)
				tmp_left->parent = node;
		}
	}
	tmp = node;
	while (tmp->parent)
		tmp = tmp->parent;
	return (tmp);
}
