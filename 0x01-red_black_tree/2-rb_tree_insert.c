#include "rb_trees.h"

/**
 * rb_tree_insert - function that inserts a value in a Red-Black Tree
 * @tree: pointer to the root node of the tree to traverse
 * @value: value to store in the new node
 * Return: ptr to the created node, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *tmp = NULL, *ret_node = NULL;

	if (*tree == NULL)
		return (*tree = rb_tree_node(*tree, value, BLACK));
	tmp = *tree;
	while (tmp)
	{
		if ((tmp->n > value) && tmp->left)
			tmp = tmp->left;
		else if ((tmp->n < value) && tmp->right)
			tmp = tmp->right;
		else if (tmp->n == value)
			return (NULL);
		else if (tmp->n > value) /*insert to the left*/
		{
			tmp->left = rb_tree_node(tmp, value, RED);
			ret_node = tmp->left;
			break;
		}
		else if (tmp->n < value) /*insert to the right*/
		{
			tmp->right = rb_tree_node(tmp, value, RED);
			ret_node = tmp->right;
			break;
		}
	}
	rb_rotator(tree, ret_node);
	while ((*tree)->parent)
		*tree = (*tree)->parent;
	return (ret_node);
}

/**
 * rb_rotator - rotate freshly inserted red black tree if necessary.
 *  Notes: no rotation nor color change if parent doesn't exist
 * @tree: pointer to the root node of the tree to traverse
 * @tmp: the freshly inserted node.
 */
void rb_rotator(rb_tree_t **tree, rb_tree_t *tmp)
{
	rb_tree_t *uncle = NULL;

	if (tmp->parent == NULL)
		tmp->color = BLACK, *tree = tmp;
	else if (tmp->parent->color == RED)
	{
		uncle = rb_tree_uncle(tmp);
		if (uncle && uncle->color == RED)
			case_triangle(tree, tmp->parent);
		else
			case_bar(tree, tmp);
	}
}

/**
 * case_triangle - when the new node, its parent and its grandpa form a
 *  triangle in red uncle case, change colors.
 * @tree: pointer to the root node of the tree to traverse
 * @parent: parent of the freshly inserted node.
 */
void case_triangle(rb_tree_t **tree, rb_tree_t *parent)
{
	rb_tree_t *grandpa = parent->parent, *uncle = NULL;

	parent->color = RED + BLACK - parent->color;
	grandpa->color = RED + BLACK - grandpa->color;
	if (grandpa->left == parent)
		uncle = grandpa->right;
	else
		uncle = grandpa->left;
	if (uncle)
		uncle->color = BLACK;
	rb_rotator(tree, grandpa);
}

/**
 * case_bar - for all the red uncle case, rotate nodes and change colors.
 * @tree: pointer to the root node of the tree to traverse
 * @tmp: the freshly inserted node.
 */
void case_bar(rb_tree_t **tree, rb_tree_t *tmp)
{
	rb_tree_t *parent = tmp->parent, *grandpa = tmp->parent->parent;

	if (parent->right == tmp && grandpa->left == parent) /*right triangle*/
		rb_tree_rotate_left(parent), tmp = tmp->left;
	else if (parent->left == tmp && grandpa->right == parent) /*left triangle*/
		rb_tree_rotate_right(parent), tmp = tmp->right;
	parent = tmp->parent, grandpa = tmp->parent->parent;
	if (parent->left == tmp)
		rb_tree_rotate_right(grandpa);
	else
		rb_tree_rotate_left(grandpa);
	if (parent->parent == NULL) /*black root*/
		*tree = parent;
	parent->color = RED + BLACK - parent->color;
	grandpa->color = RED + BLACK - grandpa->color;
	if (tmp->color == RED && parent->color == RED)
		tmp->color = BLACK;
}

/**
 * rb_tree_rotate_left - perform a left-rotation on a red black tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: pointer to the new root node, or null
 */
rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree)
{
	rb_tree_t *tmp = NULL, *new_root = NULL, *parent = NULL;

	if (!tree || !tree->right)
		return (NULL);
	tmp = tree, new_root = tree->right, parent = tmp->parent;
	tmp->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tmp;
	tmp->parent = new_root;
	new_root->left = tmp;
	new_root->parent = parent;
	if (parent && parent->left && parent->left->n == tmp->n)
		parent->left = new_root;
	else if (parent && parent->right && parent->right->n == tmp->n)
		parent->right = new_root;
	return (new_root);
}

/**
 * rb_tree_rotate_right - perform a right-rotation on a red black tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: pointer to the new root node, or null
 */
rb_tree_t *rb_tree_rotate_right(rb_tree_t *tree)
{
	rb_tree_t *tmp = NULL, *new_root = NULL, *parent = NULL;

	if (!tree || !tree->left)
		return (NULL);
	tmp = tree, new_root = tree->left, parent = tmp->parent;
	tmp->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tmp;
	tmp->parent = new_root;
	new_root->right = tmp;
	new_root->parent = parent;
	if (parent && parent->left && parent->left->n == tmp->n)
		parent->left = new_root;
	else if (parent && parent->right && parent->right->n == tmp->n)
		parent->right = new_root;
	return (new_root);
}

/**
 * rb_tree_uncle - finds the uncle of a node
 * @node: pointer to the node
 * Return: pointer to the uncle node, or null
 */
rb_tree_t *rb_tree_uncle(rb_tree_t *node)
{
	if (!node || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node)
		return (node->parent->parent->right);
	if (node->parent->parent->right == node)
		return (node->parent->parent->left);
	return (NULL);
}
