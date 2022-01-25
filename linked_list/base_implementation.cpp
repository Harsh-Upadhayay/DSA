#include<iostream>
#include<vector>
using namespace std;

template<class dataType = int>
class node {
    dataType data;
    node *next;

    node(){
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
    unsigned long long list_size;

    public:

    linked_list(void){
        head = tail = nullptr;
        list_size = 0;
    }

    bool insert(dataType value, bool atHead = false){
        
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

    void printList(void){
        node<dataType> *temp = head;

        while (temp) {
            cout<<temp->data<<", ";
            temp = temp->next;
        }
        
        cout<<endl;
    }

    void printListRec(node<dataType> *temp){
        if(temp == nullptr){
            cout<<endl;
            return;
        }

        cout<<temp->data<<", ";
        
        printListRec(temp->next);
    }

    node<dataType>* getHead(){
        return head;
    }

    bool deleteHead(){
        if(!head)
            return false;
        node<dataType> *temp = head;
        head = head->next;
        delete temp;
        list_size--;

        return true;
    }
};


int main(){
    linked_list<int> myList;
    
    vector<int> values = {11, 12, 13};

    for(auto value : values)
        myList.insert(value);

    myList.insert(14, true);
    myList.deleteHead();

    myList.printList();
}