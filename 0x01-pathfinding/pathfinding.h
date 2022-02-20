#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

/*major functions*/
queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target);
/*helper functions*/
/*0*/
queue_t *track_tree(char **mazecpy, queue_t *q, int rows, int cols,
		int y, int x, point_t const *target);
queue_t *store_curr(int x, int y, queue_t *q);
/*1*/
queue_t *track_node(queue_t *q, vertex_t *v, vertex_t *target);
queue_t *store_str(queue_t *q, char *str);

#endif /*PATHFINDING_H*/
