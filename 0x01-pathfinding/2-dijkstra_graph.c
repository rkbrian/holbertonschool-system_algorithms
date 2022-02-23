#include "pathfinding.h"

/**
 * dijkstra_graph - function that searches for the shortest path from
 *  a starting point to a target point in a graph.
 * @graph: pointer to the graph to go through
 * @start: a pointer to the starting vertex
 * @target: is a pointer to the target vertex
 * Return: a queue, in which each node is a string corresponding to
 *  a vertex, forming a path from start to target
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	queue_t *q;
	dij_t **arr;
	size_t i, sizy;
	vertex_t **route, *curr_v = NULL;

	if (!graph || !start || !target)
		return (NULL);
	sizy = graph->nb_vertices, arr = malloc(sizeof(dij_t) * sizy);
	if (!arr)
		return (NULL);
	route = malloc(sizeof(vertex_t) * sizy);
	if (!route)
	{
		free(arr);
		return (NULL);
	}
	i = 0, curr_v = graph->vertices;
	while (i < sizy)
	{
		arr[i]->dis_to_start = INT_MAX, arr[i]->visit_flag = 0;
		arr[i]->node = NULL, arr[i]->node = curr_v; /*init array of node stats*/
		i++, curr_v = curr_v->next;
	}
	arr[0]->dis_to_start = 0, arr[0]->visit_flag = 0;
	short_paths(arr, route, sizy, start, target), free(arr);
	q = dijkstra_queue_store(route, sizy, start, target), free(route);
	if (!q || q->front == NULL)
	{
		queue_delete(q);
		return (NULL);
	}
	return (q);
}

/**
 * short_paths - recursive function to find the path with dijkstra method
 * @arr: array to store and update node stats
 * @route: array of nodes in traverse order
 * @sizy: size of array above
 * @start: a pointer to the starting vertex
 * @target: is a pointer to the target vertex
 */
void short_paths(dij_t **arr, vertex_t **route, size_t sizy,
		vertex_t const *start, vertex_t const *target)
{
	edge_t *edgey = NULL;
	int next_d;
	dij_t *curr = NULL;

	if (!target || !start || !arr || !sizy || !route)
		return;
	curr = min_dis(arr, sizy);
	if (!curr)
		return;
	printf("Checking %s, distance from %s is %d\n",
		curr->node->content, start->content, curr->dis_to_start);
	edgey = curr->node->edges;
	while (edgey && curr->visit_flag == 0)
	{
		next_d = edgey->weight + curr->dis_to_start;
		if (arr[edgey->dest->index]->dis_to_start > next_d) /*update the shortest d*/
		{
			arr[edgey->dest->index]->dis_to_start = next_d;
			route[edgey->dest->index] = curr->node; /*rewrite neighbors to be visited*/
		}
		edgey = edgey->next;
	}
	curr->visit_flag = 1;
	if (arr[target->index]->visit_flag == 1) /*target reached*/
		return;
	short_paths(arr, route, sizy, start, target);
}

/**
 * store_str - function to store current walkable path
 * @route: array of nodes in traverse order
 * @sizy: size of array above
 * @start: a pointer to the starting vertex
 * @target: is a pointer to the target vertex
 * Return: queue with added path, or NULL if allocation failed
 */
queue_t *dijkstra_queue_store(vertex_t **route, size_t sizy,
				vertex_t const *start, vertex_t const *target)
{
	queue_t *q;
	char *new_str;
	size_t i;

	i = target->index;
	if (!route[i]) /*target is not connected to the short route*/
		return (NULL);
	q = queue_create(), new_str = strdup(target->content);
	if (!new_str)
	{
		queue_delete(q);
		return (NULL);
	}
	queue_push_front(q, new_str);
	while (route[i] && i < sizy)
	{
		new_str = strdup(route[i]->content);
		if (!new_str)
		{
			queue_delete(q);
			return (NULL);
		}
		queue_push_front(q, (void *)new_str); /*store current walkable path*/
		i = route[i]->index;
		if (i == start->index)
			return (q);
	}
	return (q);
}

/**
 * min_dis - return stats of the node that's globally closest to the start
 * @arr: array of nodes and stats
 * @sizy: size of array (node amount)
 * Return: stats of the closest node
 */
dij_t *min_dis(dij_t **arr, size_t sizy)
{
	size_t i, closest_d_i = INT_MAX;
	int min_val = INT_MAX;

	for (i = 0; i < sizy; i++)
	{
		if (arr[i]->visit_flag == 0 && min_val > arr[i]->dis_to_start)
			min_val = arr[i]->dis_to_start, closest_d_i = i;
	}
	if (closest_d_i == INT_MAX)
		return (NULL);
	return (arr[closest_d_i]);
}
