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
static void read_array(const char* fp, GenericArray* ga);

int main(int argc, char *argv[]){
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
    if(argc < 2){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    }
    clock_t begin = clock();
    //sleep(2);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent ordering the string's array: %f\n", time_spent);

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