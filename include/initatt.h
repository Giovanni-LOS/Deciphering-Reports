#ifndef REPORT_INIT_ATT_H
#define REPORT_INIT_ATT_H

#include "input.h"


void initHistogram(word words, int histogram[]);
void initDictionary(int dictionary[], int histogram[],word words, int letters);
void initLetters(int *letters, int histogram[]);
void attAux(word words, word *aux, int dictionary[], int letters);

#endif // REPORT_INIT_ATT_H
