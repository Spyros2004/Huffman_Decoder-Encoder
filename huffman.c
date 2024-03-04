/**
 * @file huffman.c
 * @brief Main program for Huffman encoding and decoding.
 *
 * This program provides a command-line interface for Huffman coding operations,
 * including probability calculation, Huffman tree creation, file encoding, and decoding.
 * 
 * @author Spyros Sachmpazidis
 * @bug No know bugs.
 * @version 1.1
 * @since 23/11/23
 */

#include "probabilityCalculator.h"
#include "huffmanTreeCreator.h"
#include "huffmanTable.h"
#include "huffmanDecoder.h"
#include "huffmanEncoder.h"
#include <getopt.h>
#include <ctype.h>

/**
 * @brief Prints usage instructions for the program.
 *
 * This function provides information on how to use the program, specifically the
 * various command-line options and their corresponding functionalities.
 * 
 * @since 1.1
 */
void printUsage()
{
    printf("Usage:\n");
    printf("<executable> -p <inputfile> <outputfile>\t to calculate probabilities, or\n");
    printf("<executable> -s <probfile> \t to create huffman tree, or\n");
    printf("<executable> -e <probfile> <inputfile> <encodedfile>\t to encode a file, or\n");
    printf("<executable> -d <probfile> <encodedfile> <decodedfile>\t to decode a file\n");
}

/**
 * @brief Main entry point for the program.
 *
 * The main function parses command-line arguments and according to the selected options
 * it can do the following: calculate the occurrence probability of all characters from an input file,
 * create a huffman tree and huffman tale using those probabilities, encode a file and decode a file.
 * 
 * The usage for the program is the following:\n
 * <executable> -p <inputfile> <outputfile> : to calculate probabilities from the input file and save them in the output file, or\n
 * <executable> -s <probfile> : to create huffman tree using the probabilities from the probfile, or\n
 * <executable> -e <probfile> <inputfile> <encodedfile> : to encode the input file into the encoded file using the probabilities from the probfile, or\n
 * <executable> -d <probfile> <encodedfile> <decodedfile> : to decode a the encoded file into the decoded file using the probabilities from the probfile.\n
 * 
 * Multiple options can be selected at once as long as all the arguments are correct for each option. 
 * In order to run, the user must at least select 1 option.
 * 
 * @since 1.0
 */
int main(int argc, char **argv)
{
    // check if no command line args are given
    if (argc == 1)
    {
        printf("No command line arguments given!\n");
        printUsage();
        return EXIT_FAILURE;
    }

    // initialize flags for all possible arguments
    int pflag = 0;
    int sflag = 0;
    int eflag = 0;
    int dflag = 0;

    // initialize arguments for all options
    char *sampleFile = NULL;
    char *probFile = NULL;
    char *dataFile = NULL;
    char *encodedFile = NULL;
    char *decodedFile = NULL;

    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "p:s:e:d:")) != -1)
    {
        switch (c)
        {
        case 'p':
            pflag = 1;
            // check if sample and output are given
            sampleFile = optarg;
            if (optind < argc && argv[optind])
            {
                probFile = argv[optind];
                optind++;
            }
            else
            {
                printf("Invalid format for -p.\n");
                printf("Usage: <executable> -p <inputfile> <outputfile>\n");
                return EXIT_FAILURE;
            }
            break;
        case 's':
            sflag = 1;
            probFile = optarg;
            break;
        case 'e':
            eflag = 1;
            // check all files are given
            probFile = optarg;
            if (optind < argc && argv[optind])
            {
                dataFile = argv[optind];
                optind++;
            }
            if (optind < argc && argv[optind])
            {
                encodedFile = argv[optind];
                optind++;
            }
            else
            {
                printf("Invalid format for -e.\n");
                printf("Usage: <executable> -e <probfile> <inputfile> <encodedfile>\n");
                return EXIT_FAILURE;
            }
            break;
        case 'd':
            dflag = 1;
            // check all files are given
            probFile = optarg;
            if (optind < argc && argv[optind])
            {
                encodedFile = argv[optind];
                optind++;
            }
            if (optind < argc && argv[optind])
            {
                decodedFile = argv[optind];
                optind++;
            }
            else
            {
                printf("Invalid format for -d.\n");
                printf("Usage: <executable> -d <probfile> <encodedfile> <decodedfile>\n");
                return EXIT_FAILURE;
            }
            break;
        case '?':
            if (optopt == 'p')
                printf("Option requires 2 string argument -- 'p'\n");
            else if (optopt == 's')
                printf("option requires a string argument -- 's'\n");
            else if (optopt == 'e')
                printf("option requires 3 string argument -- 'e'\n");
            else if (optopt == 'd')
                printf("option requires 3 string argument -- 'd'\n");
            else if (isprint(optopt))
                printf("Invalid option -- '%c'\n", optopt);
            printUsage();
            return EXIT_FAILURE;
        default:
            break;
        }
    }

    printf("\n");
    // check for all arguments
    if (pflag)
    {
        float *prob = calculateProbabilities(sampleFile);
        writeProbabilities(probFile, prob);
        free(prob);
    }
    if (sflag)
    {
        float *a = readProbabilities(probFile);
        HuffmanTree *tree = createHuffmanTree(a);
        char **codes = createHuffmanTable(tree);
        printf("Printing codes for all visible characters:\n");
        for (int i = 32; i < ASCII_SIZE - 1; i++)
            printf("%c:\t%s\n", i, codes[i]);
        writeCodes(codes);
        free(a);
        freeHuffmanTree(tree);
        freeHuffmanTable(codes);
    }
    if (eflag)
    {
        float *a = readProbabilities(probFile);
        HuffmanTree *tree = createHuffmanTree(a);
        char **codes = createHuffmanTable(tree);
        encodeFile(dataFile, encodedFile, codes);
        free(a);
        freeHuffmanTree(tree);
        freeHuffmanTable(codes);
    }
    if (dflag)
    {
        float *a = readProbabilities(probFile);
        HuffmanTree *tree = createHuffmanTree(a);
        decodeFile(encodedFile, decodedFile, tree);
        free(a);
        freeHuffmanTree(tree);
    }
    printf("\n");

    return 0;
}