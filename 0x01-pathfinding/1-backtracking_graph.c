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
	int map_row;
	queue_t *q, *ret_ptr = NULL;
	graph_t *graph_cpy;

	if (!graph || !start || !target)
		return (NULL);
	q = queue_create();
	if (!q)
		return (NULL);
	ret_ptr = track_node(q, start, target);
	if (!ret_ptr) /*track_nodesive function that return visited queue*/
		queue_delete(q), q = NULL;
	return (q);
}

/**
 * track_node - backtracking recursive function for graph nodes
 * @q: a queue
 * @v: pointer to the current vertex
 * @target: pointer to the target vertex
 * Return: queue
 */
queue_t *track_node(queue_t *q, vertex_t *v, vertex_t *target)
{
	queue_t *q;
	vertex_t *next_node = NULL;

	if (!q || !v || v->x == 1)
		return (NULL);
	printf("Checking %s\n", v->content);
	v->x = 1;
	if (v == target)
		return (store_str(q, v->content));
	next_node = v->edges->dest;
	while (next_node && next_node->x == 1)
		next_node = next_node->next;
	if (next_node && track_node(q, next_node, target))
		return (store_str(q, next_node->content));
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
