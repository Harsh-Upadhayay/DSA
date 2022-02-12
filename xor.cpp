#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int t = 32;
    for(int i = 0; i < t; i++){
        cout<<setw(3)<<i<<", "<<setw(3)<<(i+1)<<" : "<<setw(3)<<((i)^(i+1))<<endl;
    }
}