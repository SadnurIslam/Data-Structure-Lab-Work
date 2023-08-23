#include<bits/stdc++.h>
using namespace std;
int top,n;
int STACK[1001];
class my_stack{
public:
    void push(int item){
        if(top==n){
            cout<<"Overflow"<<endl;
            return;
        }
        top = top +1;
        STACK[top]=item;
    }

    void pop(){
        if(top==0){
            cout<<"Underflow"<<endl;
            return;
        }
        top= top -1;
    }
    bool empty(){
        if(top==0){
            return true;
        }
        return false;
    }
};

void display(){
    for(int i=1;i<=top;i++){
        cout<<STACK[i]<<" ";
    }
    cout<<endl;
}

int main(){
    my_stack st; //creating object
    n = 1000;
    for(int i = 1; i<=10;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }

    display();

    // The item to be pushed on stack

    int item;
    cin>>item;
    st.push(item);
    cin>>item;
    st.push(item);
    cin>>item;
    st.push(item);
    display();

    st.pop();
    display();
}
