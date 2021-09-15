
#define SPACE_GAP_LEVEL 10
#define MAX_NODES 100

typedef short DataType;

struct BST_Node {
    DataType value;
    struct BST_Node *left, *right;
};

typedef struct BST_Node bstNode_t;

enum status{
    FLASE, TRUE
};

typedef enum status status_t;

bstNode_t* createNode(DataType val);

bstNode_t* getParentNode(bstNode_t* root, DataType val);

status_t insertBST (bstNode_t *root, bstNode_t *node);

void printBST(bstNode_t *root, short space);

void inOrder(bstNode_t *root);

void preOrder(bstNode_t *root);

void postOrder(bstNode_t *root);

status_t searchBST (bstNode_t *root, bstNode_t *node);

status_t deleteNodeBst (bstNode_t *root, bstNode_t *node);

status_t updateBST (bstNode_t *root, bstNode_t *node, bstNode_t * newNode);

