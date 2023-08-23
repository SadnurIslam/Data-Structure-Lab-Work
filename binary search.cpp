#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[13]={0,1,2,4,4,6,7,8,9,10,11,12,13};
    int n = 13,loc;
    int beg=0;
    int en = 12;
    int mid = (beg+en)/2;
    int item = 4;
    while(beg<=en && arr[mid]!=item){
        if(item<arr[mid])
            en=mid-1;
        else beg=mid+1;
        mid=(beg+en)/2;
    }
    if(beg>en)cout<<"doesn't exist"<<endl;
    else cout<<mid <<endl;
}

