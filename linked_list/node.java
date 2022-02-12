class node<dataType> {
    public dataType data;
    public node<dataType> next;

    public node(){
        next = null;
    }
    public node(dataType value){
        data = value;
        next = null;
    }
}
