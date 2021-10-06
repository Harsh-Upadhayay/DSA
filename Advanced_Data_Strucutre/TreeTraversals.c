#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_ARRAY 2048

struct btNode{
    short value;
    struct btNode* left;
    struct btNode* right;
};

typedef struct btNode btNode_t;

typedef short dataType;

typedef enum{
    false, true
} bool ;

typedef struct ListNode
{
    dataType value;
    struct ListNode* next;
}list_t;


/***************************************************************************Utility Functions***************************************************************************/

btNode_t* createNode(dataType val){
    btNode_t* node = (btNode_t*)calloc(1, sizeof(btNode_t));
    node->value = val;
    node->left = node->right = NULL;
    return node;
}


int _print_t(btNode_t *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->value);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }

    return left + width + right;
}


void print_t(btNode_t *tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

/*************************************************************************************************************************************************************************/





/*
** Function to Iteatively sotre Inorder traversal
** of a binary tree in an array and return it's 
** address.
** 
** Parameters : Root node of the intrested tree.
** 
** Return value: Address of first element of arrray
**               where the inorder traversal is stored.
** 
** ThingToRemember : The first element of reurned array 
**                   contains its size. Actual data is 
**                   present from the secondelement i.e. ar[1]
*/
dataType* inorderIt(btNode_t* root){
    
    if(NULL == root)
        return NULL;

    btNode_t* stack[MAX_SIZE_ARRAY];
    dataType i = 0, k = 1;
    static dataType traversal[MAX_SIZE_ARRAY];
    btNode_t* cur_ptr = root;

    do{
       if(cur_ptr){
            stack[i++] = cur_ptr;
            cur_ptr = cur_ptr->left;
        }
        else{
            cur_ptr = stack[--i];
            traversal[k++] = cur_ptr->value;
            cur_ptr = cur_ptr->right;
        }
         
    }while(i || cur_ptr);

    traversal[0] = --k;
    return traversal;
}


/*
** Function to Recursively store Inorder traversal
** of a binary tree in an array, passed as argument.
** 
** Parameters : * Root node of intersted tree,
**              * Array in which traversal will be stored,
**              * Address of a variable which contains 
**                current size of array, ALWAYS 0 in 
**                function call. 
** 
** ThingToRemember : Passed array must have enough space to
**                   store all the nodes of tree.
*/
void inorderReArr(btNode_t* root, int *ar, int *cur_idx){

    if(!root)
        return;
    
    inorderReArr(root->left, ar, cur_idx);

    ar[(*cur_idx)++] = root->value;

    inorderReArr(root->right, ar, cur_idx);

}


/*
** Function to Recursively store Inorder traversal
** of a binary tree in Linked List, passed as argument.
** 
** Parameters : * Root node of intersted tree,
**              * Address of head of an empty linked list
**                in which traversal will be stored,
** 
** ThingToRemember : The last node of the linked list
**                   (before NULL) contains garbage value.
*/
void inorderReLLst(btNode_t* root, list_t **listPtr){

    if(!root)
        return;
    
    inorderReLLst(root->left, listPtr);

    
    list_t *tempPtr = (*listPtr);
    
    if(tempPtr)
        while(tempPtr->next)
            tempPtr = tempPtr->next;
    else    
        tempPtr = (*listPtr) = (list_t*)malloc(sizeof(list_t));

    tempPtr->value = root->value;
    tempPtr->next = (list_t*)malloc(sizeof(list_t));
    tempPtr->next->next = NULL;


    inorderReLLst(root->right, listPtr);

}


int main(){

    btNode_t* root = NULL, *newNode;
    root = createNode(12);

    root->right = (createNode(12));
    root->left = (createNode(9));
    root->right->left = (createNode(1));
    root->right->right = (createNode(20));
    root->left->left = (createNode(10));
    root->left->right = (createNode(11));

    print_t(root);


    printf("\nInorder : " );
    list_t *traversal = NULL;
    inorderReL(root, &traversal);
    while (traversal)
    {
        printf("%d -> ", traversal->value);
        traversal = traversal->next;
    }

    printf("\nInorder : " );
    int ar[MAX_SIZE_ARRAY] = {0}, idx = 0;
    inorderRe(root, ar, &idx);
    for(int i = 0; i < idx; i++)
        printf("%d ", ar[i]);

    
}