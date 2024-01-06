//
// Created by Giovanni on 12/6/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/output.h"
#include "../include/error.h"

// print the report
void printReport(word aux, int dictionary[], int letters, char *output) {
    FILE *outputFile = fopen(output, "w");
    fileError(outputFile);
    int c = atoi(aux.c);
    fprintf(outputFile,"%d\n", c);

    for(int i = 0; i<letters; i++) {
        fprintf(outputFile, "%c:%c\n", dictionary[i], dictionary[letters+i]);
    }
    fclose(outputFile);
    exit(0);
}
// print -1
void fail(char *message) {
    FILE* errorFile = fopen(message, "w");
    fileError(errorFile);
    fprintf(errorFile, "-1");
    fclose(errorFile);
}