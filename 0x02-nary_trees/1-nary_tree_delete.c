#include "nary_trees.h"

/**
 * nary_tree_delete - function that deallocates an entire N-ary tree
 * @tree: N-ary tree to be deleted
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *curr = NULL, *curr_child = NULL, *tmp = NULL;

	if (!tree)
		return;
	curr = tree;
	while (curr)
	{
		curr_child = curr->children;
		tmp = curr, curr = curr->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		if (curr_child)
			nary_tree_delete(curr_child);
	}
	
}
