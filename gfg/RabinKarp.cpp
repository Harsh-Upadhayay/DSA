#include<iostream>
#include<string>
#include<climits>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

#define CHAR_SIZE 256
#define weight 2

/**
 * @brief hash function for rabin karp algorithm.
 * @remark time complexity = O(n).
 * @param str string whose hash is to be calculated.
 * @return integer hash of given string. 
 */
int str_hash(string &str){
    int hash = 0, n = str.size();

    for(int i = 0; i < n; i++)
        hash += ((int)str[i] * pow(weight, n-i-1));
    
    return hash;
}

/**
 * @brief rolling hash function for rabin karp algorithm.
 * @remark time complexity = O(1).
 * @return integer hash of given string. 
 */
#define roll_hash(cur_hash, pos) (weight*(cur_hash - (int)str[pos-sub_str.size()]*pow(weight, sub_str.size()-1)) + (int)str[pos])



/**
 * @param str main string
 * @param sub_str substring
 * @bug won't work for larger strings INTEGER OVERFLOW.
 * @brief slides window over the string to compare them by using rolling hash.  
 * hash("abc") = a*(d^2) + b*(d^1) + c*(d^0), where d can be any constant.
 * 
 * @return number of matched subsequences 
 */
int fun(string &str, string &sub_str){


    string cur_str = "";
    int check_hash = str_hash(sub_str);
    int temp_hash = -1, total_match = 0;

    for(int i = 0; i < str.size(); i++){
        cur_str += str[i];

        if(cur_str.size() >= sub_str.size()){
            if(-1 == temp_hash)
                temp_hash = str_hash(cur_str);
            else
                temp_hash = roll_hash(temp_hash, i);
            
            if(temp_hash == check_hash){
                int j;
                for(j = 0; j < sub_str.size(); j++)
                    if(sub_str[j] != str[i-sub_str.size()+1+j])
                        break;
                if(j == sub_str.size()){
                    cout<<(i-sub_str.size()+1)<<" ";
                    total_match++;
                }
            }
        }
    }
    cout<<"\n";
    return total_match;
}



int main(){
    vector<pair<string, string>> queries =  {
                        make_pair("AAAA", "AAA"),
                        make_pair("ABABABCD", "ABAB"),
                        make_pair("ABCABCD", "ABCD")
                        };
    
    for(auto query : queries)
        cout<<query.first<<" \n"<<fun(query.first, query.second)<<endl;
}