/**
 * @file huffmanTreeCreator.h
 * @brief Header file for a huffman Tree creator
 *
 * This file contains declarations for functions for creating huffman trees using the probability
 * of occurrence for each one of the 128 ASCII characters. The program uses the Huffman
 * algorithm to create a specific binary tree, were the deeper you go the lower the probability for those characters
 * to appear. Basically common characters are found first and uncommon ones later. This tree can later bee used to
 * encode a text file.
 *
 *  @author Spyros Sachmpazidis
 *  @bug No know bugs.
 *  @version 1.3
 *  @since 20/11/23
 */

#ifndef HUFFMAN_TREE_CREATOR_H
#define HUFFMAN_TREE_CREATOR_H

#include <stdio.h>
#include <stdlib.h>
#include "huffmanTree.h"

/** @brief Reads a file that has the probabilities for each character
 *
 *  This function reads character probabilities for all 128 ASCII characters from the specified input file and
 *  returns a pointer to a float array of probabilities for each character. The file must only contain
 *  one float per line that is the probability of that specific character occurring. 
 *
 *  @param inputFile the name of the input file(including .txt)
 *  @return a pointer to a float array that is contains the probabilities
 *  @since 1.0
 */
float *readProbabilities(char *inputFile);

/**
 * @brief Creates a Huffman tree based on character probabilities
 *
 * This function takes an array of character probabilities and uses the Huffman algorithm
 * to create a binary huffman tree. In the tree, the characters with the highest probability are found 
 * in the first leafs and the those with the least probability are found n the last leaves. This tree can
 * be used to encode a text file and save space by using variable bit sequences for each character, shorter for the
 * common ones and longer for the uncommon ones. 
 *
 * @param charProb a pointer to a float array of probabilities for each character.
 * @return A pointer to the created Huffman tree.
 * @since 1.0
 */
HuffmanTree *createHuffmanTree(float *charProb);

/**
 * @brief Initializes a Huffman tree with a character and probability.
 *
 * This function initializes a Huffman tree with the specified character and
 * probability. It is used to create the huffman tree for all characters, since
 * all characters must first be placed in a separate huffman tree and then the trees are merged 
 * depending on their probability into 1 bug tree containing all characters.
 *
 * @param tree Pointer to the Huffman tree to initialize.
 * @param prob Probability of the character.
 * @param c Character represented by the tree.
 * @since 1.1
 */
void initializeHuffmanTree(HuffmanTree *tree, float prob, char c);

/**
 * @brief Swaps two Huffman trees.
 *
 * This function swaps the root of two huffman trees. It is used 
 * for creating a huffman tree.
 *
 * @param treeA Pointer to the first Huffman tree.
 * @param treeB Pointer to the second Huffman tree.
 * @since 1.2
 */
void swapTrees(HuffmanTree *treeA, HuffmanTree *treeB);

/**
 * @brief Merges two Huffman trees into a new tree.
 *
 * This function merges two Huffman trees into the first tree by adding an additional node
 * that connects the two roots together. Note that the second tree is not deleted from the system memory by this 
 * function.
 *
 * @param treeA Pointer to the first Huffman tree.
 * @param treeB Pointer to the second Huffman tree.
 * @since 1.2
 */
void mergeTrees(HuffmanTree *treeA, HuffmanTree *treeB);

/**
 * @brief Finds the Huffman tree with the lowest probability.
 *
 * This function finds and returns a pointer to the Huffman tree with the lowest probability
 * among an array of trees.
 *
 * @param trees pointer to an array of Huffman trees.
 * @param treeCount Number of trees in the array.
 * @return Pointer to the Huffman tree with the lowest probability.
 * @since 1.1
 */
HuffmanTree *findLowestProbability(HuffmanTree *trees, int treeCount);

/**
 * @brief Finds the Huffman tree with the second lowest probability.
 *
 * This function finds and returns a pointer to the  Huffman tree with the second lowest
 * probability among an array of trees.
 *
 * @param trees Array of Huffman trees.
 * @param treeCount Number of trees in the array.
 * @return Pointer to the Huffman tree with the second lowest probability.
 * @since 1.1
 */
HuffmanTree *findSecondLowestProbability(HuffmanTree *trees, int treeCount);

/**
 * @brief Frees the allocated memory for a Huffman tree.
 *
 * This function recursively frees the allocated memory for a Huffman tree.
 *
 * @param tree Pointer to  the Huffman tree.
 * @since 1.3
 */
void freeHuffmanTree(HuffmanTree *tree);

/**
 * @brief Frees the memory allocated for all Huffman tree nodes recursively.
 *
 * This function frees the memory allocated for all Huffman tree nodes
 * recursively.
 *
 * @param root Pointer to node of the Huffman tree that will be freed.
 * @since 1.3
 */
void freeTree(Node *root);

#endif