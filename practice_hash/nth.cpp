#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int sumExists(int arr[], int N, int sum) {
    unordered_map<int, int> m;
    
    for(int i = 0; i < N; i++)
        m[arr[i]]++;
        
    for(auto x : m)
        if((sum-x.first != x.first) && m[(sum-x.first)])
            return 1;
        else if((sum-x.first == x.first) && x.second > 1)
            return 1;

    return 0;
}

int main(){
    int arr[] = {68, 35, 1};
    cout<<sumExists(arr, 20, 3)<<endl;
}