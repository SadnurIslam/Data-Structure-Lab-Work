#define pb push_back
#include <iostream>
#include <vector>
#include<stack>

using namespace std;

int top,n;
int STACK[1001];
    void s_push(int item){
        if(top==n){
            cout<<"Overflow"<<endl;
            return;
        }
        top = top +1;
        STACK[top]=item;
    }

    void s_pop(){
        if(top==0){
            cout<<"Underflow"<<endl;
            return;
        }
        top= top -1;
    }
    bool s_empty(){
        if(top==0){
            return true;
        }
        return false;
    }

    int s_top(){
        return STACK[top];
    }



vector<int>graph[1000];
bool vis[1000];

void dfs(){
    int top = s_top();
    vis[top]=true;
    s_pop();
    cout<<char(top+64)<<" ";
    for(int i=0;i<graph[top].size();i++){
        if(vis[graph[top][i]]==false){
            vis[graph[top][i]]=true;
            s_push(graph[top][i]);
        }
    }
    if(!s_empty())
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
    n=100;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
    }

    //display(v);
    s_push(8); //find the reachable node from node 8
    dfs();

    return 0;
}



