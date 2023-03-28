#include <stdio.h>

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));



int main(int argc, char *argv[]){
    merge_binary_insertion_sort(NULL, 0, 0, atoi(argv[1]), NULL);
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    if(nitems > k){
        printf("Merge sort\n");
        mergeSort(base, nitems, size, compar);
    }
    else{
        printf("Insertion sort\n");
        insertionSort(base, nitems, size, compar);
    }
}

void insertionSort(int *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    int i,j,curr_val;
    for(i=1; i<=nitems; i++){
        curr_val = base[i];
        j = i-1;
        while(j>=0 && base[j]>curr_val){
            base[j+1]=base[j];
            j=j-1;
        }
        base[j+1]=curr_val;
    }
}
