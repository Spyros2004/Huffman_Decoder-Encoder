/**
 * @file probabilityCalculator.h
 * @brief Header file for a probability calculator.
 *
 * This file contains declarations for functions for calculating the probabilities for all 128 
 * ASCII characters in a text file. The probabilities can also be written in another file.
 * 
 *  @author Spyros Sachmpazidis
 *  @bug No know bugs.
 *  @version 1.1
 *  @since 20/11/23
 */
#ifndef PROBABILITY_CALCULATOR_H
#define PROBABILITY_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>

#ifndef ASCII_SIZE
/*The size of the ASCII table*/
#define ASCII_SIZE 128
#endif


/** @brief Reads a file and calculates probabilities for each character
 *
 *  This function reads a file and it creates a probability table.
 *  The file must only include the first 128 ASCII characters.
 *  The probability of occurrence for each one of the 128 characters is calculated and placed in a float array.
 *  The function then returns a pointer to the first float of the array.
 *
 *  @param inputFile the name of the input file(including .txt)
 *  @return a pointer to a float array that is contains the probabilities
 *  @since 1.0
 */
float *calculateProbabilities(char *inputFile);

/** @brief Writes the probabilities in a file
 *
 *  This function writes the probabilities for all characters in a file with the correct format.
 *  Each line of the file will have exactly 1 float number, that is the probability of that
 *  ASCII character to occur.
 *
 *  @param outputFile the name of the output file(including .txt)
 *  @param charProb a pointer to the array of probabilities for each character
 *  @since 1.1
 */
void writeProbabilities(char *outputFile, float *charProb);

#endif