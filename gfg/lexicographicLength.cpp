#include<iostream>
#include<string>
#include<climits>
#include<vector>
using namespace std;

#define CHAR_SIZE 256


int fun(string &Str){
    int freq[CHAR_SIZE] = {0}, preSum[CHAR_SIZE] = {0};

    for(auto x : Str)
        freq[x]++;
    
    preSum[0] = freq[0];
    for(int i = 1; i < CHAR_SIZE; i++)
        preSum[i] += (preSum[i-1] + freq[i]);
    

        
    return -1;
}


 
int main(){
    vector<string> queries =  {
                            "geeksforgeeks",
                            "abbcc",
                            "abcd"
                        };
    
    for(auto query : queries)
        cout<<query<<" "<<fun(query)<<endl;
}