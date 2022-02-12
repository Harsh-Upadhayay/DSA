#include "Binary_Search_Tree.h"
#include "stdio.h"

typedef bstNode_t node;

node* levelOrderToBinTree(char *ar, int n){
    if(NULL == ar)
        return NULL;
    
    for(int i = 0; i < n-1; i++)
        if(ar[i] != 'n')
    return NULL;
}

int main(){
    char ar[] = "Hello";
    int n = sizeof(ar)/sizeof(ar[0]);
    levelOrderToBinTree(ar, n);
}