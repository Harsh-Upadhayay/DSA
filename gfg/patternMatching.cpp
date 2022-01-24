#include<iostream>
#include<string>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

#define CHAR_SIZE 256

bool myComp(string &s1, string &s2, int start){
    // if(s1.size() != (s2.size() - start))
    //     return false;
    
    for(auto x : s1){
        if(x != s2[start++])
            return false;
    }
    return true;
}

/* first approach */
char fun(string &str, string &subStr){
    
    for(int i = 0; i < str.size()-subStr.size(); i++){
        if(myComp(subStr, str, i) == 0)
            cout<<i<<" ";
    }
    return '\n';
}


 
int main(){
    vector<pair<string, string>> queries =  {
                        make_pair("AAAA", "AAA"),
                        make_pair("ABABABCD", "ABAB"),
                        make_pair("ABCABCD", "ABCD")
                        };
    
    for(auto query : queries)
        cout<<query.first<<" "<<fun(query.first, query.second)<<endl;
}