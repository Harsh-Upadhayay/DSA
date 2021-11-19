#include "csl210_lab3.h"
#include <stdio.h>
#include <stdlib.h>
#define SPACE_GAP_LEVEL 8

typedef struct priorityNode {
    btNode_t *element;
    struct priorityNode *next;
} priorityNode_t;

priorityNode_t* front = NULL;

void printTree(btNode_t*, short);
void printPQ(void);
void printLine(int);

btNode_t* createBtNode(char c, int freq){
    btNode_t* item = (btNode_t*)malloc(sizeof(btNode_t));
    item->frequency = freq;
    item->value = c;
    item->left = item->right = NULL;
    return item;
}


priorityNode_t* createPQNode(btNode_t *key){
    char c = key->value;
    int priority = key->frequency;

    priorityNode_t* item = (priorityNode_t*)malloc(sizeof(priorityNode_t));
    item->element = key;
    item->element->frequency = priority;
    item->next = NULL;
    return item;

}


void insertPQ(btNode_t* key){

    priorityNode_t* item = createPQNode(key);

     if(0 == front){
        //printf("\nFrom : 1\n");
        front = item;
    }

    else if(item->element->frequency < front->element->frequency){
        item->next = front;
        front = item;
        //printf("\nFrom : 2\n");
    }

    else{
        priorityNode_t *ptr = front, *prev = NULL, *temp;
        while(ptr && ptr->element->frequency <= item->element->frequency){
            prev = ptr;
            ptr = ptr->next;
        }
        //printf("\nFrom : 3\n");
        prev->next = item;
        item->next = ptr;
    }
}


void initializePQ(char input[], unsigned short sz){
    front = NULL;

    int *returnMap = (int *)calloc(256, sizeof(int));

    for(int i = 0; i < sz; i++)
        returnMap[input[i]]++;

    for(int i = 0; i < 256; i++)
            if(i && returnMap[i])
                insertPQ(createBtNode(i, returnMap[i]));
}


priorityNode_t* dequeuePQ(){
    priorityNode_t* head = front;
    
    if(NULL == head)
        return NULL;
    front = front->next;

    return head;
}


int getSizePQ(){
    priorityNode_t *tempPtr = front;
    int sz;
    for(sz = 0; tempPtr; sz++, tempPtr = tempPtr->next);
    return sz;
}


btNode_t* createHuffmanTree(char input[], unsigned short sz){
    if(NULL == input)
        return EMPTYNODE;
    
    initializePQ(input, sz);

    for(int itr = getSizePQ(); itr > 1; itr--){
        printPQ();
        btNode_t *z = createBtNode('*', 0);
        btNode_t *x = z->left = dequeuePQ()->element;
        btNode_t *y = z->right = dequeuePQ()->element;
        z->frequency = x->frequency + y->frequency;
        insertPQ(z);
    }
    
    printPQ();
    return (dequeuePQ()->element);

}


void printTree(btNode_t* root, short space)
{
    if (root == NULL)
        return;
  
    space += SPACE_GAP_LEVEL;
  
    printTree(root->right, space);
  
    printf("\n");
    for (int i = SPACE_GAP_LEVEL; i < space; i++)
        printf(" ");
    printf("(%c, %d)\n", root->value, root->frequency);
  
    printTree(root->left, space);
}



void printLine(int n){
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("*");
    printf("\n");
}

void printPQ(){
    priorityNode_t *node = front;
    while(node){
        printTree(node->element, 0);
        printLine(25);
        node = node->next;
    }
    printLine(100);
    printf("\n\n");
}

/* Sample Inputs
"fffffeeeeeeeeecccccccccccc"
                    "bbbbbbbbbbbbbdddddddddddddddd"
                    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
*/

int main(){
    char string[] = "aabcaaddeffgghhhhfc"; 
    int n = sizeof(string)/sizeof(string[0]);

    
    btNode_t *huffTree = createHuffmanTree(string, n);
    printTree(huffTree, 0);
}
        