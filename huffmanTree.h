/**
 *  @file huffmanTree.h
 *  @brief Header file for defining Huffman tree structures.
 *
 *  This file contains declarations for structures representing nodes in a Huffman
 *  tree and the Huffman tree itself.
 *
 *  @author Spyros Sachmpazidis
 *  @bug No know bugs.
 *  @version 1.0
 *  @since 21/11/23
 */

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#ifndef ASCII_SIZE
/*The size of the ASCII table*/
#define ASCII_SIZE 128
#endif

/**
 * @struct Node
 * @brief Represents a node in a Huffman tree.
 *
 * The node structure contains the character and pointers
 * to the left and right child nodes.
 * 
 * @since 1.0
 */
typedef struct node
{
    char character;
    struct node *left;
    struct node *right;
} Node;

/**
 * @struct HuffmanTree
 * @brief Represents a Huffman tree.
 *
 * The HuffmanTree structure contains the probability of the
 * tree and a pointer to the root of the tree.
 * 
 * @since 1.0
 */
typedef struct
{
    float probability;
    Node *root;
} HuffmanTree;

#endif