#include "probabilityCalculator.h"

#ifdef DEBUG_PROBABILITY_CALCULATOR
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Input file not given!\n");
        exit(EXIT_FAILURE);
    }
    printf("Debugging probabilityCalculator.c:\n");
    printf("Trying to open %s to calculate probabilities...\n", argv[1]);
    float *a = calculateProbabilities(argv[1]);
    printf("Success!Printing probabilities for all visible characters:\n");
    for (int i = 32; i < ASCII_SIZE - 1; i++)
        printf("%c\t%f\n", i, a[i]);
    printf("Saving probabilities in probfile.txt\n");
    writeProbabilities("probfile.txt", a);
    free(a);
}
#endif

float *calculateProbabilities(char *inputFile)
{
    FILE *fp = NULL;
    // check if file opens correctly
    if ((fp = fopen(inputFile, "r")) == NULL)
    {
        printf("Input file cannot be read!\n");
        exit(EXIT_FAILURE);
    }

    int totalCount = 0;
    int *charCount = NULL;
    float *charProb = NULL;
    // check for calloc error
    if ((charCount = (int *)calloc(ASCII_SIZE, sizeof(int))) == NULL)
    {
        printf("System out of memory!");
        exit(EXIT_FAILURE);
    }
    if ((charProb = (float *)calloc(ASCII_SIZE, sizeof(float))) == NULL)
    {
        printf("System out of memory!");
        exit(EXIT_FAILURE);
    }

    char token;
    // scan all the numbers from file to fill the table
    while ((token = fgetc(fp)) != EOF)
    {
        charCount[(int)token]++;
        totalCount++;
    }

    int i;
    for (i = 0; i < ASCII_SIZE; i++)
        charProb[i] = (float)charCount[i] / totalCount;

    fclose(fp);
    free(charCount);
    return charProb;
}

void writeProbabilities(char *outputFile, float *charProb)
{
    FILE *fp = NULL;
    // check if file can be opened
    if ((fp = fopen(outputFile, "w")) == NULL)
    {
        printf("Error: Unable to open %s\n", outputFile);
        exit(EXIT_FAILURE);
    }

    // write every probability in output file
    int i;
    for (i = 0; i < ASCII_SIZE; i++)
        fprintf(fp, "%f\n", charProb[i]);

    fclose(fp);
}