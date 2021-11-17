// Driver Program for Red Black Tree
// g++ main.cpp RBTree.cpp RBTreeExtended.cpp; ./a.out > output.txt; rm a.out 

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
    
    int insertions[] = {125};
    
    for(auto item : insertions){
        tree.deleteValue(item);
        tree.print_t();
    }
        
    tree.print_t();

}
