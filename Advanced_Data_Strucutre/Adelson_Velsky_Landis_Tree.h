/*
** Topic : Implementation of Adelson Velsky Landis Tree
** Author : Harsh Upadhayay
            IITN
*/

#define SPACE_GAP_LEVEL 10
#define MAX_NODES 100

typedef short DataType;  //replace short by the data type, the binary tree needs to consist.

struct AVL_Node {
    DataType value;
    short bFactor;
    struct AVL_Node *left, *right;
};

typedef struct AVL_Node avlNode_t;

enum status{
    FLASE, TRUE
};

typedef enum status status_t;


/*
** Input Parameters :  Data to be stored in node of type Datatype
** Returned value : Pointer to the node created.
** Function : allocates memory for a node of AVL tree and initilizes
**               left and right children as NULL and balance factor as 0.
*/
avlNode_t* createNode(DataType val);

/*
** Input Parameters : Pointer to root node of AVL tree and
**                    Pointer to newNode which is to be inserted
** Returned value : Status of insertion, 0 : False, 1: True.
** Function : inserts node at its correct position in the AVL tree.
*/
status_t insertAVL (avlNode_t *root, avlNode_t *node);


/*
** Input Parameters : Pointer to root node of AVL tree and
**                    space between prompt and root node
**                    (set this parameter to zero, for normal functioning).
** Function : Prints the AVL tree in horizontal tree. 
*/
void printAVL(avlNode_t *root, short space);


/*
** Input Parameters : Pointer to root node.
** Function : Inorder Traversal, left > root > right.
*/
void inOrder(avlNode_t *root);


/*
** Input Parameters : Pointer to root node.
** Function : Preorder Traversal, left > right > root.
*/
void preOrder(avlNode_t *root);


/*
** Input Parameters : Pointer to root node.
** Function : Postorder Traversal, root > left > right.
*/
void postOrder(avlNode_t *root);


/*
** Input Parameters : Pointer to root node and
**                    key value to be searched.
** Returned value : Pointer to the node with value as key,
**                  returns NULL if not present.
** Function : Does binary search on the AVL tree, and prints
**            the path to the node.
*/
avlNode_t* searchAVL (avlNode_t *root, DataType key);


/*
** Input Parameters : Pointer to the pointer of root node and
**                    key value to be deleted.
** Returned value : Status of Deletion, 0 : False, 1 : True.
** Function : Deletes the node with value as key, from the AVL tree.
*/
status_t deleteNodeAVL (avlNode_t **PtrRoot, DataType key);


void ll_rotate(avlNode_t *node, avlNode_t *parent);

void rr_rotate(avlNode_t *node, avlNode_t *parent);

void lr_rotate(avlNode_t *node, avlNode_t *parent);

void rl_rotate(avlNode_t *node, avlNode_t *parent);
