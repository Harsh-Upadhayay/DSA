#include<bits/stdc++.h>
using namespace std;

int *findTwoElement(int *a, int n) {
    int *ar = (int*)malloc(2*sizeof(int));
    vector<int> arr(a, a+n);
    for(int i = 0; i < n; i++)
        arr[i]--;
    int x = 0;
    for(int i = 0; i < n; i++)
        if(x != -1){
            auto t = arr[x];
            arr[x] = -1;
            x = t;
        }
        else{
            ar[1] = i+1;
        }
    
    for(int i = 0; i < n; i++)
        if(arr[i] != -1)
            ar[0] = i+1;
    // cout<<ar[0]<<ar[1];
    return ar;
    // 12 21
}

int main(){
    int ar[] = {13, 33, 43, 16, 25, 19, 23, 31, 29, 35, 10, 2, 32, 11, 47, 15, 34, 46, 30, 26, 41, 18, 5, 17, 37, 39, 6, 4, 20, 27, 9, 3, 8, 40, 24, 44, 14, 36, 7, 38, 12, 1, 42, 12, 28, 22, 45};
    int n = sizeof(ar)/sizeof(ar[0]);
    int *x = findTwoElement(ar, n);
    cout<<(x[0])<<" "<<(x[1]);
    cout<<endl;
}