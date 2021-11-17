//
// Red Black Tree Definition
//
#include<bits/stdc++.h>
using namespace std;
#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

enum Color {RED, BLACK, DOUBLE_BLACK};

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class RBTree
{        
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void fixInsertRBTree(Node *&);
        void fixDeleteRBTree(Node *&);
        void inorderBST(Node *&);
        void preorderBST(Node *&);
        int getColor(Node *&);
        void setColor(Node *&, int);
        Node *minValueNode(Node *&);
        Node *maxValueNode(Node *&);
        Node* insertBST(Node *&, Node *&);
        Node* deleteBST(Node *&, int);
        int getBlackHeight(Node *);
        int _print_t(Node*, int, int, int, char[20][255]);
        Node* createNode(pair<int, int>);
    public:
        RBTree();
        void insertValue(int);
        void deleteValue(int);
        void merge(RBTree);
        void inorder();
        void preorder();
        void constBT(pair<int,int>[], int n);
        void insertAtPath(string, pair<int, int>);
        void print_t();

};


#endif //RED_BLACK_TREE_RBTREE_H
