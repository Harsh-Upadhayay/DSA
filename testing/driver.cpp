#include "linked_list.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    linked_list<int> myList;
    
    vector<int> values = {2, 2, 3, 7, 10, 13, 18, 18, 20, 20, 27, 28, 30, 32, 33, 35, 40, 40, 41, 42, 45, 53, 54, 57, 57, 61, 66, 66, 68, 68, 69, 71, 72, 76, 77, 79, 81, 82, 84, 87, 87, 87, 90, 93, 95, 96, 98, 98, 98
    };

    for(auto value : values)
        myList.insert(value, true);


    myList.printList();

    myList.removeDuplicates();

    myList.printList();

    // for(int i = 0; i < 10; i++){
    //     myList.deleteEnd();
    //     myList.printList();
    // }

    // for(auto value : values)
    //     myList.insert(value);
    
    // myList.printList();
}