#include "main_ex1.h"

unsigned int length_array;

int main(int argc, char *argv[]){

    /*
    printf("\n\n\n\n");
    printf("/---------------- Insertion Sort su Int ----------------/\n");
   srand(time(NULL));
    int arrSize = 10;
    int *arrayInt = malloc(arrSize * sizeof(int));
    //printf("Array before sorting:\n");
    for(int i = 0; i < arrSize; i++){
        arrayInt[i] = (int)(rand() % arrSize);
    }
    for(int i = 0; i < arrSize; i++){
        printf("%d ", arrayInt[i]);
    }
    printf("\n");
    printf("Array size: %d\n", arrSize);*/

    if(argc < 2){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    }

    /* SORTING SU INTEGERS */
    GenericArray* ga = newGenericArray();
    memcpy(ga -> array, read_array(argv[1]), sizeof(struct record) * length_array);
    printf("Array size: %u\n", length_array);
    ga -> n_el = length_array;
    ga -> length = length_array + 1; 

    printf("Array before sorting: \n");
    printf("Array size: %zu\n", ga -> n_el);
    printf("Array length: %zu\n", ga -> length);

    for (size_t i = 0; i < ga -> n_el; i++){
        struct record *tmp = (struct record *)(ga -> array + (i * sizeof(struct record)));
        printf("< ");
        printf("%d, ", tmp -> id);
        printf("%d, ", tmp -> int_f);
        printf("%s, ", tmp -> str_f);
        printf("%f, ", tmp -> float_f);
        printf(">\n");
    }
    

    printf("Sorting the Array...\n");
    clock_t begin = clock();
    insertionSort(ga -> array, ga -> n_el, sizeof(struct record), compare_int);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    /*
    printf("Array after sorting: \n");
    for(int i = 0; i < arrSize; i++){
        printf("%d ", arrayInt[i]);
    }
    printf("\n");
    */
    print_array(ga);
    if(time_spent > 60){
        int min = time_spent / 60;
        int sec = time_spent - (min * 60);
        printf("Time spent ordering the int's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
    } else {
        printf("Time spent ordering the int's array: %fs\n", time_spent);
    }
    destroyGA(ga);

    /* SORTING SU FLOAT */
    GenericArray *ga2 = newGenericArray();
    memcpy(ga2 -> array, read_array(argv[1]), sizeof(struct record) * length_array);

    printf("Sorting the Array...\n");
    begin = clock();
    insertionSort(ga2 -> array, ga2 -> n_el, sizeof(struct record), compare_float);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    print_array(ga2);
    if(time_spent > 60){
        int min = time_spent / 60;
        int sec = time_spent - (min * 60);
        printf("Time spent ordering the int's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
    } else {
        printf("Time spent ordering the int's array: %fs\n", time_spent);
    }
    destroyGA(ga2);

    /* SORTING SU STRING */
    GenericArray *ga3 = newGenericArray();
    memcpy(ga3 -> array, read_array(argv[1]), sizeof(struct record) * length_array);

    printf("Sorting the Array...\n");
    begin = clock();
    insertionSort(ga3 -> array, ga3 -> n_el, sizeof(struct record), compare_string);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    /*
    printf("Array after sorting: \n");
    for(int i = 0; i < arrSize; i++){
        printf("%s ", arrayString[i]);
    }
    printf("\n");
    */
    print_array(ga3);
    if(time_spent > 60){
        int min = time_spent / 60;
        int sec = time_spent - (min * 60);
        printf("Time spent ordering the int's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
    } else {
        printf("Time spent ordering the int's array: %fs\n", time_spent);
    }

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


void** read_array(const char* file_path){
    struct record *this_record;
    unsigned int i = 0;
    char *read_line_p, *string_tmp, buffer[1024];
    int buff_size = 1024;
    void **array_to_sort;
    FILE *fp;
    length_array = 1000;

    printf("Reading data from %s\n", file_path);
    fp = fopen(file_path, "r");

    if(fp == NULL){
        fprintf(stderr, "main: Error opening file\n");
        exit(EXIT_FAILURE);
    }
    array_to_sort = malloc(length_array * sizeof(void*));

    while ((fgets(buffer, buff_size, fp) != NULL) && (i < STOP_COUNT)){
        if(length_array == i){
            length_array *= 2;
            array_to_sort = realloc(array_to_sort, length_array * sizeof(void*));
        }

        read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
        if(read_line_p == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(read_line_p, buffer);

        this_record = malloc(sizeof(struct record));
        if(this_record == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }

        this_record -> id = atoi(strtok(read_line_p, ","));
        string_tmp = strtok(NULL, ",");
        this_record -> str_f = malloc((strlen(string_tmp) + 1) * sizeof(char));
        strcpy(this_record -> str_f, string_tmp);
        this_record -> int_f = atoi(strtok(NULL, ","));
        this_record -> float_f = atof(strtok(NULL, ","));

        if(this_record -> str_f == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }

        array_to_sort[i] = (void*)this_record;
        free(read_line_p);
        i++;
    }
    fclose(fp);
    length_array = (unsigned int) i;
    printf("Read of the file ended, allocated %d records\n", length_array);
    return array_to_sort;
}

void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
    int i,j;
    char *curr_val = malloc(size);
    printf("Insertion sort\n");
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

static int binary_search(void *base, size_t size, int (*compar)(const void *, const void*), int val_pos){
    char *arr = (char *)base;
    int low = 0, high = val_pos - 1, mid;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(compar(arr + (val_pos * size), arr + (mid * size)) == 0){
            return mid + 1;
        }
        else if(compar(arr + (val_pos * size), arr + (mid * size)) > 0){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
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
static int compare_int(const void* r1_p,const void* r2_p){
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


/* static int testCompareInt(void* p1, void *p2){
    int *rec1_p = (int*)p1;
    int *rec2_p = (int*)p2;
    return *rec1_p - *rec2_p;
} */

// Function that implements the precedence relation between strings
static int compare_string(const void* r1_p,const void* r2_p){
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

/* static int testCompareString(void* p1, void* p2){
    char *rec1_p = (char*)p1;
    puts(*rec1_p);
    char *rec2_p = (char*)p2;
    puts(*rec2_p);
    return strcmp(rec1_p, rec2_p);
} */

// Function that implements the precedence relation between float
static int compare_float(const void* r1_p, const void* r2_p) {
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

/* static int testCompareFloat(void* p1, void* p2){
    float *rec1_p = (float*)p1;
    float *rec2_p = (float*)p2;
    if (*rec1_p < *rec2_p){
        return(-1);
    } else if (*rec1_p > *rec2_p){
        return(1);
    } else {
        return(0);
    }
} */


//Method that create the array
GenericArray *newGenericArray() {
    printf("Generazione Generic Array...\n");
    GenericArray *ga = (GenericArray *)malloc(sizeof(GenericArray));                  // allocate memory for the struct
    if(ga == NULL){                                                   // check if the allocation was successful
        return NULL;
    } else {
        printf("Generic Array allocato con successo!\n");
    }

    ga->array = (void*)malloc(sizeof(void*) * INITIAL_ARRAY_SIZE);           // allocate memory for the array
    if(ga->array == NULL){                                            // check if the allocation was successful   
        free(ga);                                                     // free the memory allocated for the struct    
        return NULL;
    } else {
        printf("Array allocato con successo!\n");
    }

    for(unsigned long i = 0; i < INITIAL_ARRAY_SIZE; i++){            // initialize the array
        printf("Assegnamento valore NULL all'indice %lu...\n", i);
        void *tmp = NULL;
        memcpy(ga -> array + (i * sizeof(void*)), tmp, sizeof(void*));
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

void *insertGA(GenericArray *ga, void* new_el){                                // insert a new element in the array
    if(ga == NULL){
        return NULL;
    }

    if(new_el == NULL){
        return NULL;
    }

    if( ga -> n_el + 1 >= ga -> length){                                       // if the array is full, double its size
        ga -> array = realloc(ga -> array, sizeof(void*) * (sizeArr(ga -> array) * 2));
        if(ga -> array == NULL){
            return NULL;
        }

        for(unsigned long i = sizeArr(ga -> array); i < sizeArr(ga -> array) * 2; i++){
            memcpy(ga -> array + (i * sizeof(void*)), NULL, sizeof(void*));
        }

        ga -> length = sizeArr(ga -> array) * 2;
    }

    memcpy(ga -> array + (sizeArr(ga -> array) * sizeof(void*)), new_el, sizeof(void*));
    return (ga -> array + (sizeArr(ga -> array) * sizeof(void*)));
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
        free(ga -> array + (i * sizeof(void*)));
        memcpy(ga -> array + (i * sizeof(void*)), NULL, sizeof(void*));
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

void print_array(GenericArray *ga){
    int el_num = sizeArr(ga -> array);
    struct record *array_element = malloc(sizeof(struct record));
    memcpy(array_element, ga -> array, el_num);

    printf("\nORDERED ARRAY OF RECORDS\n");
    for(int i = 0;i < sizeArr(ga -> array);i++){
        printf("PORCODIO\n");
        memcpy(array_element, ga -> array + (i * sizeof(void*)), sizeof(struct record));
        printf("<%d, %s , %d , %lf>\n", array_element->id, array_element->str_f, array_element->int_f, array_element->float_f);
    }
}