#include "heap.h"
#include "huffman.h"

/**
 * huffman_tree - function that builds the Huffman tree
 * @data: an array of characters of size
 * @freq: an array containing the associated frequencies (of size too)
 * @size: array size
 * Return: a ptr to the root node of the Huffman tree, or NULL if it fails
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *huff_t;
	binary_tree_node_t *ln = NULL, *rn = NULL, *node = NULL;
	size_t i = size;
	char da = -1; /*char -1 considered junks in heap, no free*/
	queue_q *q; /*for sorted symbol nodes*/

	huff_t = huffman_priority_queue(data, freq, size);
	if (!huff_t)
		return (NULL);
	if (size < 2)
		return (huff_t->root);
	q = malloc(sizeof(queue_q));
	if (!q)
	{
		heap_delete(huff_t, NULL);
		return (NULL);
	}
	huff_t->data_cmp = regular_cmp, unzip_data(huff_t->root);
	ln = huff_t->root, rn = huff_t->root->left;
	ln = combine_data(ln, NULL), rn = combine_data(rn, NULL);
	q->head = 1, q->tail = 0, queue_store(q, ln), queue_store(q, rn), i -= 2;
	while (i > 0)
	{
		ln = NULL, rn = NULL;
		if (huffman_extract_and_insert(huff_t))
		{
			if (huff_t->root && huff_t->root != q->queue_arr[q->head] &&
			(char)(((symbol_t *)(huff_t->root->data))->data) != da)
				ln = combine_data(huff_t->root, NULL), queue_store(q, ln), i--;
			if (huff_t->root->left && huff_t->root != q->queue_arr[q->head] &&
			(char)(((symbol_t *)(huff_t->root->left->data))->data) != da)
				rn = combine_data(huff_t->root->left, NULL), queue_store(q, rn), i--;
		}
	}
	node = queue_remove(q, node); /*greedy algorithm*/
	while ((q->tail + 1) % MAX_Q_SIZE != q->head)
		node = greedy_connect(q, node), huff_t->size++;
	huff_t->root = node, free(q);
	return (huff_t->root);
}

/**
 * unzip_data - function to decompress data
 * @root: node to be decompressed
 */
void unzip_data(binary_tree_node_t *root)
{
	binary_tree_node_t *curr = NULL, *curr_left = NULL, *curr_right = NULL;

	if (!root)
		return;
	curr = root, curr_left = curr->left, curr_right = curr->right;
	curr->data = (symbol_t *)(((binary_tree_node_t *)(curr->data))->data);
	unzip_data(curr_left), unzip_data(curr_right);
}

/**
 * greedy_connect - using greedy algorithm to make and connect nodes
 * @q: queue (array of nodes) that stores nodes
 * @node: child node to be connected
 * Return: parent node
 */
binary_tree_node_t *greedy_connect(queue_q *q, binary_tree_node_t *node)
{
	binary_tree_node_t *l_n = NULL, *par = NULL;
	binary_tree_node_t *prep = NULL, *ll = NULL, *lr = NULL;
	size_t tmp = 0;
	char da = -1;

	prep = queue_remove(q, prep), tmp = ((symbol_t *)(node->data))->freq;
	if (((symbol_t *)(node->data))->data != da) /*start*/
	{
		par = combine_data(prep, node), par->left = node, par->right = prep;
		prep->parent = par, node->parent = par;
		return (par);
	}
	else if (q->tail % MAX_Q_SIZE != q->head &&
		(((symbol_t *)(prep->data))->freq) * 2 < tmp) /*balancing*/
	{
		ll = prep, lr = queue_remove(q, lr), l_n = combine_data(ll, lr);
		l_n->left = ll, l_n->right = lr, ll->parent = l_n, lr->parent = l_n;
		par = combine_data(l_n, node), par->left = l_n, par->right = node;
		l_n->parent = par, node->parent = par;
		return (par);
	}
	par = combine_data(prep, node), par->left = prep, par->right = node;
	prep->parent = par, node->parent = par;
	return (par);
}
