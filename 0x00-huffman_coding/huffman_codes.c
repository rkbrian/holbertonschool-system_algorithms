#include "heap.h"
#include "huffman.h"

/**
 * huffman_codes - build the Huffman tree and print the resulting
 *  Huffman codes for each symbol
 * @data: array of characters of size
 * @freq: array containing the associated frequencies (of size)
 * @size: the size
 * Return: 1 if it succeed, 0 if it fails
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *root = NULL;
	int *symbiotes;
	size_t tree_height;

	if (!data || !freq || !size)
		return (0);
	root = huffman_tree(data, freq, size);
	tree_height = binary_tree_height(root);
	symbiotes = malloc(sizeof(int) * tree_height);
	if (!symbiotes)
		return (0);
	simbakimba(root, symbiotes, 0);
	free(symbiotes), chain_free(root, free);
	return (1);
}

/**
 * simbakimba - print all symbols and their Huffman codes in a tree
 * @node: node that holds the symbol data
 * @kimba: int string to be filled with the direction representations
 * @simba: current node level in the Huffman tree
 */
void simbakimba(binary_tree_node_t *node, int *kimba, size_t simba)
{
	size_t mufasa;

	if (node->parent && node->parent->left == node)
		kimba[simba - 1] = left_d;
	else if (node->parent && node->parent->right == node)
		kimba[simba - 1] = right_d;
	if (node && node->left == NULL && node->right == NULL)
	{
		printf("%c: ", ((symbol_t *)(node->data))->data);
		for (mufasa = 0; mufasa < simba; mufasa++)
			putchar(kimba[mufasa] + '0');
		putchar('\n');
		return;
	}
	simbakimba(node->left, kimba, simba + 1);
	simbakimba(node->right, kimba, simba + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: height of binary tree, or 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_node_t *tree)
{
	size_t i = 0, lefti, righti;

	if (!tree || (tree->left == NULL && tree->right == NULL))
		return (0);
	lefti = binary_tree_height(tree->left);
	righti = binary_tree_height(tree->right);
	if (lefti >= righti)
		i = lefti;
	else
		i = righti;
	return (i + 1);
}
