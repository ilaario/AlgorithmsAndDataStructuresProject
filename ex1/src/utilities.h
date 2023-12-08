#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define STOP_COUNT 20000000

struct record {
    int id;
    char* str_f;
    int int_f;
    double float_f;
};

unsigned int length_array;

struct record* read_array(FILE* fp);
int destroy_Rarr(struct record* ga);
void print_array(struct record *a, FILE* fp);


#endif