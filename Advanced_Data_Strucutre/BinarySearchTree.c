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


bstNode_t* searchBST(bstNode_t *root, DataType key){
    if(NULL == root)
        return NULL;

    DataType path[MAX_NODES] = {-1}, flag = 0, i = 0;

    while(root && !flag){
        if(key > root->value){
            path[i++] = root->value;
            root = root->right;
        }
        else if(key < root->value){
            path[i++] = root->value;
            root = root -> left;
        }
        else{
            path[i++] = root->value;
            flag = 1;
        }
    }

    if(!flag)
        return NULL;

    for(int k = 0; k < i; k++)
        printf("%d ", path[k]);

    return root;
}


status_t deleteNodeBst (bstNode_t **PtrRoot, DataType key){
    /*Check for invalid input*/
    if(NULL == PtrRoot || NULL == *PtrRoot)  
        return FLASE;
    
    bstNode_t *root = *PtrRoot, *parent = *PtrRoot;

    DataType flag = 0;

    /* 
    ** Sets root to the node which's to be deleted
    ** and parent to it's parent node.
    */
    while(root && !flag){
        if (root->value == key){
            flag = 1;
            break;
        }
        parent = root;
        if(key > root->value){
            root = root->right;
        }
        else if(key < root->value){
            root = root -> left;
        }

    }

    /*
    ** Return if element's not present in the BST
    */
    if(!flag)
        return FLASE;

    /*
    ** If the node to be deleted is leaf node.
    ** then link the parent's respective child
    ** (left/right) to NULL.
    */
    if(NULL == root ->left && NULL == root->right)

        if(parent->value < root->value)
            parent->right = NULL;
        else if(parent->value > root->value)
            parent->left = NULL;
        else
            *PtrRoot = NULL;  //if it's the only node in the BST

    /* 
    ** If the node to be deleted only has right child,
    ** then link the parent's respective child(left/right)
    ** to the key(root here) node's right child.
    */
    else if(NULL == root->left && NULL != root->right)

        if(parent->value < root->value)
            parent->right = root->right;
        else
            parent->left = root->right;

    /*
    ** If the node to be deleted only has left child
    ** then link the parent's respective child(left/right)
    ** to the key(root here) node's left child.
    */ 
    else if(NULL == root->right && NULL != root->left)

        if(parent->value < root->value)
            parent->right = root->left;
        else
            parent->left = root->left;
    
    /*
    ** If the node to be deleted only has both children
    ** store the current position of ptr,
    ** replace the node by the smallest child in the right subtree,
    ** delete the smallest child of the right subtree. (Coz it's already-
    ** -been replaced by the node that had to be deleted).   
    */
    else{
        bstNode_t *curPtr = root;
        DataType temp;
        
        root = root->right; //selecting the right subtree.
        
        while(root->left)
            root = root->left; //selecting the smallest(leftmost) node.
        
        temp = root->value; //temporary store the value of smallest node of right subtree.  
        deleteNodeBst(&parent, root->value); //delete smallest node of right subtree.
        curPtr->value = temp;//replace the node that's to be deleted by the smallest node of right subtree.    
    }

    return TRUE;    
}
