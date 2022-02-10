#ifndef HEAP_H
#define HEAP_H

#define MAX_Q_SIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

/**
 * enum directing - enumerate child node directions
 * @left_d: enumerate of left child
 * @right_d: enumerate of right child
 */
enum directing
{
	left_d,
	right_d
};

/**
 * struct queue_s - struct of
 * @head: head position index
 * @tail: tail position index
 * @queue_arr: array of tree nodes
 */
typedef struct queue_s
{
	int head; /* position */
	int tail; /* position */
	binary_tree_node_t *queue_arr[MAX_Q_SIZE]; /* array of tree nodes */
} queue_q;

/*binary tree print*/
void binary_tree_print(const binary_tree_node_t *root,
	int (*print_data)(char *, void *));
/*major functions*/
heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);

/*helper functions*/
void imba(binary_tree_node_t *node, int height, int left_h);
binary_tree_node_t *imba_node(binary_tree_node_t *node);
int queue_store(queue_q *queen, const binary_tree_node_t *node);
binary_tree_node_t *queue_remove(queue_q *queen,
				const binary_tree_node_t *node);


#endif /*HEAP_H*/
