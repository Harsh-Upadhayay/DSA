#include<iostream>
#include<string>
#include<climits>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define CHAR_SIZE 256

int bsearch(vector<int> &v, int x){
    int l = 0, r = v.size()-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(v[mid] < x){
            l = mid + 1;
        }
        else if(v[mid] > x){
            r = mid-1;
        }
        else{
            return (mid);
        }
    }
    return l;
}

/* first approach */
/* Didn't work, wasted a lot of time here */
char fun(vector<int> &v){
    vector<int> temp(v.begin(), v.end());
    sort(temp.begin(), temp.end());
    int prevSpan = 0, curSpan = 0;

    for(int i = 0; i < v.size(); i++){
        if(prevSpan){
            curSpan = ((v[i] >= v[i-1])?(prevSpan+1):1);
            prevSpan = curSpan;
        }
        else
            prevSpan = curSpan = 1;
        
        cout<<curSpan<<" ";
    }
    
    return '\n';
}

/* Their approach, My Solution : O(nlog(n))*/

char fun2(vector<int> &v){
    map<int, int> m;
    vector<int> ans;
    for(int i = 0; i < v.size(); i++){
        if(!i){
            ans.push_back(1);
            m[v[i]] = i;
        }
        else {
            if(m.upper_bound(v[i])!=m.end())
                ans.push_back(i-(m.upper_bound(v[i])->second));
            else
                ans.push_back(i+1);
            m[v[i]] = i;
        }
    }
    for(auto x : ans)
        cout<<x<<" ";
    return '\n';
}
 
int main(){
    vector<vector<int>> queries =  {
                            {13, 15, 12, 14, 16, 8, 6, 4, 10, 30},
                            {60, 10, 20, 40, 35, 30, 50, 70, 65}
                        };
    

    for(auto query : queries)
        cout<<*(query.begin())<<" : "<<fun2(query)<<endl;
}