#include "heap.h"
#include "huffman.h"

/**
 * huffman_extract_and_insert - function that extracts the two nodes of the
 *  priority queue and insert a new one
 * @priority_queue: a pointer to the priority queue to extract from
 * Return: 1 on success or 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	size_t ab, data_a, data_b;
	binary_tree_node_t *new_node = NULL;
	symbol_t *symbiote = NULL;
	char data = -1;

	if (!priority_queue || priority_queue->size < 2)
		return (0);
	if (priority_queue->data_cmp == freak_cmp)
	{
		new_node = (binary_tree_node_t *)heap_extract(priority_queue);
		data_a = ((symbol_t *)new_node->data)->freq, free(new_node);
		new_node = (binary_tree_node_t *)heap_extract(priority_queue);
		data_b = ((symbol_t *)new_node->data)->freq;
		ab = data_a + data_b, ((symbol_t *)new_node->data)->data = data;
		((symbol_t *)new_node->data)->freq = ab;
		heap_insert(priority_queue, new_node);
	}
	else if (priority_queue->data_cmp == regular_cmp)
	{
		symbiote = (symbol_t *)heap_extract(priority_queue);
		data_a = symbiote->freq;
		symbiote = (symbol_t *)heap_extract(priority_queue);
		data_b = symbiote->freq, ab = data_a + data_b;
		symbiote->data = data, symbiote->freq = ab;
		heap_insert(priority_queue, symbiote);
	}
	return (1);
}

/**
 * combine_data - function to copy and combine data sets from 2 nodes into 1
 * @na: node a
 * @nb: node b, if it is null, make a copy of node a and return it
 * Return: new node with combined data
 */
binary_tree_node_t *combine_data(binary_tree_node_t *na,
	binary_tree_node_t *nb)
{
	binary_tree_node_t *new_n = NULL;
	char dataa;
	size_t freqa, freqb;

	freqa = ((symbol_t *)(na->data))->freq;
	if (!nb)
		dataa = ((symbol_t *)(na->data))->data, freqb = 0;
	else
		dataa = -1, freqb = ((symbol_t *)(nb->data))->freq;
	new_n = binary_tree_node(NULL, symbol_create(dataa, freqa + freqb));
	return (new_n);
}

/**
 * regular_cmp - Compares two frequencies in 2 unzipped data
 * @p1: First pointer
 * @p2: Second pointer
 * Return: Difference between the two frequencies
 */
int regular_cmp(void *p1, void *p2)
{
	size_t n1, n2;

	n1 = ((symbol_t *)(p1))->freq;
	n2 = ((symbol_t *)(p2))->freq;
	if (n1 > n2)
		return (1);
	else if (n1 < n2)
		return (-1);
	return (0);
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
