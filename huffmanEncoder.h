/**
 * @file huffmanEncoder.h
 * @brief Header file for encoding files using the Huffman algorithm.
 *
 * This file contains declarations for functions for encoding a file using the
 * Huffman algorithm. It encodes a file using a huffman code table that is generated form a huffman tree.
 * Each one of the 128 ASCII characters has a binary code with different length depending on its occurrence probability.
 * Rare characters have longer codes and common ones shorter. The encoded file contains only 1 line that is a binary sequence for all
 * the characters that the input file had.
 * 
 * @author Spyros Sachmpazidis
 * @bug No know bugs.
 * @version 1.0
 * @since 20/11/23
 */

#ifndef HUFFMAN_ENCODER_H
#define HUFFMAN_ENCODER_H

#include <stdio.h>
#include <stdlib.h>
#include "huffmanTreeCreator.h"
#include "huffmanTable.h"


/**
 * @brief Encodes a file using the Huffman algorithm and writes the encoded result to another file.
 *
 * This function takes an input file, encodes its content using the provided codes from the Huffman table
 * that were generated using a huffman tree, and writes the encoded result to
 * the specified output file. The encoded file contains only 1 line that is a binary sequence of the codes for
 * each character found in the input file.
 *
 * @param inputFile The input file.
 * @param outputFile The output file.
 * @param huffmanTable  A pointer to a character pointer array representing the Huffman code table.
 * @since 1.0
 */
void encodeFile(char *inputFile, char *outputFile, char **huffmanTable);

#endif