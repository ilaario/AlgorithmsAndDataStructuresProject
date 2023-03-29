#ifndef GENERIC_ARRAY_H_adsnoiqpfmoa
#define GENERIC_ARRAY_H_adsnoiqpfmoa

typedef struct _GenericArray GenericArray;
GenericArray* newGenericArray();
unsigned long sizeGA(GenericArray* ga); //return the number of elements in the array
void* insertGA(GenericArray* ga, void* new_el); //insert a new element in the array
void* updateIndexGA(GenericArray* ga, void* new_el, unsigned long index); //update the element in the array at the given index
void* getGA(GenericArray* ga, unsigned long index); //return the element in the array at the given index
int clearGA(GenericArray* ga); //reset all the array's elements to 0
int destroyGA(GenericArray* ga); //remove the array

#endif