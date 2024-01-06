#ifndef REPORT_INPUT_H
#define REPORT_INPUT_H

typedef struct word{
	char a[9];
	char b[9];
	char c[9];
} word;


void getWords(word *words, char *argv);
#endif // REPORT_INPUT_H

