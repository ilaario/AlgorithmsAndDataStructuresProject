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
    if(item == NULL) {
        fprintf(stderr, "An error occurred in create_node: first parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    if(level < 0) {
        fprintf(stderr, "An error occurred in create_node: second parameter cannot be negative \n");
        exit(EXIT_FAILURE);
    }

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL) {
        fprintf(stderr, "An error occurred in create_node: unable to allocate memory for the Node \n");
        exit(EXIT_FAILURE);
    }

    node->next = (struct Node **)malloc(level * sizeof(struct Node*));
    node->item = item;
    node->size = level;

    return node;

}

int randomLevel() {
    int lvl = 1;
    int r = ( random() % MAX_HEIGHT );
    while (r < (MAX_HEIGHT/2) && lvl < MAX_HEIGHT) {
        lvl++;
        r = ( random() % MAX_HEIGHT );
    }
    return lvl;
}

static void adapt_head_size(struct SkipList *list, int newSize) {
    /* A new node is created and it will become the head of the skiplist; 
     * the node is created with an updated size */
    struct Node *newHead = createNode("head", newSize);
    struct Node *prevHead;
    int k = 0;

    /* Adapting the pointers to the following elements in the skiplist */
    while(k < newSize) {
        if(k < list->max_level) {
            newHead->next[k] = (list->head)->next[k];
        }
        else {
            newHead->next[k] = NULL;
        }
        k++;
    }

    list->max_level = newSize;
    prevHead = list->head;
    list->head = newHead;
    free(prevHead);
}

//-------------------------------------------------------------

void new_skiplist(struct SkipList **list, size_t max_height, int (*compar)(const void *, const void*)){
    struct SkipList* list_tmp = malloc(sizeof(struct SkipList));
    if(compar == NULL) {
        fprintf(stderr, "An error occured in create_skipList: parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    if(list_tmp == NULL) {
        fprintf(stderr, "An error occurred in create_skipList: unable to allocate memory for the SkipList \n");
        exit(EXIT_FAILURE);
    }

    struct Node *h = createNode("head", 1);

    list_tmp->head = h;
    list_tmp->max_level = 0;
    list_tmp->compare = compar;
    (*list) = list_tmp;

}

void clear_skiplist(struct SkipList **list){
    struct Node *temp;
    struct Node *n = (*list)->head;
    while(n != NULL) {
        char *item = (char *)n->item;
        temp = n->next[0];
        free(item);
        free(n->next);
        free(n);
        n = temp;
    }
    free(*list);

}

void insert_skiplist(struct SkipList *list, void *item){
    if(list == NULL) {
        fprintf(stderr, "An error occurred in insertSkipList: first parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    if(item == NULL) {
        fprintf(stderr, "An error occurred in insertSkipList: second parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    int sizeN = randomLevel();
    struct Node *newNode = createNode(item, sizeN);
    if(newNode->size > list->max_level) {
        adapt_head_size(list, newNode->size);
    }
    struct Node *temp = list->head;
    for(int k = list->max_level-1; k >= 0; k--) {
        if(temp->next[k] == NULL || (*(list)->compare)(item, (temp->next[k])->item)) {
            if(k < newNode->size) {
                newNode->next[k] = temp->next[k];
                temp->next[k] = newNode;
            }
        } else {
            temp = temp->next[k];
            k++;
        }
    }
    free(newNode);
}


const void* search_skiplist(struct SkipList *list, void *item){
    if(list == NULL) {
        fprintf(stderr, "An error occurred in insertSkipList: first parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }
    if(item == NULL) {
        fprintf(stderr, "An error occurred in insertSkipList: second parameter cannot be NULL \n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = list->head;
    int i;
    for(i = list->max_level-1; i >= 0; i--) {
        while(temp->next[i] != NULL && (*(list)->compare)((temp->next[i])->item, item) ) {
            temp = temp->next[i];
        }
    }
    if( (*(list)->compare)((temp->next[i+1])->item, item) == 0 && (*(list)->compare)(item,(temp->next[i+1])->item) == 0) {
        return item;
    }
    else
        return NULL;
}
/*
static void print_skip_list(struct SkipList* list) {
    struct Node* x = list->head;
    for (int i = 0; i < list->max_level; i++) {
        while (x != NULL && x->next[i] != NULL) {
            printf("[%s]->", (char*)(x->next[i]->item));
            x = x->next[i];
        }
        printf("NIL\n");
    }
} */