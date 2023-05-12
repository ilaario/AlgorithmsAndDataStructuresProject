#include "ex1_sort.h"

static int binary_search(void *base, size_t size, int (*compar)(const void *, const void*), int val_pos){
    char *arr = (char *)base;
    int low = 0, high = val_pos - 1, mid;
    while(low <= high){
        mid = low + (high - low) / 2;
        int cmp_result = compar(arr + (val_pos * size), arr + (mid * size));
        if(cmp_result == 0){
            return mid + 1;
        }
        else if(cmp_result > 0){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

static void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    int i,j;
    char *curr_val = malloc(size);
    for(i = 0; i < nitems; i++){
        j = i;
        memcpy(curr_val, base + (i * size), size);
        int pos = binary_search(base, size, compar, i);
        while(j > pos){
            memcpy(base + ((j) * size), base + ((j - 1) * size), size);
            j--;
        }
        memcpy(base + ((pos) * size), curr_val, size);
    }
    free(curr_val);
}

static void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void*)){
    int i,j,k, div_1 = mid-left+1, div_2 = right-mid;  
    void *left_arr = malloc(div_1 * size);
    void *right_arr = malloc(div_2 * size);
    

    for(i=0;i<div_1;i++){
        memcpy(left_arr + (i * size), base + ((left + i) * size), size);
    }
    for(j=0;j<div_2;j++){
        memcpy(right_arr + (j * size), base + ((mid + 1 + j) * size), size);
    }

    i = 0;  
    j = 0;
    k = left;

    while(i < div_1 && j < div_2){
        if(compar(left_arr + (i * size), right_arr + (j * size)) <= 0){
            memcpy(base + (k * size), left_arr + (i * size), size);
            i++;
        }
        else{
            memcpy(base + (k * size), right_arr + (j * size), size);
            j++;
        }
        k++;
    }

    while (i < div_1) {
        memcpy(base + (k * size), left_arr + (i * size), size);
        i++;
        k++;
    }
 
    while (j < div_2) {
        memcpy(base + (k * size), right_arr + (j * size), size);
        j++;
        k++;
    }

    free(left_arr);
    free(right_arr);
}

static void mergeSort(void *base, int left, int right, int k, size_t size, int (*compar)(const void *, const void*)){
    if((right - left) <= k){
        insertionSort(base + (left * size), right - left + 1, size, compar);
        return;
    } else if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(base, left, mid, k, size, compar);
        mergeSort(base, mid + 1, right, k, size, compar);
        merge(base, left, mid, right, size, compar);
    }
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    mergeSort(base, 0, nitems - 1, k, size, compar);
    return;
}