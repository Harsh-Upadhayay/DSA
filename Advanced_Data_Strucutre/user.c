#include "Binary_Search_Tree.h"
#include <stdio.h>

int main(){
    DataType values[] = {150,30,35,40,45,50,51,55,56,60};
    bstNode_t* root = NULL;
    root = createNode(11);
    for(int i = 0; i < 10; i++)
        insertBST(root, createNode(values[i]));
    printBST(root, 0);
}
