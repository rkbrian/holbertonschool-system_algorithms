#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "queues.h"
#include "graphs.h"

/**
 * struct point_s - Structure storing coordinates
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

/**
 * enum directing - directions, set up for possible future use
 * @RIGHT: right
 * @BOTTOM: bottom
 * @LEFT: left
 * @TOP: top
 */
enum directing
{
	RIGHT,
	BOTTOM,
	LEFT,
	TOP
};

/**
 * struct dijkstra_node - saves the distance from start to the included node
 * @dis_to_start: distances
 * @visit_flag: flag indicates whether the node was visited or not
 * @node: current node
 */
typedef struct dijkstra_node
{
	int dis_to_start;
	int visit_flag;
	vertex_t *node;
} dij_t;

/**
 * struct dijkstra_edge - saves the visited edges from
 *  being counted indefinitely
 * @flag: flag of visited edge
 * @ed: edge node
 */
typedef struct dijkstra_edge
{
	int flag;
	edge_t *ed;
} dij_edge_t;

/*major functions*/
queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);
/*helper functions*/
/*0*/
queue_t *track_tree(char **mazecpy, queue_t *q, int rows, int cols,
		int y, int x, point_t const *target);
queue_t *store_curr(int x, int y, queue_t *q);
/*1*/
queue_t *track_node(vertex_t const *v, vertex_t const *target,
		size_t *visited);
queue_t *store_str(queue_t *q, char *str);
/*2*/
void short_paths(dij_t **arr, vertex_t **route, size_t sizy,
		vertex_t const *start, vertex_t const *target);
queue_t *dijkstra_queue_store(vertex_t **route, size_t sizy,
				vertex_t const *start, vertex_t const *target);
dij_t *min_dis(dij_t **arr, size_t sizy);

#endif /*PATHFINDING_H*/
