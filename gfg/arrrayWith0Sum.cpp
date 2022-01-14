#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

bool fun(vector<int> v, int reqSum){
    unordered_set<int> preSum;
    int curSum = 0;
    for(auto x : v){
        curSum += x;
        if(!(preSum.count(curSum - reqSum)))
            preSum.insert(curSum);
        else
            return true;
        if(reqSum == curSum)
            return true;  
    }
    return false;}

int main(){
    vector<int> v = {5, 8, 6, 13, 3, -1};
    
    int reqSum = 2;

    cout<<fun(v, reqSum);
}