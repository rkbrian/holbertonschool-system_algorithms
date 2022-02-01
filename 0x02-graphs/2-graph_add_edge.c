#include "graphs.h"

/**
 * graph_add_edge - adds an edge between two vertices to an existing graph
 * @graph: a pointer to the graph to add the edge to
 * @src: the string identifying the vertex to make the connection from
 * @dest: the string identifying the vertex to connect to
 * @type: the type of edge
 * Return: 1 on success, or 0 on failure. On failure, no edge created
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
		   edge_type_t type)
{
	vertex_t *current = NULL, *target = NULL;

	if (!graph || !graph->vertices || !src || !dest)
		return (0);
	if (type != UNIDIRECTIONAL && type != BIDIRECTIONAL)
		return (0);
	current = graph->vertices, target = graph->vertices;
	while (current && strcmp(src, current->content) != 0)
		current = current->next;
	while (target && strcmp(dest, target->content) != 0)
		target = target->next;
	if (!current || !target)
		return (0);
	current->edges = malloc(sizeof(edge_t));
	if (current->edges = NULL)
		return (0);
	current->edges->dest = target, current->edges->next = NULL;
	current->nb_edges += 1;
	if (type == BIDIRECTIONAL)
	{
		target->edges = malloc(sizeof(edge_t));
		if (target->edges == NULL)
		{
			free(current->edges), current->nb_edges -= 1;
			return (0);
		}
		target->edges->dest = current, target->edges->next = NULL;
		target->nb_edges += 1;
	}
	return (1);
}
