#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool fun(string &firstStr, string &secondStr){
    int freq[26] = {0};

    for(auto x : firstStr)
        freq[x - 'a']++;

    for(auto x : secondStr)
        freq[x - 'a']--;

    for(int i = 0; i < 26; i++)
        if(freq[i])
            return false;
    
    return true;
}



int main(){
    vector<pair<string, string>> queries =  {
                        make_pair("listen", "silent"),
                        make_pair("aaacb", "cabaa"),
                        make_pair("aab", "bab")
                        };
    
    for(auto query : queries)
        cout<<query.first<<" "<<fun(query.first, query.second)<<endl;
}