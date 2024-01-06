#include <stdio.h>
#include "../include/input.h"
#include "../include/error.h"

// get the words from the file
void getWords(word *words, char *argv){
    FILE *filePtr = NULL;
    filePtr = fopen(argv,"r");
    fileError(filePtr);
    fscanf(filePtr, "%8[^\n]\n", words->a);
    fscanf(filePtr, "%8[^\n]\n", words->b);
    fscanf(filePtr, "%8[^\n]\n", words->c);
    fclose(filePtr);
}
