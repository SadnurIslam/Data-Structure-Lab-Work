#define inf INT_MAX
#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,i,j,k;
    cout<<"number of nodes: ";
    cin>>m;
    long long int Q[m+1][m+1][m+1];
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            Q[0][i][j]=inf;
        }
    }
    cout<<"number of edges ";
    int e;
    cin>>e;
    for(i=1;i<=e;i++){
        int from,to,w;
        cin>>from>>to>>w;
        Q[0][from][to]=w;
    }
    for(k=1;k<=m;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                Q[k][i][j]=min(Q[k-1][i][j], Q[k-1][i][k] + Q[k-1][k][j]);
            }
        }
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            cout<<Q[m][i][j]<<" ";
        }
        cout<<endl;
    }
}

