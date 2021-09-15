#include "Binary_Search_Tree.h"
#include <stdlib.h>
#include <stdio.h>

bstNode_t* createNode(DataType val){
    bstNode_t* node = (bstNode_t*)calloc(1, sizeof(bstNode_t));
    node->value = val;
    node->left = node->right = NULL;
    return node;
}

bstNode_t* getParentNode(bstNode_t *root, DataType val){
    if(NULL == root)
        return NULL;
    
    while(root){
        if(root->value > val && NULL == root->left)
            return root;
        else if (root -> value > val && NULL != root->left)
            root = root->left;
        else if (root -> value < val && NULL == root->right)
            return root;
        else if (root -> value < val && NULL != root->right)
            root = root -> right;
        else 
            return NULL;
    }
    return NULL;
}

status_t insertBST (bstNode_t *root, bstNode_t *node){
    if(NULL == root || NULL == node)
        return FLASE;

    bstNode_t* parent = getParentNode(root, node->value);

    if(NULL == parent)
        return FLASE;

    if(node->value > parent->value)
        parent->right = node;
    else if(node->value < parent->value)
        parent->left = node;

    return TRUE;
}


void printBST(bstNode_t* root, short space)
{
    if (root == NULL)
        return;
  
    space += SPACE_GAP_LEVEL;
  
    printBST(root->right, space);
  
    printf("\n");
    for (int i = SPACE_GAP_LEVEL; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);
  
    printBST(root->left, space);
}

void inOrder(bstNode_t *root){
    if(NULL == root)
        return;

    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}

void preOrder(bstNode_t *root){
    if(NULL == root)
        return;

    printf("%d ", root->value);
    inOrder(root->left);
    inOrder(root->right);

}

void postOrder(bstNode_t *root){
    if(NULL == root)
        return;
    inOrder(root->left);
    inOrder(root->right);
    printf("%d ", root->value);
}

status_t searchBST(bstNode_t *root, bstNode_t *node){
    if(NULL == root || NULL == node)
        return FLASE;

    DataType path[MAX_NODES] = {-1}, flag = 0, i = 0;

    while(root && !flag){
        if(node->value > root->value){
            path[i++] = root->value;
            root = root->right;
        }
        else if(node->value < root->value){
            path[i++] = root->value;
            root = root -> left;
        }
        else{
            path[i++] = root->value;
            flag = 1;
        }
    }

    if(!flag)
        return FLASE;

    for(int k = 0; k < i; k++)
        printf("%d ", path[k]);

    return TRUE;
}