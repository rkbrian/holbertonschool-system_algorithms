#include "nary_trees.h"

/**
 * nary_tree_diameter - function that computes the diameter of an N-ary tree
 * @root: root node of the tree to compute the diameter of.
 * Return: the diameter of the tree pointed to by root.
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t max_diameter;

	if (!root || root->children == NULL)
		return (0);
	nary_tree_height(root);
	max_diameter = max_dia_store(0, 1);
	return (max_diameter);
}

/**
 * nary_tree_height - measures the height of a N-ary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: height of N-ary tree, or 0 if tree is null
 */
size_t nary_tree_height(nary_tree_t const *tree)
{
	size_t first_max_br = 0, second_max_br = 0, new_height;
	nary_tree_t *curr = NULL;

	if (!tree)
		return (0);
	curr = tree->children;
	while (curr)
	{
		new_height = nary_tree_height(curr);
		if (new_height > first_max_br)
			second_max_br = first_max_br, first_max_br = new_height;
		else if (new_height > second_max_br)
			second_max_br = new_height;
		curr = curr->next;
	}
	max_dia_store(first_max_br + second_max_br + 1, 0);
	return (first_max_br + 1);
}

/**
 * max_dia_store - function to store and retrieve the
 *  maximum diameter of a N-ary tree
 * @new_val: value to be compared and stored
 * @clear_memo: flag, 1 for clearing static data memory, 0 for doing nothing
 * Return: maximum diameter stored
 */
size_t max_dia_store(size_t new_val, int clear_memo)
{
	static size_t memo;
	size_t max_dia;

	if (new_val > memo)
		memo = new_val;
	max_dia = memo;
	if (clear_memo == 1)
		memo = 0;
	return (max_dia);
}