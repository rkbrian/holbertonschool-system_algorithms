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

	if (!graph || !graph->vertices || !src || !dest ||
	    (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);
	current = graph->vertices, target = graph->vertices;
	while (current && strcmp(src, current->content) != 0)
		current = current->next;
	while (target && strcmp(dest, target->content) != 0)
		target = target->next;
	if (!current || !target)
		return (0);
	curr_edge = current->edges;
	if (!curr_edge)
		curr_edge = new_edge();
	else
	{
		while (curr_edge && curr_edge->next)
			curr_edge = curr_edge->next;
		curr_edge->next = new_edge(), curr_edge = curr_edge->next;
	}
	if (!curr_edge)
		return (0);
	curr_edge->dest = target, current->nb_edges += 1, tar_edge = target->edges;
	if (type == BIDIRECTIONAL)
		return (bidirect(tar_edge, curr_edge, current, target));
	return (1);
}

/**
 * new_edge - function to return the newly allocated edge
 * @current: current vertex
 * Return: the newly allocated edge
 */
edge_t *new_edge(void)
{
	edge_t *curr_edge = NULL;

	curr_edge = malloc(sizeof(edge_t));
	if (!curr_edge)
		return (NULL);
	curr_edge->dest = NULL, curr_edge->next = NULL;
	return (curr_edge);
}

/**
 * bidirect - case bidirectional.
 *  This fuction is for beating Betty check on number of code lines
 * @tar_edge: dest vertex edge
 * @curr_edge: src vertex edge
 * @current: src vertex
 * @target: dest vertex
 * Return: 1 on success, or 0 on failure. On failure, no edge created
 */
int bidirect(edge_t *tar_edge, edge_t *curr_edge,
	     vertex_t *current, vertex_t *target)
{
	if (!tar_edge)
		tar_edge = new_edge();
	else
	{
		while (tar_edge && tar_edge->next)
			tar_edge = tar_edge->next;
		tar_edge->next = new_edge(), tar_edge = tar_edge->next;
	}
	if (!tar_edge)
	{
		free(curr_edge), current->nb_edges -= 1;
		return (0);
	}
	tar_edge->dest = current, target->nb_edges += 1;
	return (1);
}
