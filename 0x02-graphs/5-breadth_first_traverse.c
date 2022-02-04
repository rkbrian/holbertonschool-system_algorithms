#include "graphs.h"

/**
 * breadth_first_traverse - function that goes through a graph using
 *  the breach-first algorithm. The traversal must start from the 1st vertex.
 * @graph: a pointer to the graph to traverse.
 * @action: a pointer to a function to be called for each visited vertex
 * Return: the biggest vertex depth, or 0 on failure
 */
size_t breadth_first_traverse(const graph_t *graph,
			      void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t **buffalo;
	size_t ret_depth = 0, *arr, i = 0, depth_pack = 0;
	size_t store_i = 1, pack_squeeze = 1; /*1st pack has head vertex only*/
	edge_t *curr_edge = NULL;

	if (!graph || !action || graph->nb_vertices == 0)
		return (0);
	arr = malloc(sizeof(arr) * graph->nb_vertices);
	if (!arr)
		return (0);
	buffalo = malloc(sizeof(vertex_t *) * (graph->nb_vertices + 1));
	if (!buffalo)
	{
		free(arr);
		return (0);
	}
	memset(arr, 1, graph->nb_vertices * sizeof(size_t)); /*list of unvisited*/
	buffalo[0] = graph->vertices, arr[0] = 0;
	while (buffalo[i])
	{
		action(buffalo[i], ret_depth), curr_edge = buffalo[i]->edges;
		while (curr_edge)
		{
			if (arr[curr_edge->dest->index])
			{
				buffalo[store_i] = curr_edge->dest, store_i++;
				arr[curr_edge->dest->index] = 0, depth_pack++;
			}
			curr_edge = curr_edge->next;
		}
		pack_squeeze--, i++;
		if (!pack_squeeze)
			ret_depth++, pack_squeeze = depth_pack, depth_pack = 0;
	}
	free(arr), free(buffalo), ret_depth--;
	return (ret_depth);
}
