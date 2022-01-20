#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

void fun_MyApproach(vector<int> v, int k){
    unordered_map<int, int> s;
    
    for(auto x : v)
        s[x]++;
    
    for(auto x : s)
        if(x.second > ceil(v.size()/k))
            cout<<x.first<<" ";

    cout<<endl;
}

void fun_gfgApproach(vector<int> v, int maxLen){
    unordered_map<int, int> freq;

    for(int i = 0; i < v.size(); i++){

        if(i >= maxLen){
            cout<<freq.size()<<" ";
            freq[v[i]]++;
            freq[v[i-maxLen]]--;
            if(!freq[v[i-maxLen]])
                freq.erase(v[i-maxLen]);
        }
        else
            freq[v[i]]++;
    }
    cout<<freq.size()<<endl;
}

int main(){
    vector<int> v = {1, 2, 2, 2, 1, 1};
    auto k = 3;
    fun_MyApproach(v, k);

}