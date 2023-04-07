#include "main_ex1.h"

unsigned int length_array;

int main(int argc, char *argv[]){
    if(argc < 4){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    }

    /* SORTING SU INTEGERS */
    int k = atoi(argv[3]);
    int type = atoi(argv[4]);

    if(type == 2){
        printf("\nMerge Binary Insertion Sort su Integers\n");
        struct record *read_int = read_array(argv[1]);
        printf("Array before sorting:\n");
        printf("Array size: %u\n", length_array);
        printf("Sorting the Array...\n");
        clock_t begin = clock();
        merge_binary_insertion_sort(read_int, length_array, sizeof(struct record), 100, compare_int);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        if(time_spent > 60){
            int min = time_spent / 60;
            int sec = time_spent - (min * 60);
            printf("Time spent ordering the int's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
        } else {
            printf("Time spent ordering the int's array: %fs\n", time_spent);
        }
        print_array(read_int, argv[2]);
        destroy_Rarr(read_int);
    } else if (type == 3){
            /* SORTING SU FLOAT */
        printf("\n\nMerge Binary Insertion Sort su Floats\n");
        struct record *read_float = read_array(argv[1]);
        printf("Array before sorting:\n");
        printf("Array size: %u\n", length_array);
        printf("Sorting the Array...\n");
        clock_t begin = clock();
        merge_binary_insertion_sort(read_float, length_array, sizeof(struct record), 100, compare_float);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        if(time_spent > 60){
            int min = time_spent / 60;
            int sec = time_spent - (min * 60);
            printf("Time spent ordering the float's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
        } else {
            printf("Time spent ordering the float's array: %fs\n", time_spent);
        }
        print_array(read_float, argv[2]);
        destroy_Rarr(read_float);
    } else if(type == 1) {
        printf("\n\nMerge Binary Insertion Sort su String\n");
        struct record *read_string = read_array(argv[1]);
        printf("Array before sorting:\n");
        printf("Array size: %u\n", length_array);
        printf("Sorting the Array...\n");
        clock_t begin = clock();
        merge_binary_insertion_sort(read_string, length_array, sizeof(struct record), 100, compare_string);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        if(time_spent > 60){
            int min = time_spent / 60;
            int sec = time_spent - (min * 60);
            printf("Time spent ordering the string's array: %dmin and %ds (%fs)\n", min, sec, time_spent);
        } else {
            printf("Time spent ordering the string's array: %fs\n", time_spent);
        }
        print_array(read_string, argv[2]);
        destroy_Rarr(read_string);
    } else {
        printf("main: Error, wrong argument\n");
        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);
}

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    mergeSort(base, 0, nitems - 1, k, size, compar);
    return;
}



struct record* read_array(const char* file_path){
    clock_t begin_read = clock();
    unsigned int i = 0;
    char *read_line_p, *string_tmp, buffer[1024];
    int buff_size = 1024;
    struct record *array_to_sort;
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
        array_to_sort[i].id = atoi(strtok(read_line_p, ","));
        string_tmp = strtok(NULL, ",");
        char* str = malloc((strlen(string_tmp) + 1) * sizeof(char));
        strcpy(str, string_tmp);
        array_to_sort[i].str_f = str;
        array_to_sort[i].int_f = atoi(strtok(NULL, ","));
        array_to_sort[i].float_f = atof(strtok(NULL, ","));
        i++;
        free(read_line_p);
    }
    fclose(fp);
    length_array = (unsigned int) i;
    clock_t end_read = clock();
    double time_spent_read = (double)(end_read - begin_read) / CLOCKS_PER_SEC;
    printf("Read of the file ended, allocated %d records, reading time = %fs\n", length_array, time_spent_read);
    return array_to_sort;
}

void insertionSort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){
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

    free(left_arr);
    free(right_arr);
}

void mergeSort(void *base, int left, int right, int k, size_t size, int (*compar)(const void *, const void*)){
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
    return(-1);
}

int destroy_Rarr(struct record *ga){
    if(ga == NULL){
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < length_array; i++){
        free(ga[i].str_f);
    }
    
    free(ga);
    return 1;
}

void print_array(struct record *a, const char* file_path){
    printf("Printing array to file %s, please wait...\n", file_path);
    clock_t start = clock();
    FILE *fp = fopen(file_path, "w");
    if(fp == NULL){
        fprintf(stderr, "Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "id, str_f, int_f, float_f\n");
    for(int i=0;i<length_array;i++){
        fprintf(fp, "%d, %s, %d, %f\n", a[i].id, a[i].str_f, a[i].int_f, a[i].float_f);
    }
    fclose(fp);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Done in %fs!\n", time_spent);
}
