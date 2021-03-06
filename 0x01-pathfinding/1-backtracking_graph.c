#include "pathfinding.h"
#include "queues.h"

/**
 * backtracking_graph - function that searches for the first path
 *  from a starting point to a target point in a graph.
 * @graph: pointer to the graph to go through
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: a queue, in which each node is a string corresponding
 *  to a vertex, forming a path from start to target
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *ret_ptr = NULL;
	size_t *visited;

	if (!graph || !start || !target)
		return (NULL);
	visited = malloc(sizeof(size_t) * graph->nb_vertices);
	if (!visited)
		return (NULL);
	memset(visited, 0, sizeof(size_t) * graph->nb_vertices);
	ret_ptr = track_node(start, target, visited), free(visited);
	if (!ret_ptr) /*track_nodesive function that return visited queue*/
		return (NULL);
	ret_ptr = store_str(ret_ptr, start->content);
	return (ret_ptr);
}

/**
 * track_node - backtracking recursive function for graph nodes
 * @v: pointer to the current vertex
 * @target: pointer to the target vertex
 * @visited: array of integers to address visited nodes
 * Return: queue
 */
queue_t *track_node(vertex_t const *v, vertex_t const *target,
		size_t *visited)
{
	queue_t *q = NULL;
	edge_t *edgie = NULL;

	if (!target || !v || !visited || visited[v->index])
		return (NULL);
	printf("Checking %s\n", v->content);
	visited[v->index] = 1;
	if (v == target)
		return (queue_create());
	edgie = v->edges;
	while (edgie)
	{
		q = track_node(edgie->dest, target, visited);
		if (q)
			return (store_str(q, edgie->dest->content));
		edgie = edgie->next;
	}
	return (NULL);
}

/**
 * store_str - function to store current walkable path
 * @q: current queue
 * @str: name of current path
 * Return: queue with added path, or NULL if allocation failed
 */
queue_t *store_str(queue_t *q, char *str)
{
	char *new_str;

	new_str = strdup(str);
	if (!new_str)
	{
		queue_delete(q);
		return (NULL);
	}
	queue_push_front(q, (void *)new_str); /*store current walkable path*/
	return (q);
}
