#include "graphs.h"

/**
 * depth_first_traverse - function that goes through a graph using
 *  the depth-first algorithm. The traversal must start from the 1st vertex.
 * @graph: a pointer to the graph to traverse.
 * @action: a pointer to a function to be called for each visited vertex
 * Return: the biggest vertex depth, or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	size_t ret_depth = 0, *arr;

	if (!graph || !action || graph->nb_vertices == 0)
		return (0);
	arr = malloc(sizeof(*arr) * graph->nb_vertices);
	if (arr)
		free(arr);
	memset(arr, 1, graph->nb_vertices * sizeof(size_t)); /*list of unvisited*/
	dfs_recursion(graph->vertices, 0, arr, action);
	ret_depth = max_depth(0);
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
 */
void dfs_recursion(const vertex_t *vv, size_t dd, size_t *arr,
		   void (*action)(const vertex_t *v, size_t depth))
{
	edge_t *curr_edge;

	if (!vv || arr[vv->index] == 0)
		return; /*recursion advance: search for next node in stack*/
	curr_edge = vv->edges;
	action(vv, dd);
	arr[vv->index] = 0;
	max_depth(dd), dd++;
	while (curr_edge)
	{
		dfs_recursion(curr_edge->dest, dd, arr, action);
		curr_edge = curr_edge->next;
	}
}

/**
 * max_depth - function to store and return max depth
 * @dd: local depth to be tested
 * Return: max depth
 */
size_t max_depth(size_t dd)
{
	static size_t ret_d;

	if (dd > ret_d)
		ret_d = dd;
	return (ret_d);
}
