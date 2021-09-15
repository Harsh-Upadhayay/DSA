/*
** Topic : Implementation of Binary Search Tree
** Author : Harsh Upadhayay
            IITN
*/

#define SPACE_GAP_LEVEL 10
#define MAX_NODES 100

typedef short DataType;  //replace short by the data type, the binary tree needs to consist.

struct BST_Node {
    DataType value;
    struct BST_Node *left, *right;
};

typedef struct BST_Node bstNode_t;

enum status{
    FLASE, TRUE
};

typedef enum status status_t;


/*
** Input Parameters :  Data to be stored in node of type Datatype
** Returned value : Pointer to the node created.
** Function : allocates memory for a node of BST and initilizes
**               left and right children as NULL.
*/
bstNode_t* createNode(DataType val);


/*
** Input Parameters :Pointer to root node of BST and 
**                   value of node who's parent node is to be determined.
** Returned value : Pointer to the parent node of val
** Function : Finds the parent node where node with data val can be inserted in the BST.
*/
bstNode_t* getParentNode(bstNode_t* root, DataType val);


/*
** Input Parameters : Pointer to root node of BST and
**                    Pointer to newNode which is to be inserted
** Returned value : Status of insertion, 0 : False, 1: True.
** Function : inserts node at its correct position in the BST.
*/
status_t insertBST (bstNode_t *root, bstNode_t *node);


/*
** Input Parameters : Pointer to root node of BST and
**                    space between prompt and root node
**                    (set this parameter to zero, for normal functioning).
** Function : Prints the BST in horizontal tree. 
*/
void printBST(bstNode_t *root, short space);


/*
** Input Parameters : Pointer to root node.
** Function : Inorder Traversal, left > root > right.
*/
void inOrder(bstNode_t *root);


/*
** Input Parameters : Pointer to root node.
** Function : Preorder Traversal, left > right > root.
*/
void preOrder(bstNode_t *root);


/*
** Input Parameters : Pointer to root node.
** Function : Postorder Traversal, root > left > right.
*/
void postOrder(bstNode_t *root);


/*
** Input Parameters : Pointer to root node and
**                    key value to be searched.
** Returned value : Pointer to the node with value as key,
**                  returns NULL if not present.
** Function : Does binary search on the BST, and prints
**            the path to the node.
*/
bstNode_t* searchBST (bstNode_t *root, DataType key);


/*
** Input Parameters : Pointer to the pointer of root node and
**                    key value to be deleted.
** Returned value : Status of Deletion, 0 : False, 1 : True.
** Function : Deletes the node with value as key, from the BST.
*/
status_t deleteNodeBst (bstNode_t **PtrRoot, DataType key);
