#include <bits/stdc++.h>
#include "RBTree.h"
using namespace std;


Node* RBTree::createNode(pair<int, int> value){
    Node* va = (Node*)malloc(sizeof(Node));
    va->data = value.first;
    va->right = va->left = NULL;
    va->color = value.second;
    return va;
}

void RBTree::constBT(pair<int,int> arr[],int n){

    Node *root = NULL;
    Node *curr = NULL;
    int index=0;
    
    queue<Node*> q;
    for(int i=0;i<n;i++){

        if(root==NULL){
            root= createNode(arr[i]);

            q.push(root);
            curr=q.front();
            index=1;
        }else{
            if(arr[i].first==-1){

                 if(index==1)
                    index=2;
                else{
                    q.pop();
                    curr=q.front();
                    index=1;

                }
            }

            else if(index==1){
                curr->left=createNode(arr[i]);
                q.push(curr->left);
                index=2;

            }else if(index==2){
                curr->right=createNode(arr[i]);
                q.push(curr->right);
                q.pop();
                curr=q.front();
                index=1;
            }

        }
    }
    this->root = root;
}

void RBTree::insertAtPath(string path, pair<int, int> value){
    Node *root = this->root;
    for(int i = 0; i < path.length()-1; i++){
        char c = path[i];
        if(root)
            if(c == 'l' || c == 'L')
                root = root->left;
                
            else if (c == 'r' || c == 'R')
                root = root->right;
                
            else 
                return;
        else
            return;
    }
    if(path[path.length()-1] == 'r' || path[path.length()-1] == 'R') 
        root->right = createNode(value);
    else
        root->left = createNode(value);
}

int RBTree::_print_t(Node *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "%03d,%c", tree->data, (tree->color)?'b':'r');

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }

    return left + width + right;
}

void RBTree::print_t()
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(root, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}


