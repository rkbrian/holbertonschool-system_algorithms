#include "graphs.h"

/**
 * graph_add_vertex - function that adds a vertex to an existing graph
 * @graph: pointer to the graph to add the vertex to
 * @str: the string to store in the new vertex
 * Return: a pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *current = NULL, *tmp;
	size_t i;

	if (!str)
		return (NULL);
	if (!graph)
	{
		graph = malloc(sizeof(graph_t));
		if (!graph)
			return (NULL);
		graph->nb_vertices = 0;
	}
	current = graph->vertices, i = 0;
	while (current && current->next)
		current = current->next, i++;
	tmp = malloc(sizeof(vertex_t));
	if (!tmp)
	{
		free_graph(graph);
		return (NULL);
	}
	/*tmp->edges = malloc(sizeof(edge_t));
	if (tmp->edges == NULL)
	{
		free(tmp), free_graph(graph);
		return (NULL);
	}*/
	tmp->content = strdup(str);
	if (tmp->content == NULL)
	{
		/*free(tmp->edges), */free(tmp), free_graph(graph);
		return (NULL);
	}
	tmp->nb_edges = 0, tmp->index = i, tmp->next = NULL;
	/*tmp->edges->dest = NULL, tmp->edges->next = NULL;*/
	current->next = tmp, graph->nb_vertices += 1;
	return (tmp);
}

/**
 * free_graph - function to free the entire graph
 * @graph: graph structure to be freed
 */
void free_graph(graph_t *graph)
{
	vertex_t *current = NULL, *tmp = NULL;

	current = graph->vertices;
	while (current)
	{
		tmp = current->next;
		if (current->content)
			free(current->content);
		if (current->edges)
			free(current->edges);
		free(current), current = tmp;
	}
	free(graph);
}
