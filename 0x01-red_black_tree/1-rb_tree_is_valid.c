#include "rb_trees.h"

/**
 * rb_tree_is_valid - check if a binary tree is a valid Red Black Tree.
 *  Notes: this time I use recursive methods instead of queue iteration
 * @tree: pointer to the root node of the tree to traverse
 * Return: return 1 if tree is a valid RBT, and 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	int tree_height, bad_beast;

	if (!tree)
		return (0);
	if (tree->color != BLACK)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (red_check(tree) == 0)
		return (0);
	bad_beast = beast_wars(tree->left, tree->n, 0);
	if (bad_beast > 0)
		return (0);
	bad_beast = beast_wars(tree->right, tree->n, 1);
	if (bad_beast > 0)
		return (0);
	tree_height = rb_tree_height(tree);
	if (rb_tree_balance(tree, tree_height, 0) == 0)
		return (0);
	return (1);
}

/**
 * red_check - check if there is no continuous red node to meet RBT std
 * @tree: pointer to the node of the tree to traverse
 * Return: return 1 if no continuous red node, and 0 otherwise
 */
int red_check(const rb_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->color != RED && tree->color != BLACK)
		return (0);
	if (tree->color == RED)
	{
		if ((tree->left && tree->left->color == RED) ||
		    (tree->right && tree->right->color == RED))
			return (0);
	}
	return (red_check(tree->left) * red_check(tree->right));
}

/**
 * beast_wars - compare all values in a tree with root value for BST validity
 * @tree: pointer to a child of the root node of the tree to traverse
 * @root_num: root node value
 * @direction: 0 if node is left child, 1 for right child
 * Return: 0 for valid bst, 1 otherwise
 */
int beast_wars(const rb_tree_t *tree, int root_num, int direction)
{
	int i = 0;

	if (!tree)
		return (0);
	if (direction == 0 && tree->n >= root_num)
		i++;
	else if (direction == 1 && tree->n <= root_num)
		i++;
	i = i + beast_wars(tree->left, root_num, direction);
	i = i + beast_wars(tree->right, root_num, direction);
	return (i);
}

/**
 * rb_tree_balance - measures the balance conditions of a red black tree.
 *  Notes: hardest part of this project
 * @tree: pointer to the root node of the tree to traverse
 * @max_height: height of the tree, const
 * @local_height: local height for black node comparison 
 * Return: 1 if tree is null or balanced RBT, 0 for black node imba
 */
int rb_tree_balance(const rb_tree_t *tree, int max_height, int local_height)
{
	if (!tree)
	{
		if (local_height == max_height)
			return (1);
		return (0);
	}
	if (tree->color == BLACK)
		local_height++;
	return (rb_tree_balance(tree->left, max_height, local_height) &&
		rb_tree_balance(tree->right, max_height, local_height));
}

/**
 * rb_tree_height - measures the height of a red black tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: height of binary tree, or 0 if tree is null
 */
size_t rb_tree_height(const rb_tree_t *tree)
{
	size_t i = 0, lefti, righti;

	if (!tree || (tree->left == NULL && tree->right == NULL))
		return (0);
	lefti = rb_tree_height(tree->left);
	righti = rb_tree_height(tree->right);
	if (lefti >= righti)
		i = lefti;
	else
		i = righti;
	return (i + 1);
}
