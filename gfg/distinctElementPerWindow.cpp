#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

string stringify(int a, int b){
    string ans = "";
    ans += a;
    ans += '-';
    ans += b;
    return ans;
}

/* wrong */
void fun_MyApproach(vector<int> v, int maxLen){
    unordered_set<string> s;
    int winLen = 0;
    bool winFormed = false;

    for(int i = 0; i < v.size(); i++){    
            
        if(i >= maxLen){
            cout<<s.size()<<" ";
            s.insert(stringify(v[i], i/maxLen));
            s.erase(stringify(v[i-maxLen], (i-maxLen)/maxLen));
        }
        else
            s.insert(stringify(v[i], i/maxLen));       
        
    }
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
    vector<int> v = {1, 2, 2, 1, 1};
    auto maxLen = 2;
    fun_gfgApproach(v, maxLen);

}