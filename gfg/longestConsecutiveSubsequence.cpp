#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000001

int fun_MyApproach(vector<int> v){
   int hashTable[MAX] = {0}, len = 0, maxLen = 1;

    for(auto x : v)
        hashTable[x] = 1;
    
    for(int i = 0; i < MAX; i++)
        if(hashTable[i])
            len++;
        else {
            maxLen = max(maxLen, len);
            len = 0;
        }

    return maxLen;
}

int fun_gfgApproach(vector<int> v){
    unordered_set<int> s;
    int len = 1, maxLen = 1;

    for(auto x : v)
        s.insert(x);
    
    for(auto x : s){
        if(!s.count(x-1)){
            while(1)
                if(s.count(x+1)){
                    len++;
                    x += 1;
                }
                else{
                    maxLen = max(len, maxLen);
                    len = 1;
                    break;
                }
        }
    }

    return maxLen;
}

int main(){
    vector<int> v = {1,1,1,1,1,1};
    
    cout<<fun_gfgApproach(v)<<endl;

}