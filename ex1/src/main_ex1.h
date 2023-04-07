#ifndef MAIN_EX1_H
#define MAIN_EX1_H
#endif

#ifndef INITIAL_ARRAY_SIZE
#define INITIAL_ARRAY_SIZE 10
#define STOP_COUNT 20000000

#include "ex1_sort.h"

struct record {
    int id;
    char* str_f;
    int int_f;
    double float_f;
};

unsigned int length_array;

struct record* read_array(const char* file_path);

int compare_int(const void* r1_p,const void* r2_p);
int compare_string(const void* r1_p,const void* r2_p);
int compare_float(const void* r1_p,const void* r2_p);
int testCompareInt(const void *a, const void *b);

int destroy_Rarr(struct record* ga); //remove the array

static void print_array(struct record *a, const char* file_path);

void testPerf(const char *input);

#endif
