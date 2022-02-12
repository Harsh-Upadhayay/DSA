#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1 = {10, 15, 20, 5, 30},
                v2 = {30, 5, 30, 80};

    int intersect = 0;  

/* 
    Initial approach
    unordered_set<int> s1(v1.begin(), v1.end()),
                       s2(v2.begin(), v2.end());

    for(auto x : s1)
        if(s2.count(x))
            intersect++;
    
*/

    unordered_map<int, int> m;

    for(auto x : v1)
        m[x] = 1;
    
    for(auto x : v2)
        if(m[x]){
            intersect++;
            m[x] = 0;
        }

    cout<<"Intersection of the two arrays : "<<intersect<<endl;
    
    return 0;
}
