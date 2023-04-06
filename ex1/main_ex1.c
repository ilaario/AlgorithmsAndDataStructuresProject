#include "main_ex1.h"

unsigned int length_array;

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    }

    /* SORTING SU INTEGERS */
    printf("\nMerge Sort su Integers\n");
    void *read_int = read_array(argv[1]);
    printf("Array before sorting:\n");
    printf("Array size: %u\n", length_array);
    printf("Sorting the Array...\n");
    clock_t begin = clock();
    //insertionSort(read_int, length_array, sizeof(struct record), compare_int);
    mergeSort(read_int, 0, length_array - 1, sizeof(struct record), compare_int);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    if(time_spent > 60){
        int min = time_spent / 60;
        int sec = time_spent - (min * 60);
        printf("Time spent ordering the int's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
    } else {
        printf("Time spent ordering the int's array: %fs\n", time_spent);
    }
    free(read_int);

    /* SORTING SU FLOAT */
    printf("\n\nMerge Sort su Floats\n");
    void *read_float = read_array(argv[1]);
    printf("Array before sorting:\n");
    printf("Array size: %u\n", length_array);
    printf("Sorting the Array...\n");
    begin = clock();
    //insertionSort(read_float, length_array, sizeof(struct record), compare_int);
    mergeSort(read_float, 0, length_array - 1, sizeof(struct record), compare_float);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    if(time_spent > 60){
        int min = time_spent / 60;
        int sec = time_spent - (min * 60);
        printf("Time spent ordering the float's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
    } else {
        printf("Time spent ordering the float's array: %fs\n", time_spent);
    }
    free(read_float);

    /* SORTING SU STRING */
    printf("\n\nMerge Sort su String\n");
    void *read_string = read_array(argv[1]);
    printf("Array before sorting:\n");
    printf("Array size: %u\n", length_array);
    printf("Sorting the Array...\n");
    begin = clock();
    //insertionSort(read_string, lenght_array, sizeof(struct record), compare_string);
    mergeSort(read_string, 0, length_array - 1, sizeof(struct record), compare_string);
    end = clock();
    time_spent = ((double)(end - begin)) / CLOCKS_PER_SEC;
    if(time_spent > 60){
        int min = time_spent / 60;
        int sec = time_spent - (min * 60);
        printf("Time spent ordering the string's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
    } else {
        printf("Time spent ordering the string's array: %fs\n", time_spent);
    }
    free(read_string);

    return(EXIT_SUCCESS);
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){

}



void* read_array(const char* file_path){
    clock_t begin_read = clock();
    struct record *this_record = malloc(sizeof(struct record));
    unsigned int i = 0;
    char *read_line_p, *string_tmp, buffer[1024];
    int buff_size = 1024;
    void *array_to_sort;
    FILE *fp;
    length_array = 1000;

    printf("Reading data from %s\n", file_path);
    fp = fopen(file_path, "r");

    if(fp == NULL){
        fprintf(stderr, "main: Error opening file\n");
        exit(EXIT_FAILURE);
    }
    array_to_sort = malloc(length_array * sizeof(struct record));

    while ((fgets(buffer, buff_size, fp) != NULL) && (i < STOP_COUNT)){
        if(length_array == i){
            length_array *= 2;
            array_to_sort = realloc(array_to_sort, length_array * sizeof(struct record));
        }

        read_line_p = malloc((strlen(buffer) + 1) * sizeof(char));
        if(read_line_p == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(read_line_p, buffer);
        if(this_record == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
            //printf("read_line_p:\n");
        this_record -> id = atoi(strtok(read_line_p, ","));
            //printf("\tread_line_p -> id: %d\n", this_record -> id);
        string_tmp = strtok(NULL, ",");
        this_record -> str_f = malloc((strlen(string_tmp) + 1) * sizeof(char));
        strcpy(this_record -> str_f, string_tmp);
            //printf("\tread_line_p -> str_f: %s\n", this_record -> str_f);
        this_record -> int_f = atoi(strtok(NULL, ","));
            //printf("\tread_line_p -> int_f: %d\n", this_record -> int_f);
        this_record -> float_f = atof(strtok(NULL, ","));
            //printf("\tread_line_p -> float_f: %f\n\n", this_record -> float_f);

        if(this_record -> str_f == NULL){
            fprintf(stderr, "main: Error allocating memory\n");
            exit(EXIT_FAILURE);
        }
        
        memcpy(array_to_sort + (i * sizeof(struct record)), this_record, sizeof(struct record));
        //struct record *tmp = malloc(sizeof(struct record));
        //memcpy(tmp, array_to_sort + (i * sizeof(struct record)), sizeof(struct record));
        //printf("Record %d read\n < %d, %s, %d, %f >\n\n", i, tmp -> id, tmp -> str_f, tmp -> int_f, tmp -> float_f);
        i++;
    }
    fclose(fp);
    free(this_record);
    length_array = (unsigned int) i;
    clock_t end_read = clock();
    double time_spent_read = (double)(end_read - begin_read) / CLOCKS_PER_SEC;
    printf("Read of the file ended, allocated %d records, reading time = %fs\n", length_array, time_spent_read);
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


void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void*)){
    int i,j,k, div_1 = mid-left+1, div_2 = right-mid;  //nitems = 13: 1 2 3 4 5 6 7 8 9 10 11 12 13
    //creation of temp arrays
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
}

void mergeSort(void *base, int left, int right, size_t size, int (*compar)(const void *, const void*)){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(base, left, mid, size, compar);
        mergeSort(base, mid + 1, right, size, compar);
        merge(base, left, mid, right, size, compar);
    }
}



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

static int testCompareInt(const void *r1, const void *r2){
    int *a = (int*) r1;
    int *b = (int*) r2;
    return *a - *b;
}

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
    return(strcmp(rec1_p->str_f, rec2_p->str_f));
}



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

    /*for(unsigned long i = 0; i < INITIAL_ARRAY_SIZE; i++){            // initialize the array
        printf("Assegnamento valore NULL all'indice %lu...\n", i);
        void *tmp = NULL;
        memcpy(ga -> array + (i * sizeof(void*)), NULL, sizeof(void*));
    }*/

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

void print_array(void *a){
    int el_num = length_array;
    struct record *array_element = (struct record*)malloc(sizeof(struct record));
    for(int i = 0;i < length_array;i++){
        memcpy(array_element, a + (i * sizeof(struct record)), sizeof(struct record));
        printf("<%d, %s, %d, %lf>\n", array_element->id, array_element->str_f, array_element->int_f, array_element->float_f);
    }
}
