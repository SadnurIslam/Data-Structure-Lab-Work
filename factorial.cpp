#include<bits/stdc++.h>
using namespace std;

long long int fact(long long int n){
    if(n==1 || n==0)return n;
    return n*fact(n-1);
}

int main(){
    long long int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Factorial of the number = "<<fact(n)<<endl;
}
