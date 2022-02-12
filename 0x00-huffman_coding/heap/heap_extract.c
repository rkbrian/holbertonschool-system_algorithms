#include "heap.h"

/**
 * heap_extract - function that extracts the root value of a Min Binary Heap
 * @heap: a pointer to the heap from which to extract the value
 * Return: a ptr to the data that was stored in the root node of the heap,
 *  or NULL if function fails or heap is NULL.
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *leftmost = NULL, *q_cur = NULL, *ret, *last_node = NULL;
	int left_h = 1, cue_flag = 0;
	queue_q *q;
	void *ret_d;

	if (!heap)
		return (NULL);
	if (heap->root->left == NULL && heap->root->right == NULL)
	{
		ret = heap->root, ret_d = ret->data, heap->root = NULL;
		free(ret), heap->size--;
		return (ret_d);
	}
	leftmost = heap->root, q = malloc(sizeof(queue_q));
	if (!q)
		return (NULL);
	q->head = 1, q->tail = 0, queue_store(q, heap->root);
	while (leftmost && leftmost->left)
		leftmost = leftmost->left, left_h++;
	while ((q->tail + 1) % MAX_Q_SIZE != q->head)
	{
		q_cur = queue_remove(q, q_cur);
		if (q_cur)
		{
			if (q_cur->left)
				queue_store(q, q_cur->left);
			if (q_cur->right)
				queue_store(q, q_cur->right);
		}
		if (q_cur == leftmost)
			cue_flag++;
		if (cue_flag && q_cur)
			last_node = q_cur;
	}
	free(q), ret_d = swapme(heap, last_node);
	return (ret_d);
}

/**
 * queue_store - store data to queue
 * @queen: the queue
 * @node: tree node of the same depth (from root)
 * Return: 0 if success, 1 if failed
 */
int queue_store(queue_q *queen, const binary_tree_node_t *node)
{
	if ((queen->tail + 2) % MAX_Q_SIZE == queen->head) /* if queue is full */
		return (1);
	queen->tail = (queen->tail + 1) % MAX_Q_SIZE;
	queen->queue_arr[queen->tail] = (binary_tree_node_t *)node;
	return (0);
}

/**
 * queue_remove - extract node data from queue
 * @queen: the queue
 * @node: tree node of the same depth (from root)
 * Return: node pointer with acquired data if success, null if failed
 */
binary_tree_node_t *queue_remove(queue_q *queen,
				const binary_tree_node_t *node)
{
	if ((queen->tail + 1) % MAX_Q_SIZE == queen->head) /* if queue is empty */
		return (NULL);
	node = queen->queue_arr[queen->head];
	queen->head = (queen->head + 1) % MAX_Q_SIZE;
	return ((binary_tree_node_t *)node);
}

/**
 * swapme - function to swap the last node with the root (to be extracted)
 * @heap: a pointer to the heap from which to extract the value
 * @lastn: the last node of the heap tree
 * Return: extracted data
 */
void *swapme(heap_t *heap, binary_tree_node_t *lastn)
{
	binary_tree_node_t *ret = NULL;
	void *ret_data;

	ret = heap->root, ret_data = ret->data, heap->root = lastn;
	if (lastn->parent->left == lastn)
		lastn->parent->left = NULL;
	else if (lastn->parent->right == lastn)
		lastn->parent->right = NULL;
	lastn->parent = NULL;
	if (heap->size > 3)
	{
		lastn->left = ret->left, lastn->right = ret->right;
		ret->left->parent = lastn, ret->right->parent = lastn;
	}
	else if (heap->size == 3)
		lastn->left = ret->left, ret->left->parent = lastn;
	free(ret), heap->size--, ret = heap->root, titanic(heap, ret);
	return (ret_data);
}

/**
 * titanic - function to sink the larger heap data
 * @heap: a pointer to the heap from which to extract the value
 * @root: heap node with large data
 */
void titanic(heap_t *heap, binary_tree_node_t *root)
{
	binary_tree_node_t *c = root;
	void *t;

	while (c->left || c->right)
	{
		if (c->left && c->right)
		{
			if (heap->data_cmp(c->left->data, c->right->data) < 0 &&
			heap->data_cmp(c->left->data, c->data) < 0)
				t = c->left->data, c->left->data = c->data, c->data = t, c = c->left;
			else if (heap->data_cmp(c->left->data, c->right->data) > 0 &&
			heap->data_cmp(c->right->data, c->data) < 0)
				t = c->right->data, c->right->data = c->data, c->data = t, c = c->right;
			else
				break;
		}
		else if (c->left)
		{
			if (heap->data_cmp(c->left->data, c->data))
				t = c->left->data, c->left->data = c->data, c->data = t, c = c->left;
			else
				break;
		}
		else
		{
			if (heap->data_cmp(c->right->data, c->data))
				t = c->right->data, c->right->data = c->data, c->data = t, c = c->right;
			else
				break;
		}
	}
}
