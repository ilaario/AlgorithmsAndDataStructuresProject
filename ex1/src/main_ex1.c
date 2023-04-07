#include "main_ex1.h"

int main(int argc, char *argv[]){
    if(argc < 4){
        printf("main: Error, missing arguments\n");
        exit(EXIT_FAILURE);
    }

    int type = atoi(argv[4]);

    if(type == 4){
        testPerf(argv[1]);
    } else {
        int k = atoi(argv[3]);
        int type = atoi(argv[4]);
        if(type == 2){
            printf("\nMerge Binary Insertion Sort su Integers\n");
            struct record *read_int = read_array(argv[1]);
            printf("Array before sorting:\n");
            printf("Array size: %u\n", length_array);
            printf("Sorting the Array...\n");
            clock_t begin = clock();
            merge_binary_insertion_sort(read_int, length_array, sizeof(struct record), k, compare_int);
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
            merge_binary_insertion_sort(read_float, length_array, sizeof(struct record), k, compare_float);
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
            merge_binary_insertion_sort(read_string, length_array, sizeof(struct record), k, compare_string);
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
    }
    return(EXIT_SUCCESS);
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


// Function that implements the precedence relation between integers
int compare_int(const void* r1_p,const void* r2_p){
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
int compare_string(const void* r1_p,const void* r2_p){
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
int compare_float(const void* r1_p, const void* r2_p) {
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

void testPerf(const char *input){
    struct record *a = read_array(input);

    printf("Testing performance of sorting with string with different values of k\n");
    system("mkdir -p output");
    FILE *fp = fopen("output/perfStr.csv", "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type \t K \t\t Time \n");
    
    for(int i = 0; i <= 500; i++){
        struct record *str_a = malloc(sizeof(struct record) * length_array);
        memcpy(str_a, a, sizeof(struct record) * length_array);
        printf("Sorting with k = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(str_a, length_array, sizeof(struct record), i, compare_string);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d \t\t %d \t\t %f\n", 1, i, time_spent);
        free(str_a);
    }
    printf("Sorting with string done.\n");
    fclose(fp);


    printf("Testing performance of sorting with int with different values of k\n");
    fp = fopen("output/perfInt.csv", "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type \t K \t\t Time \n");
    for(int i = 0; i <= 500; i++){
        struct record *int_a = malloc(sizeof(struct record) * length_array);
        memcpy(int_a, a, sizeof(struct record) * length_array);
        printf("Sorting with k = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(int_a, length_array, sizeof(struct record), i, compare_int);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d \t\t %d \t\t %f\n", 2, i, time_spent);
        free(int_a);
    }
    printf("Sorting with int done.\n");
    fclose(fp);

    printf("Testing performance of sorting with float with different values of k\n");
    fp = fopen("output/perfFloat.csv", "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    fprintf(fp, "Type \t K \t\t Time \n");
    for(int i = 0; i <= 500; i++){
        struct record *float_a = malloc(sizeof(struct record) * length_array);
        memcpy(float_a, a, sizeof(struct record) * length_array);
        printf("Sorting with k = %d, ", i);
        clock_t start = clock();
        merge_binary_insertion_sort(float_a, length_array, sizeof(struct record), i, compare_float);
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("time spent: %f\n", time_spent);
        fprintf(fp, "%d \t\t %d \t\t %f\n", 3, i, time_spent);
        free(float_a);
    }
    printf("Sorting with float done.\n");
    fclose(fp);

    printf("Done testing!\n");
    destroy_Rarr(a);
}
