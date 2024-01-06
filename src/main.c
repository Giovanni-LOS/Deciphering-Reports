#include "../include/input.h"
#include "../include/initatt.h"
#include "../include/process.h"
#include "../include/error.h"
#include "../include/output.h"

int main(int argc, char *argv[]) {
    // verify if the number of arguments is correct
    argvError(argc);

    word words;
    word aux;
    int histogram[26] = {0};
    int letters = 0;
    // get the words from the file
    getWords(&words, argv[1]);
    // initialize the histogram
    initHistogram(words, histogram);
    // initialize the number of letters
    initLetters(&letters, histogram);

    int dictionary[letters*2];
    // initialize the dictionary
    initDictionary(dictionary, histogram, words, letters);
    // initialize the auxiliar word
    attAux(words, &aux, dictionary, letters);
    // process the words
    if(decrementTest(dictionary, words, letters, &aux, argv[2])) {
        fail(argv[2]);
    }
    return 0;
}
