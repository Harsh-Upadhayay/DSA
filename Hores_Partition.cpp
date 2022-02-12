#include <iostream>

using namespace std;

typedef int Data_type;

Data_type partition(Data_type *arr, Data_type l, Data_type r){
    Data_type pivot = arr[l], i = l-1, j = r+1;
    while(1){
        do
            i++;
        while (arr[i] < pivot);
        do
            j--;
        while (arr[j] > pivot);
        
        if(i >= j)
            return j;
                
        swap(arr[i], arr[j]);
        
    }
}

int main(){
    int arr[] = {5,3,8,4,2,7,1,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    partition(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}