#include "Binary_Search_Tree.h"
#include <stdio.h>

int main(){
    DataType values[] = {50,40,60,30,45,60,55,15,35,51,56,9,10},
             n = sizeof(values)/sizeof(values[0]);

    bstNode_t* root = NULL;
    root = createNode(11);

    for(int i = 0; i < n; i++)
        insertBST(root, createNode(values[i]));
    
    printBST(root, 0);

    printf("\n\nPreOrder : ");
    preOrder(root);

    printf("\n\nInOrder : ");
    inOrder(root);

    printf("\n\nPostOrder : ");
    postOrder(root);

    printf("\n");

    if(!searchBST(root, createNode(35)))
        printf("Not Found");

    printf("\n");
    return 0;
}

  