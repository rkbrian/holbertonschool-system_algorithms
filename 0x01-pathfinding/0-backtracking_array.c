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
	int map_row;
	queue_t *q;
	char **mazecpy;

	if (!map || !rows || !cols || !start || !target)
		return (NULL);
	q = queue_create();
	if (!q)
		return (NULL);
	mazecpy = malloc(sizeof(char *) * rows); /*init copy of maze*/
	if (!mazecpy)
	{
		free(q);
		return (NULL);
	}
	for (map_row = 0; map_row < rows; map_row++)
	{
		mazecpy[map_row] = strdup(map[map_row]);
		if (map_row < rows && mazecpy[map_row] == NULL)
		{
			while (map_row > 0)
				free(mazecpy[map_row]), map_row--;
			free(q);
			return (NULL);
		}
	}
	if (track_tree(mazecpy, q, rows, cols, start->y, start->x, target) == NULL)
                queue_delete(q), q = NULL;
        while (map_row > 0)
                free(mazecpy[map_row]), map_row--;
        free(mazecpy);
        if (q)
                free(q);
	return (q);
}

queue_t *track_tree(char **mazecpy, queue_t *q, int rows, int cols,
		int y, int x, point_t const *target)
{
	point_t *p;

	if (y >= 0 && x >= 0 && y < rows && x < cols && mazecpy[x][y] == 0)
	{
		mazecpy[y][x] = '1';
		printf("Checking coordinates [%d, %d]\n", x, y);
		if ((x == target->x && y == target->y) ||
                        track_tree(mazecpy, q, rows, cols, y, x + 1, target) ||
			track_tree(mazecpy, q, rows, cols, y + 1, x, target) ||
			track_tree(mazecpy, q, rows, cols, y, x - 1, target) ||
			track_tree(mazecpy, q, rows, cols, y - 1, x, target))
		{
			p = malloc(sizeof(point_t));
			if (!p)
			{
				queue_delete(q);
				return (NULL);
			}
			p->x = x, p->y = y;
			queue_push_front(q, p);
			return (q);
		}
	}
	return (NULL);
}
