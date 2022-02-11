# memo
heap_create: # target function: heap/heap_create.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 0-main.c -o heap_create
binary_tree_node: # target function: heap/binary_tree_node.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 1-main.c -o binary_tree_node
heap_insert: # target function: heap/heap_insert.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 2-main.c binary_tree_print.c -o heap_insert
heap_extract: # target function: heap/heap_extract.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 3-main.c binary_tree_print.c -o heap_extract
heap_delete: # target function: heap/heap_delete.c, run with valgrind
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 4-main.c binary_tree_print.c -o heap_delete
symbol_create: # target function: symbol.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 5-main.c symbol.c -o symbol_create
prio: # target function: huffman_priority_queue.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 6-main.c symbol.c huffman_priority_queue.c binary_tree_print.c -o prio
extract: # target function: huffman_extract_and_insert.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 7-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c binary_tree_print.c -o extract
.PHONY: heap_create binary_tree_node heap_insert heap_extract heap_delete symbol_create
