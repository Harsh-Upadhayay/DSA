#include<iostream>
#include<vector>
using namespace std;

template<class dataType = int>
class node {
    public:
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

    /**
     * @brief inserts the passed element at the end of linked list by default,
     * but if atHead flag is turned on by caller then the element is inserted at 
     * the head.
     * 
     * @param value element to be inserted.
     * @param atHead if set true then insertion occurs at the end
     * @return true if insertion is successfull else false.
     */
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

     /**
     * @brief prints the list iteratively.
     * 
     */
    void printList(void){
        node<dataType> *temp = head;

        while (temp) {
            cout<<temp->data<<" --> ";
            temp = temp->next;
        }
        
        cout<<"NULL\n";
    }

    /**
     * @brief prints the list recursively
     * 
     * @param temp head of linked list
     */
    void printListRec(node<dataType> *temp){
        if(temp == nullptr){
            cout<<"NULL\n";
            return;
        }

        cout<<temp->data<<" --> ";
        
        printListRec(temp->next);
    }

    /**
     * @brief Get the head 
     * 
     * @return node<dataType>* 
     */
    node<dataType>* getHead(){
        return head;
    }

    /**
     * @brief deletes the head of list
     * 
     * @return true if deletion is successful else false
     */
    bool deleteHead(){
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

    node<dataType>** getHeadRef(){
        return &head;
    }

    bool deleteEnd(){
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

    /**
     * @brief reverses the list in O(n) time 
     * and O(1) extra space.
     * 
     */
    void reverseList(){
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

    void removeDuplicates(){
        if(head == NULL || head->next == NULL)
            return;
        
        node<dataType> *t_head = head;

        while(t_head && t_head->next){
            while(t_head->next && t_head->data == t_head->next->data)
                t_head->next = t_head->next->next;
            t_head = t_head->next;
        }
    }
};

// int main(){
//     linked_list<int> myList;
    
//     vector<int> values = {17, 13, 11, 16, 14, 12, 13, 17};

//     for(auto value : values)
//         myList.insert(value);


//     myList.printList();

//     myList.removeDuplicates();

//     myList.printList();

//     // for(int i = 0; i < 10; i++){
//     //     myList.deleteEnd();
//     //     myList.printList();
//     // }

//     // for(auto value : values)
//     //     myList.insert(value);
    
//     // myList.printList();
// }