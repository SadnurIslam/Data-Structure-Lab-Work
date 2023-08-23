#include<bits/stdc++.h>
using namespace std;
int front,rear,n;
double QUEUE[6];
class my_queue{
public:
    void push(int item){
        if((front==1 && rear==n) || (front-rear==1)){
            cout<<"Overflow"<<endl;
            return;
        }
        if(empty()){
            front = 1;
            rear = 1;
        }
        else if(rear==n){
            rear=1;
        }
        else rear=rear+1;
        QUEUE[rear]=item;
    }

    void pop(){
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
    int qfront(){
        return QUEUE[front];
    }

    bool empty(){
        if(front==0){
            return true;
        }
        return false;
    }
};

void display(){
    if(front>rear){
        for(int i=front;i<=n;i++){
            cout<<QUEUE[i]<<" ";
        }
        for(int i=1;i<=rear;i++){
            cout<<QUEUE[i]<<" ";
        }
    }
    else{
        for(int i=front;i<=rear;i++){
            cout<<QUEUE[i]<<" ";
        }
    }
    cout<<endl;
}


int main(){
    n = 5;
    my_queue q;

    for(int i=1;i<=5;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    display();
    q.pop();
    display();
    q.pop();
    display();
    q.pop();
    int x;
    cin>>x;
    q.push(x);
    cin>>x;
    q.push(x);
    q.pop();
    display();
    q.pop();
}


