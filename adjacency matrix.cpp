#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,i,j,k;
    cout<<"number of nodes: ";
    cin>>m;
    int A[m+1][m+1][m+1],B[m+1][m+1];
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            A[1][i][j]=0;
            B[i][j]=0;
        }
    }
    cout<<"number of edges ";
    int e;
    cin>>e;
    for(i=1;i<=e;i++){
        int from,to;
        cin>>from>>to;
        A[1][from][to]=1;
    }
    for(int x = 2;x<=m;x++){
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                int sum = 0;
                for(k=1;k<=m;k++){
                    sum+=A[1][i][k]*A[x-1][k][j];
                }
                A[x][i][j]=sum;
            }
        }
    }
    for(k=1;k<=m;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                cout<<"Number of paths of length "<<k<<" from v"<<i<<" to v"<<j <<" is "<<A[k][i][j]<<endl;
                B[i][j]+=A[k][i][j];
            }
        }
        cout<<endl;
    }

    //path matrix
    int P[m+1][m+1], connected=1;
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            if(B[i][j]){
                P[i][j]=1;
            }
            else{
                P[i][j]=0;
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            cout<<P[i][j]<<" ";
            if(P[i][j]==0){
                connected=0;
            }
        }
        cout<<endl;
    }
    if(connected){
        cout<<"Connected"<<endl;
    }
    else{
        cout<<"Not Connected"<<endl;
    }
}
