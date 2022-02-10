#include "heap.h"

/**
 * heap_extract - function that extracts the root value of a Min Binary Heap
 * @heap: a pointer to the heap from which to extract the value
 * Return: a ptr to the data that was stored in the root node of the heap,
 *  or NULL if function fails or heap is NULL.
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *leftmost = NULL, *q_cur = NULL;
	binary_tree_node_t *ret, *p_arr[MAX_Q_SIZE], *ch_arr[MAX_Q_SIZE];
	int left_h = 1, q_size = 0, cue_size = 0, cue_flag = 0, q_flag = 0;
	queue_q *q;
	void *ret_d;

	if (!heap)
		return (NULL);
	if (heap->root->left == NULL && heap->root->right == NULL)
	{
		ret = heap->root, ret_d = ret->data, heap->root = NULL, free(ret);
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
		if (q_cur == leftmost->parent)
			q_flag++;
		else if (q_cur == leftmost)
			q_flag = 0, cue_flag++;
		if (cue_flag)
			ch_arr[cue_size] = q_cur, cue_size++;
		if (q_flag)
			p_arr[q_size] = q_cur, q_size++;
	}
	free(q), ret_d = ex_rebuild(heap, ch_arr, p_arr, cue_size, q_size, leftmost);
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
 * ex_rebuild - fuction to reconnect all nodes
 * @heap: a pointer to the heap from which to extract the value
 * @ch_arr: pointer array of the last level of the heap tree
 * @p_arr: pointer array of the 2nd last level of the heap tree
 * @cue_size: null ending index of ch_arr
 * @q_size: null ending index of p_arr
 * @leftmost: the leftmost node in the heap tree
 * Return: a ptr to the data that was stored in the root node of the heap,
 *  or NULL if function fails or heap is NULL.
 */
void *ex_rebuild(heap_t *heap, binary_tree_node_t **ch_arr,
		binary_tree_node_t **p_arr, int cue_size, int q_size,
		binary_tree_node_t *leftmost)
{
	int i = 1, j = 1;
	binary_tree_node_t *ret, *q_cur = NULL, *cue_cur = NULL, *current = NULL;
	void *ret_data;

	ch_arr[cue_size] = NULL, p_arr[q_size] = NULL, ret = heap->root;
	ret_data = ret->data, q_cur = ret->left, cue_cur = ret->right, heap->root = q_cur;
	while (q_cur)
	{
		current = q_cur->right, q_cur->right = cue_cur;
		if (cue_cur)
			cue_cur->parent = q_cur;
		cue_cur = current, q_cur = q_cur->left;
	}
	heap->size--, leftmost->left = ch_arr[j], ch_arr[j]->parent = leftmost;
	j++, leftmost->right = NULL;
	if (ch_arr[j])
	{
		leftmost->right = ch_arr[j], ch_arr[j]->parent = leftmost, j++;
		while (ch_arr[j] && p_arr[i])
		{
			p_arr[i]->left = ch_arr[j], ch_arr[j]->parent = p_arr[i];
			j++, p_arr[i]->right = NULL;
			if (ch_arr[j])
				p_arr[i]->right = ch_arr[j], ch_arr[j]->parent = p_arr[i], j++;
			i++;
		}
	}
	free(ret);
	return (ret_data);
}
