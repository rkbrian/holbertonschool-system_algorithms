#ifndef RB_TREES_H
#define RB_TREES_H

#define MAX_Q_SIZE 1024

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 -> I don't know what is this, it is given to me
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;
/**
 * struct queue_s - queue that stores the tree nodes for value comparison
 * @head: head node
 * @tail: tail node
 * @queue_arr: array of tree nodes
 */
typedef struct queue_s
{
	int head; /* position */
	int tail; /* position */
	rb_tree_t *queue_arr[MAX_Q_SIZE]; /* array of tree nodes */
} queue_q;

/* tree printer */
void rb_tree_print(const rb_tree_t *tree);
/* major functions */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int rb_tree_is_valid(const rb_tree_t *tree);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *array_to_rb_tree(int *array, size_t size);
/* helper functions */
int red_check(const rb_tree_t *tree);
int beast_wars(const rb_tree_t *tree, int root_num, int direction);
int rb_tree_balance(const rb_tree_t *tree, int max_height, int local_height);
size_t rb_tree_height(const rb_tree_t *tree);
void rb_rotator(rb_tree_t **tree, rb_tree_t *tmp);
rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree);
rb_tree_t *rb_tree_rotate_right(rb_tree_t *tree);
rb_tree_t *rb_tree_uncle(rb_tree_t *node);
void case_triangle(rb_tree_t **tree, rb_tree_t *parent);
void case_bar(rb_tree_t **tree, rb_tree_t *tmp);

#endif /* RB_TREES_H */
