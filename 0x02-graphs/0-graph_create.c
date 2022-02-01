#include "graphs.h"

/**
 * graph_create - function that allocates memory to store a graph_t structure,
 *  and initializes its content.
 * Return: new graph structure
 */
graph_t *graph_create(void)
{
	graph_t *new_g = malloc(sizeof(graph_t));

	if (!new_g)
		return (NULL);
	/**/
	new_g->vertices = malloc(sizeof(vertex_t));
	if (new_g->vertices == NULL)
	{
		free(new_g);
		return (NULL);
	}
	new_g->vertices->edges = malloc(sizeof(edge_t));
	if (new_g->vertices->edges == NULL)
	{
		free(new_g->vertices);
		free(new_g);
		return (NULL);
	}
	new_g->vertices->content = NULL;
	new_g->vertices->nb_edges = 0;
	new_g->vertices->index = 0;
	new_g->vertices->edges->dest = NULL, new_g->vertices->edges->next = NULL;
	new_g->vertices->next = NULL;
	new_g->nb_vertices = 1;
	/**/
	new_g->nb_vertices = 0;
	return (new_g);
}
