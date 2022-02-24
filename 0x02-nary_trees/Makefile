# memo
0-nary_tree_insert: # run: ./0-nary_tree_insert ; echo $?
	gcc -Wall -Wextra -Werror -pedantic -o 0-nary_tree_insert 0-nary_tree_insert.c 0-main.c
1-nary_tree_delete: # valgrind to test if these's mem leak
	gcc -Wall -Wextra -Werror -pedantic -o 1-nary_tree_delete 1-nary_tree_delete.c 0-nary_tree_insert.c 1-main.c
2-nary_tree_traverse:
	gcc -Wall -Wextra -Werror -pedantic -o 2-nary_tree_traverse 2-nary_tree_traverse.c 1-nary_tree_delete.c 0-nary_tree_insert.c 2-main.c
3-nary_tree_diameter:
	gcc -Wall -Wextra -Werror -pedantic -o 3-nary_tree_diameter 3-nary_tree_diameter.c 1-nary_tree_delete.c 0-nary_tree_insert.c 3-main.c
4-path_exists:
	gcc -Wall -Wextra -Werror -pedantic -o 4-path_exists 4-path_exists.c 1-nary_tree_delete.c 0-nary_tree_insert.c 4-main.c
.PHONY: 0-nary_tree_insert 1-nary_tree_delete 2-nary_tree_traverse
