#include<iostream>
#include<vector>
using namespace std;

template<class dataType = int>
class node {
    dataType data;
    node *next;

    node(){
        data = -1;
        next = nullptr;
    }
    node(dataType value){
        data = value;
        next = nullptr;
    }
    template<class T>
    friend class linked_list;
};

template<class dataType = int>
class linked_list {
    node<dataType> *head, *tail;

    public:

    linked_list(void){
        head = tail = nullptr;
    }

    bool insert(dataType value){
        if(nullptr == head)
            head = tail = new node(value);
        else {        
            tail->next = new node(value);
            tail = tail->next;
        }
        return true;
    }

};


int main(){
    linked_list<int> myList;
    
    vector<int> values = {11, 12, 13};

    for(auto value : values)
        myList.insert(value);

}