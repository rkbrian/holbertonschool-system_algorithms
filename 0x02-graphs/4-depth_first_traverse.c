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
	size_t arr[MAX_BUFF], ret_depth;
	;

	if (!graph || action == NULL)
		return (0);
	memset(arr, 1, graph->nb_vertices * sizeof(size_t));
	dfs_recursion(0, arr, graph, action);
	ret_depth = max_depth(0);
	return (ret_depth);
}

void dfs_recursion(size_t i, size_t *arr, const graph_t *graph,
		void (*action)(const vertex_t *v, size_t depth))
{
        size_t v_index = 0, edge_i = 0;
	vertex_t *current = NULL;
        edge_t *curr_edge = NULL;

	current = graph->vertices, curr_edge = current->edges;
	while (arr[current->index] == 0)
	{
		if (!curr_edge) /*island, not valid for traverse*/
			break; /*current = current->next, curr_edge = current->edges, v_index++;*/
		else if (arr[curr_edge->dest->index] == 1) /*unvisited neighbor, stay*/
			current = curr_edge->dest, v_index++, curr_edge = current->edges;
		else if (curr_edge->next) /*visited neighbor, find next neighbor*/
			curr_edge = curr_edge->next, current = curr_edge->dest;
		else if (curr_edge->next == NULL)
			break;
	}
	action(current, v_index), v_index = max_depth(v_index);
	arr[i] = 0;
	dfs_recursion(v_index, arr, graph, action);
}


size_t max_depth(size_t new_depth)
{
	static size_t depth = 0;

	if (new_depth > depth)
		depth = new_depth;
	return (depth);
}

/**
 * buffalo - creates buffer array to store all the vertex index
 * @graph: a pointer to the graph to traverse.
 * Return: the buffer array
 */
size_t *buffalo(const graph_t *graph)
{
	size_t i = 0, arr[MAX_BUFF];
	vertex_t *current = NULL;

	memset(arr, 0, graph->nb_vertices * sizeof(size_t));
	current = graph->vertices;
	while (current)
		arr[i] = current->index, i++, current = current->next;
	return (arr);
}
