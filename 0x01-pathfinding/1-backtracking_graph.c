#include "pathfinding.h"
#include "queues.h"


queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	int map_row;
	queue_t *q;

        if (!graph || !start || !target)
	q = queue_create();
	if (!q)
		return (NULL);
        ;
}

queue_t *recur()
{
        ;
}
