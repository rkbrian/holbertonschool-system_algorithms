#include "graphs.h"

/**
 * depth_first_traverse - function that goes through a graph using
 *  the depth-first algorithm. The traversal must start from the 1st vertex.
 * @graph: a pointer to the graph to traverse.
 * @action: a pointer to a function to be called for each visited vertex
 * @v: a const pointer to the visited vertex
 * @depth: the depth of v, from the starting vertex
 * Return: the biggest vertex depth, or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	size_t ret_depth, *arr = malloc(sizeof(*arr) * graph->nb_vertices);

	if (!graph || graph->nb_vertices == 0 || !arr)
		return (0);
	memset(arr, 1, graph->nb_vertices * sizeof(size_t)); /*list of unvisited*/
	ret_depth = dfs_recursion(graph->vertices, 0, arr, action);
	free(arr);
	return (ret_depth);
}

/**
 * dfs_recursion - Depth First Search function to traverse vertices linked by
 *  edges, recursive.
 * @vv: a const pointer to the visited vertex
 * @dd: the depth of vv, from the starting vertex
 * @arr: index array of unvisited, index marked 1 for unvisited vertex index
 * @action: a pointer to a function to be called for each visited vertex
 * @v: a const pointer to the visited vertex
 * @depth: the depth of v, from the starting vertex
 * Return: the maximum depth found
 */
size_t dfs_recursion(const vertex_t *vv, size_t dd, size_t *arr,
		void (*action)(const vertex_t *v, size_t depth))
{
	size_t tmp_depth, curr_depth = 0;
	edge_t *curr_edge = vv->edges;

	if (arr[vv->index] == 0)
		return (dd - 1);
	action(vv, dd);
	arr[vv->index] = 0;
	while (curr_edge)
	{
		tmp_depth = dfs_recursion(curr_edge->dest, dd + 1, arr, action);
		if (tmp_depth > curr_depth)
			curr_depth = tmp_depth;
	}
	return (curr_depth);
}
