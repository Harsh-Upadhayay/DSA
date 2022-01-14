#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

int fun(vector<int> v, int reqSum){
    unordered_map<int, int> preSum;
    int curSum = reqSum, len = 0;

    for(int i = 0; i < v.size(); i++){
        int x = v[i];
        curSum += x;
        
        if(!(preSum.count(curSum)))
            preSum[curSum] = i;
        else
            len = max(len, i-preSum[curSum]+1);

        if(reqSum == curSum)
            len = i+1;
    }
    
    return len;
}

int main(){
    vector<int> v = {5, 8, -4, -4, 5, -2, 2};
    
    int reqSum = 5;

    cout<<fun(v, reqSum)<<endl;
}