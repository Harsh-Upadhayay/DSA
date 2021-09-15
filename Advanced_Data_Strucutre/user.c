#include "Binary_Search_Tree.h"
#include <stdio.h>

int main(){
    DataType values[] = {50,40,60,30,45,60,55,15,35,51,56,9,10,52},
             n = sizeof(values)/sizeof(values[0]);

    bstNode_t* root = NULL;
    root = createNode(11);

    for(int i = 0; i < n; i++)
        insertBST(root, createNode(values[i]));
    
    printBST(root, 0);

    // printf("\n\nPreOrder : ");
    // preOrder(root);

    // printf("\n\nInOrder : ");
    // inOrder(root);

    // printf("\n\nPostOrder : ");
    // postOrder(root);

    // printf("\n");

    // bstNode_t* item = searchBST(root, 40);
    // printBST(item, 0);

    printf("\n\n\n*%d* ", deleteNodeBst(&root, 50));
    printBST(root, 0);
    printf("\n\n\n*%d* ", deleteNodeBst(&root, 55));
    printBST(root, 0);
    printf("\n\n\n*%d* ", deleteNodeBst(&root, 40));
    printBST(root, 0);    

    printf("\n");
    return 0;
}

  