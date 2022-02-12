#include<vector>
#include<iostream>
using namespace std;


vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        vector<int> table(hashSize, -1);
        for(int i = 0; i < sizeOfArray; i++){
            
            int key = arr[i]%hashSize;
            
            while(table[key] != -1)
                key = ((key + 1)%hashSize);
            
            table[key] = arr[i];
        }
        return table;
    }

int main(){
    int ar[] = {4, 14, 24, 44};
    vector<int> v = linearProbing(10, ar, 4);
    for(int i = 0; i< v.size(); i++)
        cout<<v[i]<<" ";
    }