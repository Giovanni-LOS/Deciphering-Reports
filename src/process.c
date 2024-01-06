//
// Created by Giovanni on 12/6/23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/process.h"
#include "../include/initatt.h"
#include "../include/output.h"

// process the words
int testCase(word aux){
    int integerA = atoi(aux.a);
    int integerB = atoi(aux.b);
    int integerC = atoi(aux.c);
    if((integerA+integerB)==integerC) {
        return 1;
    } else {
        return 0;
    }
}
// verify if the first char of the word is zero
int isFirstCharZero(word aux) {
    if ((strlen(aux.a) > 1 && aux.a[0] == '0') || (strlen(aux.b) > 1 && aux.b[0] == '0') || (strlen(aux.c) > 1 && aux.c[0] == '0')) {
        return 1;
    } else {
        return 0;
    }
}
// decrement the dictionary
int decrementTest(int dictionary[], word words, int letters, word *aux, char *output) {
    char auxWord[letters+1];
    word aux2;
    aux2.c[0] = '0';
    aux2.c[1] = '\0';
    int dictionaryAux[letters*2];
    int flag = 1;

    while(1) {
        for(int i = 0; i < letters; i++) {
            auxWord[i] = dictionary[letters+i];
        }
        auxWord[letters] = '\0';
        int integerAux = atoi(auxWord);
        integerAux--;
        if (integerAux < 0) {
            break;
        }
        memset(auxWord, '0', sizeof(auxWord));
        sprintf(auxWord + letters - snprintf(NULL, 0, "%d", integerAux), "%d", integerAux);
        for(int i = letters-1; i>=0; i--) {
            dictionary[letters+i] = auxWord[i];
        }
        attAux(words, aux, dictionary, letters);
        if(isFirstCharZero(*aux)) {
            continue;
        }
        if(testCase(*aux)) {
            flag = 0;
            int c = atoi(aux->c);
            int auxC = atoi(aux2.c);
            if(c >= auxC) {
                strcpy(aux2.a, aux->a);
                strcpy(aux2.b, aux->b);
                strcpy(aux2.c, aux->c);
                for(int i = 0; i<letters*2; i++) {
                    dictionaryAux[i] = dictionary[i];
                }
            }
        }
    }

    if (flag) {
        return 1;
    } else {
        printReport(aux2, dictionaryAux, letters, output);
        return 0;
    }
}
