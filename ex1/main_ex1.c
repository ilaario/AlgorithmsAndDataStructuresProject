#include "main_ex1.h"

int main(int argc, char *argv[]){
    printf("/---------------- Insertion Sort su Int ----------------/\n");
    int arrSize = 10;
    int *arrayInt = malloc(arrSize * sizeof(int));
    printf("Array before sorting:\n");
    for(int i = 0; i < 10; i++){
        arrayInt[i] = rand() % 100;
    }
     for(int i = 0; i < 10; i++){
        printf("%d ", arrayInt[i]);
    }
    printf("\n");
    printf("Array size: %d\n", arrSize);
  /*
    if(argc < 2){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    } */
    clock_t begin = clock();
    insertionSort(arrayInt, arrSize, sizeof(int), compare_int);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Array after sorting: \n");
    for(int i = 0; i < 10; i++){
        printf("%d ", arrayInt[i]);
    }
    printf("\n");
    printf("Time spent ordering the int's array: %fs\n", time_spent);
/*
    begin = clock();
    //sleep(2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent ordering the integer's array: %f\n", time_spent);

*/
    printf("\n\n\n");
     printf("/--------------- Insertion Sort su Float ---------------/\n ");


    GenericArray *ga1 = newGenericArray();
    //printf("Array before sorting: ");
    srand(time(NULL));
    float *arrayFloat = malloc(10 * sizeof(float));
    for(int i = 0; i < 10; i++){
        arrayFloat[i] = (float)rand() / (float)(RAND_MAX / 100);
        printf("Valore nell'array: %f\n ", arrayFloat[i]);
    }

    ga1 -> array = arrayFloat;

    for(int i = 0; i < 10; i++){
        float *v2 = getGA(ga1, i);
        printf("Valore nell'array generico: %f\n ", v2);
    }
    printf("\n");
    printf("Array size: %d\n", ga1 -> n_el);
    begin = clock();
    insertionSort(ga1, ga1 -> n_el, sizeof(float), compare_int);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
       printf("Array after sorting: \n");
    for(int i = 0; i < 10; i++){
        float *v2 = getGA(ga1, i);
        printf("%f ", v2);
    }
    printf("\n");
    printf("Time spent ordering the floats's array: %fs\n", time_spent);

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

void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    int i,j;
    void *curr_val = malloc(size);
    for(i = 1; i < nitems; i++){
        memcpy(curr_val, base + (i * size), size);
        j = i-1;
        while(j >= 0 && compar(base + (j * size), curr_val) > 0){
            memcpy(base + ((j + 1) * size), base + (j * size), size);
            j-=1;
        }
        memcpy(base + ((j + 1) * size), curr_val, size);
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

// Function that implements the precedence relation between integers
static int compare_int(void* r1_p,void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"compare_int: the first parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_int: the second parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    struct record *rec1_p = (struct record*)r1_p;
    struct record *rec2_p = (struct record*)r2_p;
    if(rec1_p->int_f > rec2_p->int_f){
        return(1);
    } else if(rec1_p->int_f < rec2_p->int_f){
        return(-1);
    }
    return(0);
}

// Function that implements the precedence relation between strings
static int compare_string(void* r1_p,void* r2_p){
    if(r1_p == NULL){
        fprintf(stderr,"compare_string: the first parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_string: the second parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    struct record *rec1_p = (struct record*)r1_p;
    struct record *rec2_p = (struct record*)r2_p;
    if (strcasecmp(rec1_p->str_f,rec2_p->str_f) <= 0){
        return(1);
    }
    return(0);
}

// Function that implements the precedence relation between float
static int compare_float(void* r1_p, void* r2_p) {
    if(r1_p == NULL){
        fprintf(stderr,"compare_float: the first parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    if(r2_p == NULL){
        fprintf(stderr,"compare_float: the second parameter cannot be NULL");
        exit(EXIT_FAILURE);
    }
    struct record *rec1_p = (struct record*)r1_p;
    struct record *rec2_p = (struct record*)r2_p;
    if (rec1_p->float_f <= rec2_p->float_f){
        return(1);
    }
    return(0);
}


//Method that create the array
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

    ga -> n_el = 0;
    ga -> length = INITIAL_ARRAY_SIZE;
    return ga;
}

//Method that return the size of the array
size_t sizeArr(void **a) {                              // return the number of elements in the array
    if(a == NULL){
        exit(EXIT_FAILURE);
    }

    return sizeof(a)/sizeof(a[0]);
}

void *insertGA(void **a, void* new_el){                                // insert a new element in the array
    if(a == NULL){
        return NULL;
    }

    if(new_el == NULL){
        return NULL;
    }

    if(sizeArr(a) >= sizeArr(a) - 1){
        a = realloc(a, sizeof(void*) * (sizeArr(a) * 2));
        if(a == NULL){
            return NULL;
        }

        for(unsigned long i = sizeArr(a); i < sizeArr(a) * 2; i++){
            a[i] = NULL;
        }
    }

    a[sizeArr(a)] = new_el;
    return (a[sizeArr(a) - 1]);
}

void* updateIndexGA(void **a, void *new_el, unsigned long index){ // update the element in the array at the given index
    if(a == NULL){
        return NULL;
    }

    if(new_el == NULL){
        return NULL;
    }

    if(index < 0 || index >= sizeArr(a) - 1){
        return NULL;
    }

    a[index] = new_el;
    return (a[index]);
}

void* getGA(void **a, unsigned long index){                     // return the element in the array at the given index
    if(a == NULL){
        return NULL;
    }

    if(index < 0 || index >= sizeArr(a)){
        return NULL;
    }

    return (a[index]);
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