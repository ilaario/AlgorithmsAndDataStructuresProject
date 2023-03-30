#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define STOP_COUNT 1000000

#include "GenericArray.h"

struct record {
    int id;
    char* str_f;
    int int_f;
    double float_f;
};

/*
 send +                                     9*** +
 more =         m = 1  s = 9  o = 2         12** =
money                                      12***
*/


void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
void insertionSort(GenericArray *ga, size_t nitems, size_t size, int (*compar)(const void *, const void*));
void merge(int *base, int left, int mid, int right);
void mergeSort(int *base, int left, int right);
static void read_array(const char* fp, GenericArray* ga);

int main(int argc, char *argv[]){
    GenericArray *ga = newGenericArray();
    //printf("Array before sorting: ");
    for(int i = 0; i < 100000; i++){
        int *value;
        int v = rand();
        value = v;
        //printf("%d ", value);
        insertGA(ga, value);
    }
    printf("\n");
    printf("Array size: %d", ga -> n_el);
  /*
    if(argc < 2){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    } */
    clock_t begin = clock();
    insertionSort(ga, ga -> n_el, sizeof(int), NULL);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n");
    /*printf("Array after sorting: ");
    for(int i = 0; i < 10; i++){
        int *q = getGA(ga, i);
        printf("%d ", q);
    }*/
    printf("\n");
    printf("Time spent ordering the string's array: %fs\n", time_spent);
/*
    begin = clock();
    //sleep(2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent ordering the integer's array: %f\n", time_spent);

    begin = clock();
    //sleep(2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent ordering the floats's array: %f\n", time_spent);
*/
    return(EXIT_SUCCESS);
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
        //insertionSort(base, nitems, size, compar);
    }
}


static void read_array(const char* fp, GenericArray *ga){
    char *line;
    char buffer[1024];
    int buf_size = 1024, i = 0;
    FILE *file = fopen(fp, "r");
    printf("Reading data from %s\n", fp);
    if(fp == NULL){
        printf("main: Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, buf_size, fp) != NULL && i < STOP_COUNT){
        line = malloc((strlen(buffer) + 1) * sizeof(char));
        if(line == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(line, buffer);
        char *id_line = strtok(line, ",");
        char *string_line = strtok(NULL, ",");
        char *int_line = strtok(NULL, ",");
        char *float_line = strtok(NULL, ",");
        char *string_field = (malloc((strlen(string_line) + 1) * sizeof(char)));
        if(string_field == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(string_field, string_line);
        int int_field = atoi(int_line);
        double float_field = atof(float_line);
        struct record *r = malloc(sizeof(struct record));
        if(r == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        r -> id = atoi(id_line);
        r -> str_f = string_field;
        r -> int_f = int_field;
        r -> float_f = float_field;
        if(insertGA(ga, r) == NULL){
            fprintf(stderr, "main: Error inserting element in the array\n");
            exit(EXIT_FAILURE);
        }
        free(line);
        i++;
    }
    fclose(file);
    printf("Data read\n");
       
}

int cmp_void(const void *a, const void *b){
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return (*ia > *ib) - (*ia < *ib);
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


void merge(int *base, int left, int mid, int right){
    int i,j,k, div_1 = mid-left+1, div_2 = right-mid;  //nitems = 13: 1 2 3 4 5 6 7 8 9 10 11 12 13
    //creation of temp arrays
    int Left[div_1], Right[div_2]; 

    for(i=0;i<div_1;i++){
        Left[i]= base[left+i]; 
    }
    for(j=0;j<div_2;j++){
        Right[j]= base[mid+1+j];
    }

    i=0;  
    j=0;
    k=left;

    while(i<div_1 && j<div_2){
        if(Left[i]<=Right[j]){
            base[k]=Left[i];
            i++;
        }
        else {
            base[k]=Right[j];
            j++;
        }
        k++;
    }

    while (i < div_1) {
        base[k] = Left[i];
        i++;
        k++;
    }
 
    while (j < div_2) {
        base[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int *base, int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(base,left,mid);
        mergeSort(base,mid+1,right);
        merge(base,left,mid,right);
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