/*
** Handling of collision via open addressing
** Method for Probing: Double Hashing
*/

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define MAX_SIZE 10000001ll

class doubleHash {

    int TABLE_SIZE, PRIME;
    bitset<MAX_SIZE> isPrime;

    void __setSieve(){
        isPrime[0] = isPrime[1] = 1;
        for(long long i = 2; i*i <= MAX_SIZE; i++)
            if(isPrime[i] == 0)
                for(long long j = i*i; j <= MAX_SIZE; j += i)
                    isPrime[j] = 1;

    }

    int hash1(int value){
        return value%TABLE_SIZE;
    }
    
    int hash2(int value){
        return (5);
    }

    public: 

    doubleHash(int n){
        __setSieve();
        TABLE_SIZE = n;
        
    }

    void __printPrime(long long n){
        for(long long i = 0; i <= n; i++)
            if(isPrime[i] == 0)
                cout<<i<<", ";
        cout<<endl;
    }
};

int main(){
    doubleHash A(5);
    A.__printPrime(100);
}