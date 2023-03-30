#ifndef MAIN_EX1_H
#define MAIN_EX1_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#ifndef STOP_COUNT
#define STOP_COUNT 1000000
#endif

#ifndef INITIAL_ARRAY_SIZE
#define INITIAL_ARRAY_SIZE 10

struct record {
    int id;
    char* str_f;
    int int_f;
    double float_f;
};

typedef struct _GenericArray {
    void **array;
    size_t n_el;
    size_t length;
}GenericArray;

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
static void read_array(const char* fp, GenericArray* ga);
static int compare_int(void* r1_p,void* r2_p);
static int compare_string(void* r1_p,void* r2_p);
static int compare_float(void* r1_p,void* r2_p);

//typedef struct _GenericArray GenericArray;
GenericArray* newGenericArray();
size_t sizeArr(void **a); //return the number of elements in the array
void* insertGA(void **a, void* new_el); //insert a new element in the array
void* updateIndexGA(void **a, void* new_el, unsigned long index); //update the element in the array at the given index
void* getGA(void **a, unsigned long index); //return the element in the array at the given index
int clearGA(GenericArray* ga); //reset all the array's elements to 0
int destroyGA(GenericArray* ga); //remove the array

#endif