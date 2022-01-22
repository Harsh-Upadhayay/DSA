#include<iostream>
#include<string>
using namespace std;

bool fun(string s){
    int n = s.size();
    for(int i = 0; i < n/2; i++)
        if(s[i] != s[n-i-1])
            return false;
    return true;
}

int main(){
    string queries[] =  {
                        "ABCDCBA",
                        "ABBA", 
                        "geeks"
                        };
    for(auto query : queries)
        cout<<query<<" "<<fun(query)<<endl;
}