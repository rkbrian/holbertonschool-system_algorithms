#include "nary_trees.h"

/**
 * path_exists - function that checks if a path exists in an N-ary tree.
 * @root: a pointer to the root node of the tree
 * @path: a NULL terminated array of strings. The string at the index i
 *  can be the content of one of the nodes of the tree at the depth i.
 * Return: 1 if all the elements of path are present in the tree and if
 *  for an element of path at the index i is present in one of the nodes at
 *  the depth i. And of course, all the nodes must be linked to form a path
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	size_t path_size = 0, tree_d = 0;

	if (!root || !path) /*tree or path is empty*/
		return (0);
	while (path[path_size] != NULL)
		path_size++;
	while (root && tree_d < path_size)
	{
		if (strcmp(path[tree_d], root->content) == 0)
			root = root->children, tree_d++; /*path found, search in next catagory*/
		else
			root = root->next;
	}
	if (tree_d == path_size)
		return (1);
	return (0);
}
