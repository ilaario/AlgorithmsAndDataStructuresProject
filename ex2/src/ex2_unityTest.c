#include "unity.h"
#include "SkipList.h"

void setUp(void) {
    
}

void tearDown(void) {
    
}

int compare(const void* v1, const void* v2) {
  if(v1 == NULL){
      fprintf(stderr,"precedes_string: the first parameter cannot be NULL \n");
      exit(EXIT_FAILURE);
   }
   if(v2 == NULL){
      fprintf(stderr,"precedes_string: the second parameter cannot be NULL \n");
      exit(EXIT_FAILURE);
   }
   char *word1 = (char *)v1;
   char *word2 = (char *)v2;
    if (strcasecmp(word1, word2) < 0)
      return 1;

   return 0;
}

void test_function_with_null_array(void) {
    struct SkipList *list = NULL;
    TEST_ASSERT_EQUAL(NULL, list);
}

void test_function_free_of_null_array(void){
    struct SkipList *list = NULL;
    new_skiplist(&list, MAX_HEIGHT, compare);
    clear_skiplist(&list);
    TEST_ASSERT_EQUAL(NULL, list);
}

void test_function_of_insert_one_element(void){
    struct SkipList *list = NULL;
    new_skiplist(&list, MAX_HEIGHT, compare);
    insert_skiplist(list, "zero");
    TEST_ASSERT_EQUAL("zero", search_skiplist(list, "zero"));
    clear_skiplist(&list);
}

void test_function_of_insert_of_more_element(void){
    struct SkipList *list = NULL;
    new_skiplist(&list, MAX_HEIGHT, compare);
    insert_skiplist(list, "zero");
    insert_skiplist(list, "one");
    insert_skiplist(list, "two");
    insert_skiplist(list, "three");
    insert_skiplist(list, "four");
    insert_skiplist(list, "five");
    TEST_ASSERT_EQUAL("three", search_skiplist(list, "three"));
    clear_skiplist(&list);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_with_null_array);
    RUN_TEST(test_function_free_of_null_array);
    RUN_TEST(test_function_of_insert_one_element);
    RUN_TEST(test_function_of_insert_of_more_element);
    UNITY_END();
    return 0;
}