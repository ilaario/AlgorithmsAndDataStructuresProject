#include "SkipList.h"

struct SkipList {
  struct Node *head;
  size_t max_level;
  size_t max_height;
  int (*compare)(const void*, const void*);
};

struct Node {
  struct Node **next;
  size_t size;
  void *item;
};

struct Node* createNode(void *item, int level){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        fprintf(stderr, "createNode(): node malloc error\n");
        return NULL;
    }
    printf("createNode(): Node created\n");

    n->item = item;
    n->size = level;
    printf("createNode(): Creation of n -> next pointers\n");
    n->next = (struct Node**)malloc((unsigned long int)(level) * sizeof(struct Node*));
    for (size_t i = 0; i < level; i++){
        n->next[i] = NULL;
    }
    
    printf("createNode(): n -> next pointers created\n");

    if (n->next == NULL) {
        fprintf(stderr, "createNode(): next malloc error\n");
        return NULL;
    }
    printf("createNode(): Node initialized\n");
    return n;
}

int randomLevel() {
    int lvl = 1;
    srand(time(NULL)); // Inizializzazione del generatore di numeri casuali

    while ((double) rand() / RAND_MAX < 0.5 && lvl < MAX_HEIGHT) {
        lvl++;
    }

    return lvl;
}

void new_skiplist(struct SkipList **list, size_t max_height, int (*compar)(const void *, const void*)){
    struct SkipList* list_tmp = malloc(sizeof(struct SkipList));
    if (list_tmp == NULL) {
        fprintf(stderr, "new_skiplist(): skiplist malloc error\n");
        exit(EXIT_FAILURE);
    }
    printf("new_skiplist(): List created\n");

    list_tmp -> head = NULL;
    printf("new_skiplist(): NULL-Head initialized\n");

    if ((list_tmp->head = createNode(NULL, max_height)) == NULL) {
        fprintf(stderr, "new_skiplist(): skiplist createNode error\n");
        exit(EXIT_FAILURE);
    }
    printf("new_skiplist(): Head created\n");

    list_tmp->max_height = 0;

    list_tmp->max_level = 1;
    list_tmp->compare = compar;
    
    printf("new_skiplist(): List initialized\n");
    list = &list_tmp;
}

void clear_skiplist(struct SkipList **list){
    struct Node *current = (*list)->head;
    struct Node *next = NULL;
    while (current != NULL){
        next = current->next[0];
        free(current->next);
        free(current);
        current = next;
    }
    free(*list);
    *list = NULL;
}

void insert_skiplist(struct SkipList *list, void *item){
    struct Node *new_node = createNode(item, randomLevel());
    if (new_node == NULL){
        fprintf(stderr, "insert_skiplist(): new_node malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (new_node -> size > list -> max_height){
        list -> max_height = new_node -> size;
    }

    struct Node *x = list->head;
    for (size_t k = list -> max_level - 1; k >= 0; --k){
        if(x -> next[k] != NULL || list->compare(x -> next[k] -> item, item) < 0){
            if (k < new_node -> size){
                new_node -> next[k] = x -> next[k];
                x -> next[k] = new_node;
            } else {
                x = x -> next[k];
                k++;
            }
        }
    }
}

const void* search_skiplist(struct SkipList *list, void *item){
    struct Node *current = list->head;
    for (size_t i = list -> max_level; i > 0; i--){
        while (current != NULL && list->compare(current -> next[i] -> item, item) < 0){
            current = current -> next[i];
        }
    }
    
    current = current -> next[0];
    if (current -> item != NULL && list -> compare(current -> item, item) == 0){
        return current -> item;
    }
    return NULL;
}

void print_skip_list(struct SkipList* list) {
    struct Node* x = list->head;
    for (int i = 0; i < list->max_level; i++) {
        while (x != NULL && x->next[i] != NULL) {
            printf("[%s]->", (char*)(x->next[i]->item));
            x = x->next[i];
        }
        printf("NIL\n");
    }
}

