
// Node *insert(Node *,int);
// Node *Delete(Node *,int);
// void preorder(Node *);
// void inorder(Node *);
// int height( Node *);
// Node *rotateright(Node *);
// Node *rotateleft(Node *);
// Node *RR(Node *);
// Node *LL(Node *);
// Node *LR(Node *);
// Node *RL(Node *);
// int BF(Node *);
 
// Node * insert(Node *T,int x)
// {
// if(T==NULL)
// {
// T=(Node*)malloc(sizeof(Node));
// T->data=x;
// T->left=NULL;
// T->right=NULL;
// }
// else
// if(x > T->data) // insert in right subtree
// {
// T->right=insert(T->right,x);
// if(BF(T)==-2)
// if(x>T->right->data)
// T=RR(T);
// else
// T=RL(T);
// }
// else
// if(x<T->data)
// {
// T->left=insert(T->left,x);
// if(BF(T)==2)
// if(x < T->left->data)
// T=LL(T);
// else
// T=LR(T);
// }
// T->ht=height(T);
// return(T);
// }
 
// Node * Delete(Node *T,int x)
// {
// Node *p;
// if(T==NULL)
// {
// return NULL;
// }
// else
// if(x > T->data) // insert in right subtree
// {
// T->right=Delete(T->right,x);
// if(BF(T)==2)
// if(BF(T->left)>=0)
// T=LL(T);
// else
// T=LR(T);
// }
// else
// if(x<T->data)
// {
// T->left=Delete(T->left,x);
// if(BF(T)==-2) //Rebalance during windup
// if(BF(T->right)<=0)
// T=RR(T);
// else
// T=RL(T);
// }
// else
// {
// //data to be deleted is found
// if(T->right!=NULL)
// { //delete its inorder succesor
// p=T->right;
// while(p->left!= NULL)
// p=p->left;
// T->data=p->data;
// T->right=Delete(T->right,p->data);
// if(BF(T)==2)//Rebalance during windup
// if(BF(T->left)>=0)
// T=LL(T);
// else
// T=LR(T);\
// }
// else
// return(T->left);
// }
// T->ht=height(T);
// return(T);
// }
 
// int height(Node *T)
// {
// int lh,rh;
// if(T==NULL)
// return(0);
// if(T->left==NULL)
// lh=0;
// else
// lh=1+T->left->ht;
// if(T->right==NULL)
// rh=0;
// else
// rh=1+T->right->ht;
// if(lh>rh)
// return(lh);
// return(rh);
// }
 
// Node * rotateright(Node *x)
// {
// Node *y;
// y=x->left;
// x->left=y->right;
// y->right=x;
// x->ht=height(x);
// y->ht=height(y);
// return(y);
// }
 
// Node * rotateleft(Node *x)
// {
// Node *y;
// y=x->right;
// x->right=y->left;
// y->left=x;
// x->ht=height(x);
// y->ht=height(y);
// return(y);
// }
 
// Node * RR(Node *T)
// {
// T=rotateleft(T);
// return(T);
// }
 
// Node * LL(Node *T)
// {
// T=rotateright(T);
// return(T);
// }
 
// Node * LR(Node *T)
// {
// T->left=rotateleft(T->left);
// T=rotateright(T);
// return(T);
// }
 
// Node * RL(Node *T)
// {
// T->right=rotateright(T->right);
// T=rotateleft(T);
// return(T);
// }
 
// int BF(Node *T)
// {
// int lh,rh;
// if(T==NULL)
// return(0);
 
// if(T->left==NULL)
// lh=0;
// else
// lh=1+T->left->ht;
 
// if(T->right==NULL)
// rh=0;
// else
// rh=1+T->right->ht;
 
// return(lh-rh);
// }
 
// void preorder(Node *T)
// {
// if(T!=NULL)
// {
// printf("%d(Bf=%d)",T->data,BF(T));
// preorder(T->left);
// preorder(T->right);
// }
// }
 
// void inorder(Node *T)
// {
// if(T!=NULL)
// {
// inorder(T->left);
// printf("%d(Bf=%d)",T->data,BF(T));
// inorder(T->right);
// }
// }


// // int main()
// // {
// // Node *root=NULL;
// // int x,n,i,op;
// // do
// // {
// // printf("\n1)Create:");
// // printf("\n2)Insert:");
// // printf("\n3)Delete:");
// // printf("\n4)Print:");
// // printf("\n5)Quit:");
// // printf("\n\nEnter Your Choice:");
// // scanf("%d",&op);
// // switch(op)
// // {
// // case 1: printf("\nEnter no. of elements:");
// // scanf("%d",&n);
// // printf("\nEnter tree data:");
// // root=NULL;
// // for(i=0;i<n;i++)
// // {
// // scanf("%d",&x);
// // root=insert(root,x);
// // }
// // break;
// // case 2: printf("\nEnter a data:");
// // scanf("%d",&x);
// // root=insert(root,x);
// // break;
// // case 3: printf("\nEnter a data:");
// // scanf("%d",&x);
// // root=Delete(root,x);
// // break;
// // case 4: printf("\nPreorder sequence:\n");
// // preorder(root);
// // printf("\n\nInorder sequence:\n");
// // inorder(root);
// // printf("\n");
// // break;
// // }
// // }while(op!=5);
// // return 0;
// // }
 
// int main() {
//    int c, i;
//    avl_tree Node;
//    while (1) {
//       cout << "1.Insert Element into the tree" << endl;
//       cout << "2.show Balanced AVL Tree" << endl;
//       cout << "3.InOrder traversal" << endl;
//       cout << "4.PreOrder traversal" << endl;
//       cout << "5.PostOrder traversal" << endl;
//       cout << "6.Exit" << endl;
//       cout << "Enter your Choice: ";
//       cin >> c;
//       switch (c) {
//          case 1:
//             cout << "Enter value to be inserted: ";
//             cin >> i;
//             r = Node.insert(r, i);
//          break;
//          case 2:
//             if (r == NULL) {
//                cout << "Tree is Empty" << endl;
//                continue;
//             }
//             cout << "Balanced AVL Tree:" << endl;
//             Node.show(r, 1);
//             cout<<endl;
//          break;
//          case 3:
//             cout << "Inorder Traversal:" << endl;
//             Node.inorder(r);
//             cout << endl;
//          break;
//          case 4:
//             cout << "Preorder Traversal:" << endl;
//             Node.preorder(r);
//             cout << endl;
//          break;
//          case 5:
//             cout << "Postorder Traversal:" << endl;
//             Node.postorder(r);
//             cout << endl;
//          break;
//          case 6:
//             exit(1);
//          break;
//          default:
//             cout << "Wrong Choice" << endl;
//       }
//    }
//    return 0;
// }