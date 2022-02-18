#ifndef HEAP_H
#define HEAP_H

#define MAX_Q_SIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

/*binary tree print*/
void binary_tree_print(const binary_tree_node_t *root,
	int (*print_data)(char *, void *));
/*major functions: 0*/
heap_t *heap_create(int (*data_cmp)(void *, void *));
/*1*/
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
/*2*/
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
/*3*/
void *heap_extract(heap_t *heap);
/*4*/
void heap_delete(heap_t *heap, void (*free_data)(void *));
/*6*/
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
/*7*/
int huffman_extract_and_insert(heap_t *priority_queue);
/*8*/
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
/*9*/
int huffman_codes(char *data, size_t *freq, size_t size);
/*helper functions: 2*/
void imba(binary_tree_node_t *node, int height, int left_h);
binary_tree_node_t *imba_node(binary_tree_node_t *node);
binary_tree_node_t *bubble_up(heap_t *heap, binary_tree_node_t *node);
/*3*/
binary_tree_node_t *keep_going(binary_tree_node_t *node,
				int cur, int h);
void *swapme(heap_t *heap, binary_tree_node_t *lastn);
void titanic(heap_t *heap, binary_tree_node_t *root);
/*4*/
void chain_free(binary_tree_node_t *node, void (*free_data)(void *));
/*6*/
int freak_cmp(void *p1, void *p2);
/*9*/
void simbakimba(binary_tree_node_t *node, int *kimba, size_t simba);
size_t binary_tree_height(const binary_tree_node_t *tree);

#endif /*HEAP_H*/
