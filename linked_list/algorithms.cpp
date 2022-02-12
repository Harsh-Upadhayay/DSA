#include "linked_list.h"
#include <iostream>

using namespace std;
    
/**
 * @brief reverses the list in O(n) time 
 * and O(1) extra space.
 * 
 */
template<class dataType = int>
void reverseList(node<dataType> * head){
    node<dataType> *tempNext = NULL, *curr = head, *prev = head;
    if(NULL == head)
        return;
        
    tempNext = head->next;
    head->next = NULL;
    while(tempNext){
        curr = tempNext;
        tempNext = tempNext->next;
        curr->next = prev;
        prev = curr;
    }
    head = curr;
}

int main(){
    linked_list<int> myList;
    
    vector<int> values = {11, 12, 13};

    for(auto value : values)
        myList.insert(value);


    myList.insert(14, true);

    myList.printList();

    myList.reverseList();

    myList.printList();

    // for(int i = 0; i < 10; i++){
    //     myList.deleteEnd();
    //     myList.printList();
    // }

    // for(auto value : values)
    //     myList.insert(value);
    
    myList.printList();
}