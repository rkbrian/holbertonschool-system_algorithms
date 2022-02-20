#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        point_t *point = (point_t *)dequeue(path);
        printf(" [%d, %d]\n", point->x, point->y);
        free(point);
    }
    free(path);
}

/**
 * main - Backtracking using an array. Here the array is chosen to demonstrate
 * that Backtracking is a really bad algorithm. The target point is just
 * down-right from the starting point, but since we first check the right cell,
 * then top, then left, then bottom, our algo will almost go through the whole
 * maze before finding a path.
 * Don't use backtracking. Backtracking is bad.
 */
int main(void)
{
    char *map[21] = {
        "111111111111111111111", /*"111111111111111111111",*/
        "101000000000001000001", /*"1 1           1     1",*/
        "101011111111101110101", /*"1 1 111111111 111 1 1",*/
        "100010000010001000101", /*"1   1     1   1   1 1",*/
        "111111111010111011101", /*"111111111 1 111 111 1",*/
        "101000000010100010001", /*"1 1       1 1   1   1",*/
        "101011111010111011111", /*"1 1 11111 1 111 11111",*/
        "101000001010001000001", /*"1 1     1 1   1     1",*/
        "101110111011101111101", /*"1 111 111 111 11111 1",*/
        "101000001000100000101", /*"1 1     1   1     1 1",*/
        "101011111110111110101", /*"1 1 1111111 11111 1 1",*/
        "101000000010000010001", /*"1 1       1     1   1",*/
        "101111101111101111101", /*"1 11111 11111 11111 1",*/
        "000000001000001000001", /*"        1     1     1",*/
        "111011111010101011111", /*"111 11111 1 1 1 11111",*/
        "100010100010101000001", /*"1   1 1   1 1 1     1",*/
        "101110101111111110111", /*"1 111 1 111111111 111",*/
        "100000101000000000001", /*"1     1 1           1",*/
        "101111101011111111101", /*"1 11111 1 111111111 1",*/
        "100000100000000010001", /*"1     1         1   1",*/
        "111110111111111111111"  /*"11111 111111111111111"*/
    };
    point_t start = { 0, 13 };
    point_t target = { 5, 20 };
    queue_t *path;

    path = backtracking_array((char **)map, 21, 21, &start, &target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);

    return (EXIT_SUCCESS);
}
