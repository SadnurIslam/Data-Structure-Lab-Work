#define pb push_back
#include <iostream>
#include <vector>
#include<stack>

using namespace std;

int front,rear,n;
int QUEUE[1000];

bool q_empty(){
        if(front==0){
            return true;
        }
        return false;
    }


    void q_push(int item){
        if((front==1 && rear==n) || (front-rear==1)){
            cout<<"Overflow"<<endl;
            return;
        }
        if(q_empty()){
            front = 1;
            rear = 1;
        }
        else if(rear==n){
            rear=1;
        }
        else rear=rear+1;
        QUEUE[rear]=item;
    }

    void q_pop(){
        if(front==0){
            cout<<"Underflow"<<endl;
            return;
        }
        if(front==rear){
            front=0;
            rear=0;
        }
        else if(front==n){
            front==1;
        }
        else front = front + 1;
    }
    int q_front(){
        return QUEUE[front];
    }




vector<int>graph[1000];
bool vis[1000];

void bfs(){
    int front = q_front();
    vis[front]=true;
    q_pop();
    cout<<char(front+64)<<" ";
    for(int i=0;i<graph[front].size();i++){
        if(vis[graph[front][i]]==false){
            vis[graph[front][i]]=true;
            q_push(graph[front][i]);
        }
    }
    if(!q_empty())
        bfs();
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
    q_push(1);
    bfs();

    return 0;
}




