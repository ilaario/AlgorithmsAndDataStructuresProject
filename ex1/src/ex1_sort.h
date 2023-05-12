#ifndef EX1_SORT_H
#define EX1_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));

#endif