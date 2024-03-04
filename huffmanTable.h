#ifndef HUFFMAN_TABLE_H
#define HUFFMAN_TABLE_H

#include <stdio.h>
/**
 * @file huffmanTable.h
 * @brief Header file for creating Huffman code tables.
 *
 * This file contains declarations for functions for creating Huffman
 * code tables from Huffman trees. A binary code is generated for all 128 ASCII
 * characters depending on their occurrence probability. Characters that are common have shorter codes
 * and characters that rae uncommon have longer ones.
 *
 * @author Spyros Sachmpazidis
 * @bug No know bugs.
 * @version 1.2
 * @since 22/11/23
 */

#include <stdlib.h>
#include <string.h>
#include "huffmanTree.h"
#include "huffmanTreeCreator.h"

/**
 * @brief Creates a Huffman table from a Huffman tree.
 *
 * This function takes a Huffman tree and creates a Huffman code table
 * represented as an array of strings. The functions reads the huffman tree node by node
 * and adds 0 if it goes to the left and 1 if it goes to the right. Using this recursive algorithm 
 * a binary code is generated for all 128 ASCII characters. Common characters have short codes and
 * rare ones have a longer code since they are located deeper in the huffman tree.
 *
 * @param tree Pointer to the Huffman tree.
 * @return A pointer to a character pointer array representing the Huffman code table.
 * @since 1.0
 */
char **createHuffmanTable(HuffmanTree *tree);

/**
 * @brief Recursively creates Huffman codes for each character in the tree.
 *
 * This function recursively traverses the Huffman tree to create Huffman
 * codes for each one of the 128 ASCII characters and stores them in the provided string array.
 * This function also returns 1 if a leaf node was found so that it knows which pointers can be freed and which ones
 * need to be kept.
 *
 * @param root Pointer to the current root of the Huffman tree.
 * @param codes Pointer to a character pointer array to store all the Huffman codes.
 * @param code Current Huffman code being generated.
 * @return 1 if a leaf node was found and 0 otherwise.
 * @since 1.1
 */
int createHuffmanCodes(Node *root, char **codes, char *code);

/**
 * @brief Writes Huffman codes to an output file.
 *
 * This function writes the Huffman codes from the provided Huffman code table
 * to the specified output file. Each code for all 128 ASCII characters is written in a different line.
 *
 * @param huffmanTable A pointer to a character pointer array representing the Huffman code table.
 * @since 1.1
 */
void writeCodes(char **huffmanTable);

/**
 * @brief Frees the memory allocated for a Huffman code table.
 *
 * This function frees the memory allocated for a Huffman code table.
 *
 * @param codes A pointer to a character pointer array representing the Huffman code table.
 * @since 1.2
 */
void freeHuffmanTable(char **codes);

#endif