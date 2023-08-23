#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)cin>>arr[i];
    int r,c;
    cin>>r>>c;
    int pre = ((r-1)*r)/2;
    pre+=c;
    cout<<arr[pre-1];
    cin>>r;
    pre = ((r-1)*r)/2;
    for(i=pre;i<pre+r;i++){
        cout<<arr[i]<<" ";
    }
}

