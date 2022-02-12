#include<iostream>
#include<vector>
#include "linked_list.h"
using namespace std;

template<class dataType>
node<dataType>::node(){
    next = nullptr;
}

template<class dataType>
node<dataType>::node(dataType value){
    data = value;
    next = nullptr;
}


template<class dataType>
linked_list<dataType> :: linked_list(void){
    head = tail = nullptr;
    list_size = 0;
}

template<class dataType>
bool linked_list<dataType> :: insert(dataType value, bool atHead){
    
    if(nullptr == head){
        head = tail = new node(value);
        list_size++;
    }
        
        else if(atHead){
            node<dataType> *newNode = new node(value);
            newNode->next = head;
            head = newNode;
            list_size++;
        }
        
        else {        
            tail->next = new node(value);
            tail = tail->next;
            list_size++;
        }

        return true;
    }

template<class dataType>
void linked_list<dataType> :: printList(void){
    node<dataType> *temp = head;

    while (temp) {
        cout<<temp->data<<" --> ";
        temp = temp->next;
    }
    
    cout<<"NULL\n";
}

 
template<class dataType>
void linked_list<dataType> :: printListRec(node<dataType> *temp){
    if(temp == nullptr){
        cout<<"NULL\n";
        return;
    }

    cout<<temp->data<<" --> ";
    
    printListRec(temp->next);
}

 
template<class dataType>
node<dataType>*  linked_list<dataType> :: getHead(){
    return head;
}

template<class dataType>
bool linked_list<dataType> :: deleteHead(){
    if(!head)
        return false;
    node<dataType> *temp = head;
    head = head->next;
    delete temp;
    list_size--;

    if(!head)
        tail = nullptr;

    return true;
}

template<class dataType>
bool linked_list<dataType> :: deleteEnd(){
    if(head == tail)
        return deleteHead();
    node<dataType> *temp = head, *deleteTemp;

    while (temp->next->next)
        temp = temp->next;
    
    deleteTemp = temp->next;
    temp->next = nullptr;
    delete deleteTemp;
    
    tail = temp;
    list_size--;
    return true;
}

 
template<class dataType>
void linked_list<dataType> :: reverseList(){
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

template<class dataType>
void linked_list<dataType> :: removeDuplicates(){
    if(head == NULL || head->next == NULL)
        return;
    
    node<dataType> *t_head = head;

    while(t_head && t_head->next){
        while(t_head->next && t_head->data == t_head->next->data)
            t_head->next = t_head->next->next;
        t_head = t_head->next;
    }
}

