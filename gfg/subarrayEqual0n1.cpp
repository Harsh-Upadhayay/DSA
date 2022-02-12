#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int fun(string s){
    int curSum = 0, len = 0;
    unordered_map<int, int> preSum;
    
    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == '1')
           curSum++;
        else
            curSum--;
        
        if(!preSum.count(curSum))
            preSum[curSum] = i;
        else
            len = max(len, i - preSum[curSum]);
        
        if(0 == curSum)
            len = i+1;
    }

    return len;
}

int main(){
    string s = "0011011010";
    cout<<fun(s)<<endl;
}