#include<iostream>
#include<string>

using namespace std;

#define CHAR 256

bool isEqual(int *a, int *b){
    for(int i = 0; i < CHAR; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

/**
 * @brief finds if given substring's anagram is present in 
 * the main string.
 * 
 * @param str main string
 * @param subStr sub string
 * @return true if match is found, else false.
 */
bool fun(string &str, string &subStr){
    int n = str.size(), m = subStr.size();
    int pat_freq[CHAR] = {0}, str_freq[CHAR] = {0};

    for(int i = 0; i < m; i++){
        pat_freq[subStr[i]]++;
        str_freq[str[i]]++;
    }
    
    for(int i = m; i < n-m+1; i++){
        if(isEqual(pat_freq, str_freq))
            return true;
        str_freq[str[i]]++;
        str_freq[str[i-m]]--;
    }

    return false;
}

int main(){
    string s1 = "geeksforgeeks", s2 = "frog";
    cout<<fun(s1, s2)<<endl;
}