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
	edge_t *curr_edge = NULL, *tar_edge = NULL;

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

	if ((curr_edge = new_edge(current)) == NULL)
		return (0);
	curr_edge->dest = target, curr_edge->next = NULL, current->nb_edges += 1;
	if (type == BIDIRECTIONAL)
	{
		if ((tar_edge = new_edge(target)) == NULL)
		{
			free(curr_edge), current->nb_edges -= 1;
			return (0);
		}
		tar_edge->dest = current, tar_edge->next = NULL, target->nb_edges += 1;
	}
	return (1);
}

/**
 * new_edge - function to return the newly allocated edge
 * @current: current vertex
 * Return: the newly allocated edge
 */
edge_t *new_edge(vertex_t *current)
{
	edge_t *curr_edge = NULL;

	if (current->edges == NULL)
	{
		curr_edge = current->edges;
		curr_edge = malloc(sizeof(edge_t));
		if (!curr_edge)
			return (NULL);
		return (curr_edge);
	}
	curr_edge = current->edges;
	while (curr_edge && curr_edge->next)
		curr_edge = curr_edge->next;
	curr_edge->next = malloc(sizeof(edge_t));
	if (curr_edge->next == NULL)
		return (NULL);
	return (curr_edge->next);
}
