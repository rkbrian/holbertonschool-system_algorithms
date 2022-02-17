#include "pathfinding.h"

/**
 * backtracking_array - a function that searches for the first path from a
 *  starting point to a target point within a two-dimensional array.
 * Notes: required to use recursive backtracking to find the 1st working path
 *  from start to target
 * @map: the pointer to a read-only 2d array, 0 represents a walkable cell,
 *  1 represents a blocked cell
 * @rows: the number of rows of map
 * @cols: the number of columns of map
 * @start: stores the coordinates of the starting point
 * @target: stores the coordinates of the target point
 * Return: a queue, in which each node is a point in the path
 *  from start to target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
        point_t const *start, point_t const *target)
{
        ;
}
