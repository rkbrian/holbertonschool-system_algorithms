#include "graphs.h"

/**
 * graph_delete - function that completely deletes a graph
 * @graph: a pointer to the graph to be deleted
 */
void graph_delete(graph_t *graph)
{
	vertex_t *current = NULL, *tmp = NULL;
	edge_t *curr_edge = NULL, *edge_tmp = NULL;

	if (graph)
	{
		current = graph->vertices;
		while (current)
		{
			tmp = current->next, curr_edge = current->edges;
			if (current->content)
				free(current->content);
			while (curr_edge)
				edge_tmp = curr_edge->next, free(curr_edge), curr_edge = edge_tmp;
			free(current), current = tmp;
		}
		free(graph);
	}
}
