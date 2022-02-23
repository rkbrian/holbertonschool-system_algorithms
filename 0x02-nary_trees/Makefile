# memo
0-nary_tree_insert: # run: ./0-nary_tree_insert ; echo $?
	gcc -Wall -Wextra -Werror -pedantic -o 0-nary_tree_insert 0-nary_tree_insert.c 0-main.c
1-nary_tree_delete: # valgrind to test if these's mem leak
	gcc -Wall -Wextra -Werror -pedantic -o 1-nary_tree_delete 1-nary_tree_delete.c 0-nary_tree_insert.c 1-main.c
.PHONY: 0-nary_tree_insert
