#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[13]={4,5,2,88,4,32,11,99,0,654,3,1,2};
    int n = 13;
    for(int i = 0; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    cout<<n<<endl;
    for(int i = 0; i< n;i++){
        cout<<arr[i]<<" ";
    }
}
