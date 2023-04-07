#include "unity.h"
#include "main_ex1.h"

void setUp(void) {
    
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_with_null_array(void) {
    int *arr = NULL;
    merge_binary_insertion_sort(arr, 0, sizeof(int), 0, compare_int);
    TEST_ASSERT_EQUAL(NULL, arr);
    //test stuff
}

void test_function_with_0_element_array(void) {
    int *arr = malloc(sizeof(int));
    arr = 0;
    merge_binary_insertion_sort(arr, 0, sizeof(int), 0, compare_int);
    TEST_ASSERT_EQUAL(0, arr);
}

void test_function_with_100_0_element_array(void) {
    int *arr = calloc(100, sizeof(int));
    int *expected = calloc(100, sizeof(int));
    
    merge_binary_insertion_sort(arr, 100, sizeof(int), 0, compare_int);
    TEST_ASSERT_EQUAL_INT32_ARRAY(expected, arr, 100);
}

void test_function_with_100_num_element_array(void) {
    int *arr = malloc(sizeof(int) * 100);
    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }
    int *expected = malloc(sizeof(int) * 100);
    memcpy(expected, arr, sizeof(int) * 100);
    qsort(expected, 100, sizeof(int), testCompareInt);
    merge_binary_insertion_sort(arr, 100, sizeof(int), 0, testCompareInt);
    TEST_ASSERT_EQUAL_INT32_ARRAY(expected, arr, 100);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_with_null_array);
    RUN_TEST(test_function_with_0_element_array);
    RUN_TEST(test_function_with_100_0_element_array);
    RUN_TEST(test_function_with_100_num_element_array);
    return UNITY_END();
}


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

int testCompareInt(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}