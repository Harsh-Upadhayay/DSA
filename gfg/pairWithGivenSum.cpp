#include<unordered_set>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {2, 1, 6, 3};
    int sum = 7;
    bool flag = true;

/* 
    Wrong approach
    failed test case : vector<int> v = {2, 1, 6, 3}; int sum = 6; 
    output : Yes the pair is : (3, 3).

    unordered_set<int> s(v.begin(), v.end());

    for(auto x : s)
        if(flag && s.count(sum-x)){
            cout<<"Yes the pair is : ("<<x<<", "<<sum-x<<")\n";
            flag = false;
        }
    
*/

    unordered_set<int> s;

    for(auto x : v){
        if(flag && s.count(sum-x)){
            cout<<"Yes the pair is : ("<<x<<", "<<sum-x<<")\n";
            flag = false;
        }
        else
            s.insert(x);
    }

    if(flag)
        cout<<"Not Present\n";

}