# Memo
# Theoretically every compilation here needs to free allocation,
# but the most given test files didn't include the freeing.
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
PTREE = rb_tree_print.c
NNODE = 0-rb_tree_node.c

rb_tree_node:	$(PTREE) $(NNODE) 0-main.c
	$(CC) $(CFLAGS) $^ -o $@
rb_tree_valid:	$(PTREE) $(NNODE) 1-main.c 1-rb_tree_is_valid.c
	$(CC) $(CFLAGS) $^ -o $@
