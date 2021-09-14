#include "Binary_Search_Tree.h"
#include <stdlib.h>

bstNode_t* createNode(DataType val){
    bstNode_t* node = calloc(1, sizeof(bstNode_t));
    node->value = val;
    node->left = node->right = NULL;
    return node;
}

status_t insertBST (bstNode_t *root, bstNode_t *node){
    if(NULL == root || NULL == node)
        return FLASE;


    return TRUE;
}