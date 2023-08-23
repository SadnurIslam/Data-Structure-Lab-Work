#define pb push_back
#include <iostream>
#include <vector>
#include<stack>

using namespace std;

vector<int>graph[1000];
stack<int>s;
bool vis[1000];

void dfs(){
    int top = s.top();
    vis[top]=true;
    s.pop();
    cout<<char(top+64)<<" ";
    for(int i=0;i<graph[top].size();i++){
        if(vis[graph[top][i]]==false){
            vis[graph[top][i]]=true;
            s.push(graph[top][i]);
        }
    }
    if(!s.empty())
        dfs();
}

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

    //display(v);
    s.push(8); //find the reachable node from node 8
    dfs();

    return 0;
}


