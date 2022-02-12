public class linked_list<dataType>{
    node<dataType> head, tail;
    long list_size;

    public linked_list(){
        head = tail = null;
    }

    public boolean insert(dataType value){
        if(null == head)
            head = tail = new node<dataType>(value);
        else {        
            tail.next = new node<dataType>(value);
            tail = tail.next;
        }
        list_size++;
        return true;
    }

    public boolean insert(dataType value, boolean atHead){

        if(null == head)
            head = tail = new node<dataType>(value);

        else if(atHead){
            node<dataType> newNode = new node<dataType>(value);
            newNode.next = head;
            head = newNode;
        }
        else
            return insert(value);
        
        list_size++;
        return true;
    }

    public void printList(){
        node<dataType> temp = head;
        while(temp != null){
            System.out.print(temp.data + ", ");
            temp = temp.next;
        }
        System.out.println();
    }

    public boolean deleteHead(){
        if(head == null)
            return false;

        head = head.next;
        list_size--;

        if(head == null)
            tail = null;
        return true;
    }

    boolean deleteEnd(){
        if(head == tail)
            return deleteHead();
        node<dataType> temp = head;

        while (temp.next.next != null)
            temp = temp.next;
        
        temp.next = null;
        
        tail = temp;
        list_size--;
        return true;
    }

}
