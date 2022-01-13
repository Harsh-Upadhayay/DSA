#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[] = {15, 12, 13, 12, 13, 13, 18}, n = sizeof(ar)/sizeof(ar[0]);
    // unordered_set<int> freq;
    // int distinctElement = 0;
    // for(auto x : ar){
    //     if(freq.count(x))
    //         continue;
    //     freq.insert(x);
    //     distinctElement++;
    // }

    /* shorter implementation */

    unordered_set<int> freq(ar, ar+n);
    auto distinctElement = freq.size();

    cout<<"Number of distinct elements : "<<distinctElement;
}