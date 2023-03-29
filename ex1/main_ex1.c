#include <stdio.h>

#include "GenericArray.h"

void merge_binary_insertion_sort(void **base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
void insertionSort(void **base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
struct _GenericArray *ar;
int main(int argc, char *argv[]){
    //merge_binary_insertion_sort(NULL, 0, 0, atoi(argv[1]), NULL);
    GenericArray *ga = newGenericArray();
    for(int i = 1; i <= 10; i++){
        insertGA(ga, i);
    }

    insertionSort(ga -> array ,);
}

void merge_binary_insertion_sort(void **base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    if(nitems > k){
        printf("Merge sort\n");
        //mergeSort(base, nitems, size, compar);
    }
    else{
        printf("Insertion sort\n");
        insertionSort(base, nitems, size, compar);
    }
}

void insertionSort(void **base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    int i,j;
    void *k;
    void *curr_val;
    for(i=1; i<=nitems; i++){
        curr_val = getGA(base,i);
        j = i-1;
        k = &j;
        while(j>=0 && getGA(base,j)>curr_val){
            updateIndexGA(base,j+1,j);
            j=j-1;
        }
        updateIndexGA(base,j+1,curr_val);
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