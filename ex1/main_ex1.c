#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GenericArray.h"

void merge_binary_insertion_sort(void **base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
void insertionSort(GenericArray *ga, size_t nitems, size_t size, int (*compar)(const void *, const void*));

int main(int argc, char *argv[]){
    //merge_binary_insertion_sort(NULL, 0, 0, atoi(argv[1]), NULL);
    GenericArray *ga = newGenericArray();
    for(int i = 0; i < 10; i++){
        int *value;
        int v = rand()%10;
        value = v;
        printf("Inserted item: %d\nNumber of elements in ga: %d\n", value, ga -> n_el);
        insertGA(ga, value);
    }
    printf("\n");
    printf("Array size: %d", ga -> n_el);
    printf("\n");
    printf("Array after sorting: ");

    insertionSort(ga, 10, sizeof(int), NULL);

    for(int i = 0; i < 10; i++){
        int *q = getGA(ga, i);
        printf("%d ", q);
    }
    printf("\n");
}

void merge_binary_insertion_sort(void **base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    if(nitems > k){
        printf("Merge sort\n");
        //mergeSort(base, nitems, size, compar);
    }
    else{
        printf("Insertion sort\n");
        //insertionSort(base, nitems, size, compar);
    }
}

void insertionSort(GenericArray *ga, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    int i,j;
    void *curr_val;
    for(i = 1; i < nitems; i++){
        curr_val = getGA(ga,i);
        j = i-1;
        while(j >= 0 && getGA(ga,j) > curr_val){
            updateIndexGA(ga, getGA(ga, j) , j + 1);
            j-=1;
        }
        updateIndexGA(ga, curr_val, j+1);
    }
}

/*void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    int i,j;
    void *curr_val;
    for(i=1; i<=nitems; i++){
        curr_val = base[i];
        j = i-1;
        while(j>=0 && getGA(base,j)>curr_val){
            updateIndexGA(base,j+1,j);
            j=j-1;
        }
        updateIndexGA(base,j+1,curr_val);
    }
}
*/