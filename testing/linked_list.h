template<class dataType>
class node {
    dataType data;
    node *next;

    node();
    node(dataType value);

    template<class T>
    friend class linked_list;
};

template<class dataType>
class linked_list {
    node<dataType> *head, *tail;
    unsigned long long list_size;

    public:

    linked_list(void);

    /**
     * @brief inserts the passed element at the end of linked list by default,
     * but if atHead flag is turned on by caller then the element is inserted at 
     * the head.
     * 
     * @param value element to be inserted.
     * @param atHead if set true then insertion occurs at the end
     * @return true if insertion is successfull else false.
     */
    bool insert(dataType value, bool atHead = false);

    /**
     * @brief prints the list iteratively.
     * 
     */
    void printList(void);

    /**
     * @brief prints the list recursively
     * 
     * @param temp head of linked list
     */
    void printListRec(node<dataType> *temp);

    /**
     * @brief Get the head 
     * 
     * @return node<dataType>* 
     */
    node<dataType>* getHead();

    /**
     * @brief deletes the head of list
     * 
     * @return true if deletion is successful else false
     */
    bool deleteHead();

    bool deleteEnd();

    /**
     * @brief reverses the list in O(n) time 
     * and O(1) extra space.
     * 
     */
    void reverseList();
    void removeDuplicates();
};



