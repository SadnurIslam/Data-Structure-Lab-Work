#include<bits/stdc++.h>
using namespace std;
int top,mxstk;
double STACK[1000];
class my_stack{
public:
    void push(double item){
        top = top +1;
        STACK[top]=item;
    }

    void pop(){
        top= top -1;
    }
    double topp(){
        return STACK[top];
    }
};

bool isOperand(string s){
    if(s[0]>='0' && s[0]<=57)
        return true;
    return false;
}
double sto(string s){
    double num=0;
    int k = 1;
    for(int i=s.size()-1;i>=0;i--){
        num+= (s[i]-'0')*k*1.0;
        //cout<<num<<endl;
        k=k*10;
    }
    return num;
}

double operation(string s, double b, double a){
    if(s=="+"){
        return a+b;
    }
    if(s=="^"){
        return pow(a,b);
    }
    if(s=="-"){
        return a-b;
    }
    if(s=="/" && b!=0){
        return a/b;
    }
    if(s=="*"){
        return a*b;
    }
    return INT_MIN;
}

int main(){
    my_stack st; //creating object

    string s;
    while(1){
        if(s=="exit")break;
        cin>>s;
        if(isOperand(s)){
            double num = sto(s);
            st.push(num);
            //cout<<num<<endl;
        }
        else{
            double b = st.topp();
            st.pop();
            double a = st.topp();
            st.pop();
            double result = operation(s,b,a);
            st.push(result);
            cout<<result<<endl;
        }
    }
    double ans = st.topp();
    cout<<ans <<endl;
}

