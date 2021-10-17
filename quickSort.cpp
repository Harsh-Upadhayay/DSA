#include <iostream>

using namespace std;

typedef int dataType;

int n, k = 0;

void printArr(dataType* arr, dataType n){
    cout<<(++k)<<": ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void swapP(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

dataType partition(dataType *arr, dataType l, dataType r){
    dataType pivot = arr[r], i = l-1, j;

    for(int j = 0; j < r; j++)
        if(arr[j] <= pivot)
            swap(arr[j], arr[++i]);    
    
    swap(arr[i+1], arr[r]);
    return i+1;    
}

void qSort(dataType *arr, dataType l, dataType r){
    if(l < r){
        dataType m = partition(arr, l, r);
        qSort(arr, l, m-1);
        qSort(arr, m+1, r);        
    }
}

int main(){
    int arr[] = {5,4,3,2,1};
    n = sizeof(arr)/sizeof(arr[0]);
    qSort(arr, 0, n-1);
    printArr(arr, n);
    return 0;
}