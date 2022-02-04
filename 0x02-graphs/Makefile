# I'm lazy to do alias and simplification here
0-graph_create:
	gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-graph_create.c -o 0-graph_create
1-graph_add_vertex:
	gcc -Wall -Wextra -Werror -pedantic -g3 1-main.c 0-graph_create.c 1-graph_add_vertex.c graph_display.c -o 1-graph_add_vertex
2-graph_add_edge:
	gcc -Wall -Wextra -Werror -pedantic -g3 2-main.c 0-graph_create.c 1-graph_add_vertex.c 2-graph_add_edge.c graph_display.c -o 2-graph_add_edge
# valgrind ./3-graph_delete
3-graph_delete:
	gcc -Wall -Wextra -Werror -pedantic -g3 3-main.c 0-graph_create.c 1-graph_add_vertex.c 2-graph_add_edge.c 3-graph_delete.c graph_display.c -o 3-graph_delete
4-depth_first_traverse:
	gcc -Wall -Wextra -Werror -pedantic -g3 4-main.c 0-graph_create.c 1-graph_add_vertex.c 2-graph_add_edge.c 3-graph_delete.c 4-depth_first_traverse.c graph_display.c -o 4-depth_first_traverse
5-breadth_first_traverse:
	gcc -Wall -Wextra -Werror -pedantic -g3 5-main.c 0-graph_create.c 1-graph_add_vertex.c 2-graph_add_edge.c 3-graph_delete.c 5-breadth_first_traverse.c graph_display.c -o 5-breadth_first_traverse
