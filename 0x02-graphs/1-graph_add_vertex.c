#include "graphs.h"

/**
 * graph_add_vertex - function that adds a vertex to an existing graph
 * @graph: pointer to the graph to add the vertex to
 * @str: the string to store in the new vertex
 * Return: a pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *current, *tmp;

	if (!graph)
	{
		graph = malloc(sizeof(graph_t));
		if (!graph)
			return (NULL);
	}
	if (!str)
		return (NULL);
	if (graph->vertices == NULL)
		return (head_start(graph, str));
	current = graph->vertices;
	if (current && strcmp(str, current->content) == 0)
		return (NULL);
	while (current && current->next)
	{
		if (strcmp(str, current->content) == 0)
			return (NULL);
		current = current->next;
	}
	tmp = malloc(sizeof(vertex_t));
	if (tmp == NULL)
	{
		free_graph(graph);
		return (NULL);
	}
	if (str == NULL)
		tmp->content = NULL;
	else
	{
		tmp->content = strdup(str);
		if (tmp->content == NULL)
		{
			free(tmp), free_graph(graph);
			return (NULL);
		}
	}
	tmp->edges = NULL, tmp->nb_edges = 0, tmp->index = graph->nb_vertices;
	tmp->next = NULL, current->next = tmp, graph->nb_vertices += 1;
	return (current);
}

/**
 * free_graph - function to free the entire graph
 * @graph: graph structure to be freed
 */
void free_graph(graph_t *graph)
{
	vertex_t *current = NULL, *tmp = NULL;
	edge_t *curr_edge = NULL, *edge_tmp = NULL;

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

/**
 * head_start - function to make head vertex
 * @graph: pointer to the graph to add the vertex to
 * @str: the string to store in the new vertex
 * Return: a pointer to the created vertex, or NULL on failure
 */
vertex_t *head_start(graph_t *graph, const char *str)
{
	if (!str)
		return (NULL);
	graph->vertices = malloc(sizeof(vertex_t));
	if (graph->vertices == NULL)
	{
		free(graph);
		return (NULL);
	}
	graph->vertices->content = strdup(str);
	if (graph->vertices->content == NULL)
	{
		free(graph->vertices), free(graph);
		return (NULL);
	}
	graph->vertices->edges = NULL, graph->vertices->index = 0;
	graph->vertices->nb_edges = 0, graph->vertices->next = NULL;
	graph->nb_vertices = 1;
	return (graph->vertices);
}

