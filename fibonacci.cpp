#include<bits/stdc++.h>
using namespace std;

long long int fibo(long long int n){
    if(n==1 || n==0)return n;
    return fibo(n-1)+fibo(n-2);
}

int main(){
    long long int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Fibanacci of the number = "<<fibo(n)<<endl;
}

