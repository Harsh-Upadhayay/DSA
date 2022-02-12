#include<iostream>
#include<vector>
using namespace std;


template<class dataType = int>
class node {
    dataType data;
    node *next;

    node();
    node(dataType value);
    friend class linked_list<dataType>;
};

template<class dataType = int>
class linked_list {
    node<dataType> *head, *tail;

    public:

    linked_list(void){
        head = tail = nullptr;
    }

    bool insert(dataType value);

};
