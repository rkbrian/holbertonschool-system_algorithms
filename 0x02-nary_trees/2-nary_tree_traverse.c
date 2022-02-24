#include "nary_trees.h"

/**
 * nary_tree_traverse - function that goes through an N-ary tree, node by node.
 * @root: a pointer to the root node of the tree to traverse
 * @action: pointer to a function to execute for each node being traversed.
 * Return: the biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	static size_t tree_d;
	size_t memo;

	if (!root || !action)
		return (0);
	while (root)
	{
		action(root, tree_d);
		if (root->children)
			tree_d++, nary_tree_traverse(root->children, action);
		root = root->next;
	}
	tree_d--, memo = tree_d;
	return (memo);
}
