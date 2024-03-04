/**
 * @file huffmanDecoder.h
 * @brief Header file for decoding files using the Huffman algorithm.
 *
 * This file contains declarations for functions for decoding a file using the 
 * Huffman algorithm.
 *
 * @author Spyros Sachmpazidis
 * @bug No know bugs.
 * @version 1.0
 * @since 23/11/23
 */

#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include <stdio.h>
#include <stdlib.h>
#include "huffmanTree.h"
#include "huffmanTreeCreator.h"

/**
 * @brief Decodes a file using the Huffman algorithm and writes the decoded result to another file.
 *
 * This function takes an input file that contains a binary sequence of characters that was created using
 * the HUffman algorithm, decodes
 * it using the provided Huffman tree, and writes the decoded result to the
 * specified output file. In order to decode the file, the function starts at the root fo the tree
 * and reads the encoded file character by character. When a 0 is encountered it goes to the left node and when a 1 it goes to the
 * right node. If at any point a leaf node is found, then the character in the leaf node is printed and the algorithm
 * goes back to the tree root. This proccess is continued until the whole file is decoded.
 *
 * @param inputFile The input file.
 * @param outputFile The output file.
 * @param tree Pointer to the Huffman tree.
 * @since 1.0
 */
void decodeFile(char *inputFile, char *outputFile, HuffmanTree *tree);

#endif