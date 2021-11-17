// Driver Program for Red Black Tree

#include <bits/stdc++.h>
#include "RBTree.h"
using namespace std;

int main() {
    RBTree tree;
    pair<int, int> arr[] = {make_pair(100, 1), 
                            make_pair(70, 1), 
                            make_pair(150, 1), 
                            make_pair(50, 1), 
                            make_pair(90, 1), 
                            make_pair(120, 0), 
                            make_pair(180, 1), 
                            make_pair(-1, 1), 
                            make_pair(-1, 1), 
                            make_pair(80, 1), 
                            make_pair(-1, 1), 
                            make_pair(110, 1),
                            make_pair(130, 1), 
                            make_pair(-1, 1),
                            make_pair(200, 0),                         
                            };
        int n = sizeof(arr)/sizeof(arr[0]);
                
    tree.constBT(arr, n);
    tree.insertAtPath("rlrl", make_pair(125, 0));
    
    int insertions[] = {100, 80, 200, 90};
    
    for(auto item : insertions){
        tree.insertValue(item);
        tree.print_t();
    }
        
    tree.print_t();

}
// int main() {
//     int data;
//     RBTree rbTree1, rbTree2;

//     cin >> data;
//     while (data != 0)
//     {
//         rbTree1.insertValue(data);
//         cin >> data;
//     }

//     rbTree1.preorder();

//     cin >> data;
//     while (data != 0)
//     {
//         rbTree2.insertValue(data);
//         cin >> data;
//     }

//     rbTree2.preorder();

//     rbTree1.merge(rbTree2);
//     rbTree1.preorder();

//     return 0;
// }