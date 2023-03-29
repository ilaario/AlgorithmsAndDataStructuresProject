#include "GenericArray.h"

#ifndef INITIAL_ARRAY_SIZE
#define INITIAL_ARRAY_SIZE 10
#endif

GenericArray *newGenericArray() {
    GenericArray *ga = malloc(sizeof(GenericArray));                  // allocate memory for the struct
    if(ga == NULL){                                                   // check if the allocation was successful
        return NULL;
    }

    ga->array = malloc(sizeof(void*) * INITIAL_ARRAY_SIZE);           // allocate memory for the array
    if(ga->array == NULL){                                            // check if the allocation was successful   
        free(ga);                                                     // free the memory allocated for the struct    
        return NULL;
    }

    for(unsigned long i = 0; i < INITIAL_ARRAY_SIZE; i++){            // initialize the array
        ga -> array[i] = NULL;
    }

    ga -> n_el = 1;
    ga -> length = INITIAL_ARRAY_SIZE;
    return ga;
}

unsigned long sizeGA(GenericArray *ga) {                                        // return the number of elements in the array
    if(ga == NULL){
        exit(EXIT_FAILURE);
    }

    return ga -> n_el;
}

void *insertGA(GenericArray *ga, void* new_el){                       // insert a new element in the array
    if(ga == NULL){
        return NULL;
    }

    if(new_el == NULL){
        return NULL;
    }

    if(ga -> n_el >= ga -> length){
        ga -> array = realloc(ga -> array, sizeof(void*) * (ga -> length * 2));
        if(ga -> array == NULL){
            return NULL;
        }

        for(unsigned long i = ga -> length; i < ga -> length * 2; i++){
            ga -> array[i] = NULL;
        }

        ga -> length *= 2;
    }

    ga -> array[ga -> n_el] = new_el;
    ga -> n_el++;
    return (ga -> array[ga -> n_el - 1]);
}

void* updateIndexGA(GenericArray *ga, void *new_el, unsigned long index){ // update the element in the array at the given index
    if(ga == NULL){
        return NULL;
    }

    if(new_el == NULL){
        return NULL;
    }

    if(index < 0 || index >= ga -> n_el){
        return NULL;
    }

    ga -> array[index] = new_el;
    return (ga -> array[index]);
}

void* getGA(GenericArray *ga, unsigned long index){                     // return the element in the array at the given index
    if(ga == NULL){
        return NULL;
    }

    if(index < 0 || index >= ga -> n_el){
        return NULL;
    }

    return (ga -> array[index]);
}

int clearGA(GenericArray *ga){
    if(ga == NULL){
        exit(EXIT_FAILURE);
    }

    for(unsigned long i = 0; i < ga -> n_el; i++){
        free(ga -> array[i]);
        ga -> array[i] = NULL;
    }

    ga -> n_el = 0;
    return 1;
}

int destroyGA(GenericArray *ga){
    if(ga == NULL){
        exit(EXIT_FAILURE);
    }

    free(ga -> array);
    free(ga);
    return 1;
}



