#include<iostream>
#include<string>
#include<climits>
#include<vector>
using namespace std;

#define CHAR_SIZE 256

/* first approach */
/* requires two traversal */
int fun(string &Str){
    int freq[CHAR_SIZE] = {0};

    for(auto x : Str)
        freq[x]++;
    
    for(int i = 0; i < Str.size(); i++)
        if(freq[Str[i]] == 1)
            return i;
        
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