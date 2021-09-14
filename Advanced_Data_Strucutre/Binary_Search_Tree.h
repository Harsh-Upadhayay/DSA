
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

void printBST(bstNode_t *root);

void inorder(bstNode_t *root);

void preOrder(bstNode_t *root);

void inorder(bstNode_t *root);

status_t insertBST (bstNode_t *root, bstNode_t *node);

status_t searchBST (bstNode_t *root, bstNode_t *node);

status_t deleteNodeBst (bstNode_t *root, bstNode_t *node);

status_t updateBST (bstNode_t *root, bstNode_t *node, bstNode_t * newNode);