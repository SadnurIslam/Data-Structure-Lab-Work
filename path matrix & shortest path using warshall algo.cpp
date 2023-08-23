#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,i,j,k;
    cout<<"number of nodes: ";
    cin>>m;
    int P[m+1][m+1][m+1];
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            P[0][i][j]=0;
        }
    }
    cout<<"number of edges ";
    int e;
    cin>>e;
    for(i=1;i<=e;i++){
        int from,to;
        cin>>from>>to;
        P[0][from][to]=1;
    }
    for(k=1;k<=m;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                P[k][i][j]=P[k-1][i][j] | P[k-1][i][k] & P[k-1][k][j];
            }
        }
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            cout<<P[m][i][j]<<" ";
        }
        cout<<endl;
    }
}
