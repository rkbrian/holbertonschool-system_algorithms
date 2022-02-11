#include "huffman.h"

/**
 * symbol_create - function that creates a symbol_t data structure
 * @data: the data to be stored in the structure
 * @freq: associated frequency of the data
 * Return: a pointer to the created structure, or NULL if it fails
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbiote;

	symbiote = malloc(sizeof(symbol_t));
	if (!symbiote)
		return (NULL);
	symbiote->data = data, symbiote->freq = freq;
	return (symbiote);
}
