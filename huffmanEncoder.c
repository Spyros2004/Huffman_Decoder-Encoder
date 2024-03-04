#include "huffmanEncoder.h"

#ifdef DEBUG_HUFFMAN_ENCODER
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Correct files not given!\n");
        exit(EXIT_FAILURE);
    }
    printf("Debugging huffmanEncoder.c:\n");
    printf("Trying to open %s to read probabilities...\n", argv[1]);
    float *a = readProbabilities(argv[1]);
    printf("Success!\n");
    printf("Trying to create huffman tree...\n");
    HuffmanTree *tree = createHuffmanTree(a);
    printf("Success!\n");
    printf("Trying to create huffman table...\n");
    char **codes = createHuffmanTable(tree);
    printf("Success!Printing codes for all visible characters:\n");
    for (int i = 32; i < ASCII_SIZE - 1; i++)
        printf("%c\t%s\n", i, codes[i]);
    printf("Trying to encode %s into %s...\n", argv[2], argv[3]);
    encodeFile(argv[2], argv[3], codes);
    printf("Success!\n");
    free(a);
    freeHuffmanTree(tree);
    freeHuffmanTable(codes);
}
#endif

void encodeFile(char *inputFile, char *outputFile, char **huffmanTable)
{
    FILE *input = NULL;
    // check if file can be opened
    if ((input = fopen(inputFile, "r")) == NULL)
    {
        printf("Error: Unable to open %s\n", inputFile);
        exit(EXIT_FAILURE);
    }

    FILE *output = NULL;
    // check if file can be opened
    if ((output = fopen(outputFile, "w")) == NULL)
    {
        printf("Error: Unable to open %s\n", outputFile);
        exit(EXIT_FAILURE);
    }

    char token;
    // scan all the numbers from file and convert to huffman codes using huffman table
    while ((token = fgetc(input)) != EOF)
    {
        char *code = huffmanTable[(int)token];
        fprintf(output, "%s", code);
    }

    fclose(input);
    fclose(output);
}