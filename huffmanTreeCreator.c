#include "huffmanTreeCreator.h"

#ifdef DEBUG_HUFFMAN_TREE_CREATOR
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Input file not given!\n");
        exit(EXIT_FAILURE);
    }
    printf("Debugging huffmanTreeCreator.c:\n");
    printf("Trying to open %s to read probabilities...\n", argv[1]);
    float *a = readProbabilities(argv[1]);
    printf("Success!Printing probabilities for all visible characters:\n");
    for (int i = 32; i < ASCII_SIZE - 1; i++)
        printf("%c\t%f\n", i, a[i]);
    printf("Trying to create huffman tree...\n");
    HuffmanTree *tree = createHuffmanTree(a);
    printf("Success!Printing probability of the final tree:\n%f\n", tree->probability);
    free(a);
    freeHuffmanTree(tree);
}
#endif

float *readProbabilities(char *inputFile)
{
    FILE *fp = NULL;
    // check if file opens correctly
    if ((fp = fopen(inputFile, "r")) == NULL)
    {
        printf("Input file cannot be read!\n");
        exit(EXIT_FAILURE);
    }

    float *charProb = NULL;
    if ((charProb = (float *)calloc(ASCII_SIZE, sizeof(float))) == NULL)
    {
        printf("System out of memory!");
        exit(EXIT_FAILURE);
    }

    float *tp = charProb;
    float token;
    // scan all the numbers from file to fill the table
    while (fscanf(fp, "%f", &token) != EOF)
    {
        *tp = token;
        tp++;
    }

    fclose(fp);
    return charProb;
}

HuffmanTree *createHuffmanTree(float *charProb)
{
    HuffmanTree *charTrees = NULL;
    if ((charTrees = (HuffmanTree *)malloc(ASCII_SIZE * sizeof(HuffmanTree))) == NULL)
    {
        printf("System out of memory!");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < ASCII_SIZE; i++)
        initializeHuffmanTree(&charTrees[i], charProb[i], i);

    int treeCount = ASCII_SIZE;
    while (treeCount > 1)
    {
        HuffmanTree *lowest = findLowestProbability(charTrees, treeCount);
        HuffmanTree *secondLowest = findSecondLowestProbability(charTrees, treeCount);

        swapTrees(lowest, &charTrees[treeCount - 2]);
        swapTrees(secondLowest, &charTrees[treeCount - 1]);
        mergeTrees(&charTrees[treeCount - 2], &charTrees[treeCount - 1]);

        treeCount--;
        HuffmanTree *temp = realloc(charTrees, treeCount * sizeof(HuffmanTree));
        if (temp == NULL)
        {
            free(charTrees);
            printf("System out of memory!");
            exit(EXIT_FAILURE);
        }
        charTrees = temp;
    }

    return charTrees;
}

void initializeHuffmanTree(HuffmanTree *tree, float prob, char c)
{
    tree->probability = prob;

    tree->root = NULL;
    if ((tree->root = (Node *)malloc(sizeof(Node))) == NULL)
    {
        printf("System out of memory!");
        exit(EXIT_FAILURE);
    }

    tree->root->character = c;
    tree->root->left = NULL;
    tree->root->right = NULL;
}

void swapTrees(HuffmanTree *treeA, HuffmanTree *treeB)
{
    float tempProb = treeA->probability;
    Node *tempRoot = treeA->root;

    treeA->probability = treeB->probability;
    treeA->root = treeB->root;

    treeB->probability = tempProb;
    treeB->root = tempRoot;
}

void mergeTrees(HuffmanTree *treeA, HuffmanTree *treeB)
{
    Node *tempRoot = treeA->root;

    treeA->probability += treeB->probability;
    treeA->root = NULL;
    if ((treeA->root = (Node *)malloc(sizeof(Node))) == NULL)
    {
        printf("System out of memory!");
        exit(EXIT_FAILURE);
    }
    treeA->root->character = '\0';
    treeA->root->left = tempRoot;
    treeA->root->right = treeB->root;
}

HuffmanTree *findLowestProbability(HuffmanTree *trees, int treeCount)
{
    float min = 1;
    HuffmanTree *minTree = NULL;

    int i;
    for (i = 0; i < treeCount; i++)
    {
        if (trees[i].probability < min)
        {
            min = trees[i].probability;
            minTree = &trees[i];
        }
    }

    return minTree;
}

HuffmanTree *findSecondLowestProbability(HuffmanTree *trees, int treeCount)
{
    HuffmanTree *lowestTree = findLowestProbability(trees, treeCount);
    float min = 1;
    HuffmanTree *minTree = NULL;

    int i;
    for (i = 0; i < treeCount; i++)
    {
        if (trees[i].probability < min && &trees[i] != lowestTree)
        {
            min = trees[i].probability;
            minTree = &trees[i];
        }
    }

    return minTree;
}

void freeHuffmanTree(HuffmanTree *tree)
{
    freeTree(tree->root);
    free(tree);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}