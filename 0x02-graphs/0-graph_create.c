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
	new_g->vertices = NULL;
	new_g->nb_vertices = 0;
	return (new_g);
}
