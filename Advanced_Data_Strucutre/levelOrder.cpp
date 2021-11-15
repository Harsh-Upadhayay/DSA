#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    int ht;
}*r;


Node* createNode(int val){
    Node* va = (Node*)malloc(sizeof(Node));
    va->data = val;
    va->right = va->left = NULL;
    return va;
}


Node* constBT(int arr[],int n){

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
            if(arr[i]==-1){

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
    return root;
}


void insertAtPath(Node *root, string path, int value){
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


int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

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


void print_t(Node *tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}


class avl_tree {
   public:
      int height(Node *);
      int difference(Node *);
      Node *rr_rotat(Node *);
      Node *ll_rotat(Node *);
      Node *lr_rotat(Node*);
      Node *rl_rotat(Node *);
      Node * balance(Node *);
      Node * insert(Node*, int);
      void show(Node*, int);
      void inorder(Node *);
      void preorder(Node *);
      void postorder(Node*);
      avl_tree() {
         r = NULL;
      }
};
int avl_tree::height(Node *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->left);
      int r_height = height(t->right);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(Node *t) {
   int l_height = height(t->left);
   int r_height = height(t->right);
   int b_factor = l_height - r_height;
   return b_factor;
}
Node *avl_tree::rr_rotat(Node *parent) {
   Node *t;
   t = parent->right;
   parent->right = t->left;
   t->left = parent;
   cout<<"Right-Right Rotation\n";
   return t;
}
Node *avl_tree::ll_rotat(Node *parent) {
   Node *t;
   t = parent->left;
   parent->left = t->right;
   t->right = parent;
   cout<<"Left-Left Rotation\n";
   return t;
}
Node *avl_tree::lr_rotat(Node *parent) {
   Node *t;
   t = parent->left;
   parent->left = rr_rotat(t);
   cout<<"Left-Right Rotation\n";
   return ll_rotat(parent);
}
Node *avl_tree::rl_rotat(Node *parent) {
   Node *t;
   t = parent->right;
   parent->right = ll_rotat(t);
   cout<<"Right-Left Rotation\n";
   return rr_rotat(parent);
}
Node *avl_tree::balance(Node *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->left) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->right) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
Node *avl_tree::insert(Node *r, int v) {
   if (r == NULL) {
      r = new Node;
      r->data = v;
      r->left = NULL;
      r->right = NULL;
      return r;
   } else if (v< r->data) {
      r->left = insert(r->left, v);
      r = balance(r);
   } else if (v >= r->data) {
      r->right = insert(r->right, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(Node *p, int l) {
   int i;
   if (p != NULL) {
      show(p->right, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->data;
         show(p->left, l + 1);
   }
}
void avl_tree::inorder(Node *t) {
   if (t == NULL)
      return;
      inorder(t->left);
      cout << t->data << " ";
      inorder(t->right);
}
void avl_tree::preorder(Node *t) {
   if (t == NULL)
      return;
      cout << t->data << " ";
      preorder(t->left);
      preorder(t->right);
}
void avl_tree::postorder(Node *t) {
   if (t == NULL)
      return;
      postorder(t ->left);
      postorder(t ->right);
      cout << t->data << " ";
}





int main(){
    avl_tree node;
    int ar[] = {100,70,150,50,90,120,180,-1,-1,80,-1,110,130,-1,200};
    int n = sizeof(ar)/sizeof(ar[0]);

    Node* root = constBT(ar, n);
    insertAtPath(root, "rlrl", 125);
    
    int insertions[] = {136, 138, 140, 142, 144};
    for(auto item : insertions){
        print_t(root);
        root = node.insert(root, item);
    }
    print_t(root);
}