//
// Created by Giovanni on 12/6/23.
//

#include "../include/error.h"
#include <stdlib.h>
#include <stdio.h>

// verify if the number of arguments is correct
void argvError(int argc) {
    if(argc != 3) {
        printf("Invalid number of arguments.\nUsage is ./main <input> <output>\n");
        exit(1);
    }
}
// verify if the file was opened/created
void fileError(FILE* file) {
    if(file == NULL) {
        printf("Fail to open/create the file.\n");
        exit(1);
    }
}