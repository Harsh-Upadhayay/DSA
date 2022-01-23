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
        if(freq[Str[i]] > 1)
            return i;
        
    return -1;
}

/* Optimized Solution */
/* requires one traversal */
int fun2(string &str){
    vector<int> f_idx(CHAR_SIZE, -1);
    int res = INT_MAX;

    for(int i = 0; i < str.size(); i++)
        if(f_idx[str[i]] == -1)
            f_idx[str[i]] = i;
        else
            res = min(f_idx[str[i]], res);

    return (res == INT_MAX)?(-1):res;
}

 
int main(){
    vector<string> queries =  {
                            "geeksforgeeks",
                            "abbcc",
                            "abcd"
                        };
    
    for(auto query : queries)
        cout<<query<<" "<<fun2(query)<<endl;
}