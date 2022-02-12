# 0x00. C - Huffman coding

## General
 - What is a binary Heap (min and max)
 - What is a priority queue
 - What is a Huffman code

#### 0. Min Binary Heap - Create heap
#### 1. Min Binary Heap - Create node
#### 2. Min Binary Heap - Insert node
#### 3. Min Binary Heap - Extract
#### 4. Min Binary Heap - Delete heap
#### 5. Symbols: Create symbol
#### 6. Huffman coding - Step 1: Priority queue
#### 7. Huffman coding - Step 2: Extract
Once we have our priority queue initialized, the next step is to build the Huffman tree. First we need to understand the process of building such a tree. We need to extract the two least frequent symbols from our priority queue, add their frequencies, and store this new frequency back in our priority queue.

Remember that in our priority queue, each node stores a leaf node that stores our symbol_t *. The goal here, is to make the two extracted nodes (containing the symbol_t *) the children of the new node we will create (the one that will store the sum of the two frequencies). The first extracted node will be the left child, and the second one will be the right child. Then this node will be stored (inside a node) in our priority queue.

So, at the end of this process, our priority queue will see its size decreased by one (we extract two, we insert back one). Note that we will use the value -1 as the char data for the new symbol we will create. (In the example below, we print it as a dollar sign)
#### 
#### 
