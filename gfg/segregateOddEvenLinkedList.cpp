#include "../linked_list/base_implementation.cpp"
#include "iostream"

using namespace std;

void fun(node<int>** headRef){

    node<int> *head = *headRef;

    if(!head) return;

    node<int>  *odd_start, *even_start, *odd_end, *even_end;
    odd_start = even_start = odd_end = even_end = NULL;
    
    while(head){
        if(head->data % 2)
            if(!odd_start)
                odd_end = odd_start = head;
            else
                odd_end = odd_end -> next = head;
                
        else
            if(!even_start)
                even_end = even_start = head;
            else
                even_end = even_end -> next = head;
        
        head = head->next;
    }
    
    if(!odd_start || !even_start)
        return;
    
    even_end -> next = odd_start;
    odd_end -> next = NULL;

    *headRef = even_start;

    return;
}

int main(){
    linked_list<int> myList;
     
    vector<int> values = {17, 13, 11, 16, 15, 12, 13, 8};

    for(auto value : values)
        myList.insert(value);

    myList.printList();
    fun(myList.getHeadRef());
    myList.printList();

    return 0;
}