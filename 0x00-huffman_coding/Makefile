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
huffman_tree: # target function: huffman_tree.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 8-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c binary_tree_print.c -o huffman_tree
test: # target function: huffman_tree.c -------- for edge case of same frequency all over
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 8-main-2.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c binary_tree_print.c -o test
huffman_codes: # target function: huffman_codes.c
	gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 9-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c huffman_codes.c binary_tree_print.c -o huffman_codes
.PHONY: heap_create binary_tree_node heap_insert heap_extract heap_delete symbol_create prio extract huffman_tree test
