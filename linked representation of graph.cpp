#define pb push_back
#include <iostream>
#include <vector>

using namespace std;

vector<int>graph[1000];

void display(int v){
    for(int i=1;i<=v;i++){
        int n = graph[i].size();
        cout<<"Adjacency list of vertex "<<i<<" : ";
        if(n==0){
            cout<<"null"<<endl;
        }
        else{
            for(int j=0;j<n;j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main() {

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
    }

    display(v);

    return 0;
}

