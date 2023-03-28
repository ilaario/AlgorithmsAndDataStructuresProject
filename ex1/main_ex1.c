#include <stdio.h>

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

int main(int argc, char *argv[]){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(a)/sizeof(a[0]);
    int size = sizeof(a[0]);
    merge_binary_insertion_sort(a, len, size, 5, cmp_void(0, len - 1));
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    // divisione dell'array in due parti tramite merge sort, fino a quando lunghezza array <= k
    // si inizia a ordinare il nuovo array
    // se la lunghezza dell'array è maggiore di k, allora si applica merge sort
    // altrimenti si applica insertion sort


    if(nitems > k){
        printf("Merge sort\n");
        
    }
    else{
        printf("Insertion sort\n");
        insertionSort(base, nitems, size, compar);
    }
}

int cmp_void(const void *a, const void *b){
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return (*ia > *ib) - (*ia < *ib);
}