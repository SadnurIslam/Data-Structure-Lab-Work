#define pb push_back
#include <iostream>
#include <vector>
#include<stack>
#include<queue>

using namespace std;

vector<int>graph[1000];
bool vis[1000];
queue<int>q;

void bfs(){
    int front = q.front();
    vis[front]=true;
    q.pop();
    cout<<char(front+64)<<" ";
    for(int i=0;i<graph[front].size();i++){
        if(vis[graph[front][i]]==false){
            vis[graph[front][i]]=true;
            q.push(graph[front][i]);
        }
    }
    if(!q.empty())
        bfs();
}

int main() {

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
    }

    q.push(1);
    bfs();

    return 0;
}





