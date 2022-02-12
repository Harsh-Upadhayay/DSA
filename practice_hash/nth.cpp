#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int fun(int arr[], int n, int sum){
    unordered_set<int> preSum;
    int curSum = 0, ctr = 0;
    for(int i = 0; i < n; i++){
        curSum += arr[i];
        if(preSum.count(curSum-sum) || curSum == sum)
            ctr++;
        else
            preSum.insert(curSum);
    }
    return ctr;
}
int fun2(int arr[], int n, int sum) {
    //using map to store the prefix sum which has appeared already.
    unordered_map<int, int> map;
    
    int curr_sum = 0;
    int count=0; unordered_map<int,int>::iterator x;
    
    //iterating over the array elements.
    for (int i = 0; i < n; i++)  {
        //storing prefix sum which is sum of elements till current element.
        curr_sum = curr_sum + arr[i];
        
        //checking if sum up to current element is equal to the given sum.
        if (curr_sum == sum)
        {
            //updating the counter.
            count++;
        }
        //if map contains (curr_sum - sum) i.e. difference of current and 
        //given sum, it means there is a subarray with sum of elements 
        //equal to sum given.
        x=map.find(curr_sum-sum);
        if(x!=map.end())
        //adding number of times (curr_sum - sum) has 
        //appeared in map to the counter.
        count+=x->second;
        
        //storing the prefix sum in map.
        map[curr_sum]++;
    }
    //returning the count of subarrays.
    return count;
    
}

int main(){
    int arr[] = {10,2,-2,-20,10};
    cout<<fun2(arr, 5, -10)<<endl;
}
// -21 + 21+ 30 -7+ 45+ 49 -26 +38+ 4+ 36+ 19 -18+ 19 -40+ 23 -20 -17+ 13