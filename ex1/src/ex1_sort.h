#ifndef EX1_SORT_H
#define EX1_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
static int binary_search(void *base, size_t size, int (*compar)(const void *, const void*), int val_pos);

void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void*));
void mergeSort(void *base, int left, int right, int k, size_t size, int (*compar)(const void *, const void*));

#endif