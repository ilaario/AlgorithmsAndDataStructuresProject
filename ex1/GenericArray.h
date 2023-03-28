#ifndef GENERIC_ARRAY_H_adsnoiqpfmoa
#define GENERIC_ARRAY_H_adsnoiqpfmoa

typedef struct _GenericArray GenericArray;
GenericArray* newGenericArray();
unsigned long sizeGA(GenericArray* ga);
void* insertGA(GenericArray* ga, void* new_el);
void* updateIndexGA(GenericArray* ga, void* new_el, unsigned long index);
void* getGA(GenericArray* ga, unsigned long index);
int clearGA(GenericArray* ga);
int destroyGA(GenericArray* ga);

#endif