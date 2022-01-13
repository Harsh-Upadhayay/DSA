#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {10, 12, 10, 15, 10, 20, 12, 12};
    int n = v.size();

    unordered_set<int> elements(v.begin(), v.end());

    unordered_map<int, int> freq;

    for(auto x : v)
        if(!freq.count(x))
            freq[x] = 1;
        else
            freq[x]++;

    for(auto x : freq)
        cout<<x.first<<" : "<<x.second<<endl;
}