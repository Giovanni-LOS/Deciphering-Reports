#include <string.h>
#include "../include/input.h"
#include "../include/initatt.h"

// initialize the histogram
void initHistogram(word words, int histogram[]) {

    int lenA = strlen(words.a);
    int lenB = strlen(words.b);
    int lenC = strlen(words.c);

    for(size_t i = 0; i<lenA; i++) {
        histogram[words.a[i]-'A'] = 1;
    }
    for(size_t i = 0; i<lenB; i++) {
        histogram[words.b[i]-'A'] = 1;
    }
    for(size_t i = 0; i<lenC; i++) {
        histogram[words.c[i]-'A'] = 1;
    }

}
// initialize the number of letters
void initLetters(int *letters, int histogram[]) {
    for(int i = 0; i<26; i++) {
        if(histogram[i]) {
            *letters += 1;
        }
    }
}
// initialize the dictionary
void initDictionary(int dictionary[], int histogram[], word words, int letters) {
    for(int i = 0; i<letters; i++) {
        for(int j = 0; j<26; j++) {
            if(histogram[j]==1) {
                histogram[j]++;
                dictionary[i] = j + 'A';
                dictionary[letters+i] = '9';
                break;
            }
        }
    }
}
// initialize the auxiliar word
void attAux(word words, word *aux, int dictionary[], int letters) {
    
    int lenA = strlen(words.a);
    int lenB = strlen(words.b);
    int lenC = strlen(words.c);

    for(int i = 0; i<lenA; i++) {
        for(int j = 0; j<letters; j++) {
            if(words.a[i] == dictionary[j]) {
                aux->a[i] = dictionary[letters+j];
            }
        }
        aux->a[lenA] = '\0';
    }

    for(int i = 0; i<lenB; i++) {
        for(int j = 0; j<letters; j++) {
            if(words.b[i] == dictionary[j]) {
                aux->b[i] = dictionary[letters+j];
            }
        }
        aux->b[lenB] = '\0';
    }

    for(int i = 0; i<lenC; i++) {
        for(int j = 0; j<letters; j++) {
            if(words.c[i] == dictionary[j]) {
                aux->c[i] = dictionary[letters+j];
            }
        }
        aux->c[lenC] = '\0';
    }
}
