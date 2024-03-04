#include "huffmanTable.h"

#ifdef DEBUG_HUFFMAN_TABLE
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Input file not given!\n");
        exit(EXIT_FAILURE);
    }
    printf("Debugging huffmanTree.c:\n");
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
    printf("Saving codes in codes.txt\n");
    writeCodes(codes);
    free(a);
    freeHuffmanTree(tree);
    freeHuffmanTable(codes);
}
#endif

char **createHuffmanTable(HuffmanTree *tree)
{
    char **codes = NULL;
    if ((codes = (char **)malloc(ASCII_SIZE * sizeof(char *))) == NULL)
    {
        printf("System out of memory!");
        exit(EXIT_FAILURE);
    }

    createHuffmanCodes(tree->root, codes, "");
    return codes;
}

int createHuffmanCodes(Node *root, char **codes, char *code)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
    {
        codes[(int)root->character] = code;
        return 1;
    }

    char *leftCode = malloc(strlen(code) + 2);
    strcpy(leftCode, code);
    strcat(leftCode, "0");
    if (!createHuffmanCodes(root->left, codes, leftCode))
        free(leftCode);

    char *rightCode = malloc(strlen(code) + 2);
    strcpy(rightCode, code);
    strcat(rightCode, "1");
    if (!createHuffmanCodes(root->right, codes, rightCode))
        free(rightCode);
    
    return 0;
}

void writeCodes(char **huffmanTable)
{
    FILE *fp = NULL;
    // check if file can be opened
    if ((fp = fopen("codes.txt", "w")) == NULL)
    {
        printf("Error: Unable to open codes.txt\n");
        exit(EXIT_FAILURE);
    }

    // write every code in output file
    int i;
    for (i = 0; i < ASCII_SIZE; i++)
        fprintf(fp, "%s\n", huffmanTable[i]);

    fclose(fp);
}

void freeHuffmanTable(char **codes)
{
    int i;
    for (i = 0; i < ASCII_SIZE; i++)
        free(codes[i]);

    free(codes);
}