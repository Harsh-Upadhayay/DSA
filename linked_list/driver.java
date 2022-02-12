
public class driver {
    public static void main(String[] args){
        linked_list<Integer> myList = new linked_list<Integer>();

        Integer []values = {11, 12, 13};
        
        for (Integer value : values) {
            myList.insert(value);
        }
        myList.insert(14);
        myList.printList();
    }
}
