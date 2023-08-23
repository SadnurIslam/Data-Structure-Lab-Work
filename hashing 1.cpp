#include<bits/stdc++.h>
using namespace std;

int size,item;

void setvalue(int Hash[]){
    for(int i=0;i<size;i++){
        Hash[i]=-1;
    }
}

void display(int Hash[]){
    for(int i=0;i<size;i++){
        if(Hash[i]==-1){
            cout<<"none ";
        }
        else
        cout<<Hash[i]<<" ";
    }
    cout<<endl;
}

void linear_probing(int Hash[], int arr[], int n){
    int i,j;
    setvalue(Hash);
    for(i=0;i<n;i++){
        int hv = arr[i]%size;
        if(Hash[hv]==-1){
            Hash[hv]=arr[i];
        }
        else{
            for(j=1;j<size;j++){
                int t = (hv+j)%size;
                if(Hash[t]==-1){
                    Hash[t]=arr[i];
                    break;
                }
            }
        }
    }
    display(Hash);
    int v = item%size;
    for(j=0;j<size;j++){
        int t = (v+j)%size;
        if(Hash[t]==-1){
            cout<<"Doesn't exist"<<endl;
            break;
        }
        else if(Hash[t]==item){
            cout<<"Found at "<<t<<endl;
            break;
        }
        else continue;
    }
    if(j==size){
        cout<<"Doesn't exist"<<endl;
    }
}

void plus3_probing(int Hash[], int arr[], int n){
    int i,j;
    setvalue(Hash);
    for(i=0;i<n;i++){
        int hv = arr[i]%size;
        if(Hash[hv]==-1){
            Hash[hv]=arr[i];
        }
        else{
            for(j=1;j<size;j++){
                int t = (hv+j*3)%size;
                if(Hash[t]==-1){
                    Hash[t]=arr[i];
                    break;
                }
            }
        }
    }
    display(Hash);
    int v = item%size;
    for(j=0;j<size;j++){
        int t = (v+j*3)%size;
        if(Hash[t]==-1){
            cout<<"Doesn't exist"<<endl;
            break;
        }
        else if(Hash[t]==item){
            cout<<"Found at "<<t<<endl;
            break;
        }
        else continue;
    }
    if(j==size){
        cout<<"Doesn't exist"<<endl;
    }
}

void quadratic_probing(int Hash[], int arr[], int n){
    int i,j;
    setvalue(Hash);
    for(i=0;i<n;i++){
        int hv = arr[i]%size;
        if(Hash[hv]==-1){
            Hash[hv]=arr[i];
        }
        else{
            for(j=1;j<size;j++){
                int t = (hv+j*j)%size;
                if(Hash[t]==-1){
                    Hash[t]=arr[i];
                    break;
                }
            }
        }
    }
    display(Hash);
    int v = item%size;
    for(j=0;j<size;j++){
        int t = (v+j*j)%size;
        if(Hash[t]==-1){
            cout<<"Doesn't exist"<<endl;
            break;
        }
        else if(Hash[t]==item){
            cout<<"Found at "<<t<<endl;
            break;
        }
        else continue;
    }
    if(j==size){
        cout<<"Doesn't exist"<<endl;
    }
}

void chaining(int arr[], int n){
    int i,j;
    vector<int>Hash[size];
    for(i=0;i<n;i++){
        int hv = arr[i]%size;
        Hash[hv].push_back(arr[i]);
    }
    for(i=0;i<size;i++){
        int k =0;
        for(j=0;j<Hash[i].size();j++){
            cout<<Hash[i][j]<<" ";
            k++;
        }
        if(k==0)cout<<"none ";
        cout<<endl;
    }
    int k=0;
    for(i=0;i<size;i++){
        for(j=0;j<Hash[i].size();j++){
            if(Hash[i][j]==item){
                k++;
                break;
            }
        }
        if(k)break;
    }
    if(k)cout<<"found at "<<i<<endl;
    else cout<<"doesn't exist"<<endl;
}


int main(){
    int n,i;
    cin>>n>>size;
    int arr[n],Hash[size];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Search item : ";
    cin>>item;
    linear_probing(Hash,arr,n);
    plus3_probing(Hash,arr,n);
    quadratic_probing(Hash,arr,n);
    chaining(arr,n);
    return 0;
}
