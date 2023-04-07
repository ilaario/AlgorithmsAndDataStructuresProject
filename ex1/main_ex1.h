#ifndef MAIN_EX1_H
#define MAIN_EX1_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#ifndef INITIAL_ARRAY_SIZE
#define INITIAL_ARRAY_SIZE 10
#define STOP_COUNT 20000000

#include "ex1_test.h"

struct record {
    int id;
    char* str_f;
    int int_f;
    double float_f;
};

unsigned int length_array;

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
static int binary_search(void *base, size_t size, int (*compar)(const void *, const void*), int val_pos);

void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void*));
void mergeSort(void *base, int left, int right, int k, size_t size, int (*compar)(const void *, const void*));

struct record* read_array(const char* file_path);

int compare_int(const void* r1_p,const void* r2_p);
static int testCompareInt(const void *r1, const void *r2);

int compare_string(const void* r1_p,const void* r2_p);
static int testCompareString(void *p1, void *p2);

int compare_float(const void* r1_p,const void* r2_p);
static int testCompareFloat(void *p1, void *p2);

int destroy_Rarr(struct record* ga); //remove the array

static void print_array(struct record *a, const char* file_path);

#endif
