#include<iostream>
#include<string>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

#define CHAR_SIZE 256

/* first approach */
char fun(string &Str){
    string word = "";

    for(int i = Str.size()-1; i >= 0; i--){
        char x = Str[i];
        if(x != ' ')
            word += x;
        else{
            reverse(word.begin(), word.end());
            cout<<word<<" ";
            word = "";
        }
    }
    reverse(word.begin(), word.end());
    cout<<word;
    return '\n';
}

/* efficient approach */
string fun2(string &str){
    int startIdx = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            reverse(str.begin()+startIdx, str.begin()+i);
            startIdx = i+1;
        }
    }
    reverse(str.begin()+startIdx, str.end());
    reverse(str.begin(), str.end());
    return str;
}

 
int main(){
    vector<string> queries =  {
                            "welcome to gfg",
                            "I love coding",
                            "abc"
                        };
    
    for(auto query : queries)
        cout<<query<<" : "<<fun2(query)<<endl;
}