#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool fun(string &mainStr, string &subStr){
    int j = 0;
    for(int i = 0; i < mainStr.size(); i++)
        if(mainStr[i] == subStr[j])
            j++;
    
    return (j>=subStr.size());
}

bool fun(string &mainStr, string &subStr, int n, int m){
    
    if(m == 0)
        return true;
    if(n == 0)
        return false;
    
    if(mainStr[n-1] == subStr[m-1])
        return fun(mainStr, subStr, n-1, m-1);
    else
        return fun(mainStr, subStr, n-1, m);
}

int main(){
    vector<pair<string, string>> queries =  {
                        make_pair("ABCD", "AD"),
                        make_pair("ABCDE", "AED")
                        };
    
    for(auto query : queries)
        cout<<query.first<<" "<<fun(query.first, query.second, query.first.size(), query.second.size())<<endl;
}