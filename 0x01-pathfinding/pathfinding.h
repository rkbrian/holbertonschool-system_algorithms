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
/*helper functions*/
queue_t *track_tree(char **mazecpy, queue_t *q, int rows, int cols,
		int y, int x, point_t const *target);

#endif /*PATHFINDING_H*/
