#ifndef MAIN_EX1_H
#define MAIN_EX1_H
#endif

#ifndef INITIAL_ARRAY_SIZE
#define INITIAL_ARRAY_SIZE 10

#include "ex1_sort.h"
#include "utilities.h"

struct record* read_array(FILE *fp);

int compare_int(const void* r1_p,const void* r2_p);
int compare_string(const void* r1_p,const void* r2_p);
int compare_float(const void* r1_p,const void* r2_p);
int testCompareInt(const void *a, const void *b);
void testPerf(FILE *input);

#endif
