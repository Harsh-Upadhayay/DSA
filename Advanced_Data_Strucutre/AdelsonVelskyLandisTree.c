#include "Adelson_Velsky_Landis_Tree.h"
#include <stdlib.h>
#include <stdio.h>


/*Private Functions*/
avlNode_t* getParentNode(avlNode_t *root, DataType val){
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


void update_BalanceFactor(avlNode_t *root, DataType key){
    if(NULL == root)
        return;

    do
        if(root->value > key){
            root->bFactor += 1;
            root = root->left;
        }
        else if(root->value < key){
            root->bFactor -= 1;
            root = root->right;
        }       
    while(root->value != key);
     
}



status_t balanceTree(avlNode_t **rootPtr){
    if(NULL == rootPtr || NULL == *rootPtr)
        return FLASE;

    avlNode_t *root = *rootPtr;
    

    return TRUE;
}


avlNode_t* createNode(DataType val){
    avlNode_t* node = (avlNode_t*)calloc(1, sizeof(avlNode_t));
    node->value = val;
    node->bFactor = 0;
    node->left = node->right = NULL;
    return node;
}


status_t insertAVL (avlNode_t *root, avlNode_t *node){
    if(NULL == root || NULL == node)
        return FLASE;

    avlNode_t* parent = getParentNode(root, node->value);
    status_t flag = FLASE;

    if(NULL == parent)
        return FLASE;

    if(node->value > parent->value){
        if(NULL == parent->left)
            flag = TRUE;
        else
            parent->bFactor -= 1;
        parent->right = node;
    }
    else if(node->value < parent->value){
        if(NULL == parent->right)
            flag = TRUE;
        else
            parent->bFactor += 1;
        parent->left = node;
    }

    if(flag)
        update_BalanceFactor(root, node->value);

    return TRUE;
}


void printAVL(avlNode_t* root, short space)
{
    if (root == NULL)
        return;
  
    space += SPACE_GAP_LEVEL;
  
    printAVL(root->right, space);
  
    printf("\n");
    for (int i = SPACE_GAP_LEVEL; i < space; i++)
        printf(" ");
    printf("(%d, %d)\n", root->value, root->bFactor);
  
    printAVL(root->left, space);
}

void ll_rotate(avlNode_t *node, avlNode_t *parent){
    if(NULL == node || NULL == parent)
        return;

    avlNode_t *temp;

    temp = node->left;

    node->left = node->left->right;
    
    temp->right = node;

    if(node->value > parent->value)
        parent->right = temp;
    else if(node->value < parent->value)
        parent->left = temp;
}


void rr_rotate(avlNode_t *node, avlNode_t *parent){
    if(NULL == node || NULL == parent)
        return;

    avlNode_t *temp;

    temp = node->right;

    node->right = node->right->left;
    
    temp->left = node;

    if(node->value > parent->value)
        parent->right = temp;
    else if(node->value < parent->value)
        parent->left = temp;
}


void lr_rotate(avlNode_t *node, avlNode_t *parent){
    if(NULL == node || NULL == parent)
        return;

    avlNode_t *temp;

    temp = node->left;

    node->left = node->left->right;
    
    temp->right = node->left->left;

    node->left->left = temp;

    ll_rotate(node, parent);
}


void rl_rotate(avlNode_t *node, avlNode_t *parent){
    if(NULL == node || NULL == parent)
        return;

    avlNode_t *temp;

    temp = node->right;

    node->right = node->right->left;
    
    temp->left = node->right->right;

    node->right->right = temp;

    rr_rotate(node, parent);
}

// // Insert node
// struct Node *insertNode(struct Node *node, int key) {
//   // Find the correct position to insertNode the node and insertNode it
//   if (node == NULL)
//     return (newNode(key));

//   if (key < node->key)
//     node->left = insertNode(node->left, key);
//   else if (key > node->key)
//     node->right = insertNode(node->right, key);
//   else
//     return node;

//   // Update the balance factor of each node and
//   // Balance the tree
//   node->height = 1 + max(height(node->left),
//                height(node->right));

//   int balance = getBalance(node);
//   if (balance > 1 && key < node->left->key)
//     return rightRotate(node);

//   if (balance < -1 && key > node->right->key)
//     return leftRotate(node);

//   if (balance > 1 && key > node->left->key) {
//     node->left = leftRotate(node->left);
//     return rightRotate(node);
//   }

//   if (balance < -1 && key < node->right->key) {
//     node->right = rightRotate(node->right);
//     return leftRotate(node);
//   }

//   return node;
// }
