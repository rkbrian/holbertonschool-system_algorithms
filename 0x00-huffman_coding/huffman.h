#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

/*major functions*/
symbol_t *symbol_create(char data, size_t freq); /*5*/

#endif /*HUFFMAN_H*/
