/**
@mainpage EPL232 Assignment3

This program is used to encode and decode text files using the Huffman algorithm.
The program has several options that are selected using the command line arguments.\n

The usage for the program is the following:\n
<executable> -p <inputfile> <outputfile> : to calculate probabilities from the input file and save them in the output file, or\n
<executable> -s <probfile> : to create huffman tree using the probabilities from the probfile, or\n
<executable> -e <probfile> <inputfile> <encodedfile> : to encode the input file into the encoded file using the probabilities from the probfile, or\n
<executable> -d <probfile> <encodedfile> <decodedfile> : to decode a the encoded file into the decoded file using the probabilities from the probfile\n

Multiple options can be selected at once as long as all the arguments are correct for each option. 
In order to run, the user must at least select 1 option.\n

I personally really liked this project and i found it to be the appropriate difficulty with very satisfying results.

@author Spyros Sachmpazidis
*/