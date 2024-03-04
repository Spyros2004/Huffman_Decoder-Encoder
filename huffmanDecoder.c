#include "huffmanDecoder.h"

#ifdef DEBUG_HUFFMAN_DECODER
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Correct files not given!\n");
        exit(EXIT_FAILURE);
    }
    printf("Debugging huffmanDecoder.c:\n");
    printf("Trying to open %s to read probabilities...\n", argv[1]);
    float *a = readProbabilities(argv[1]);
    printf("Success!\n");
    printf("Trying to create huffman tree...\n");
    HuffmanTree *tree = createHuffmanTree(a);
    printf("Success!\n");
    printf("Trying to decode %s into %s...\n", argv[2], argv[3]);
    decodeFile(argv[2], argv[3], tree);
    printf("Success!\n");
    free(a);
    freeHuffmanTree(tree);
}
#endif

void decodeFile(char *inputFile, char *outputFile, HuffmanTree *tree)
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
    Node *start = tree->root;
    // scan all the numbers from file and convert to characters using huffman tree
    while ((token = fgetc(input)) != EOF)
    {
        if (token == '0')
            start = start->left;
        if (token == '1')
            start = start->right;
        if (start->left == NULL && start->right == NULL)
        {
            fputc(start->character, output);
            start = tree->root;
        }
    }

    fclose(input);
    fclose(output);
}