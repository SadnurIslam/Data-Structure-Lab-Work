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

bool isOperand(char s){
    if(s>='0' && s<=57)
        return true;
    return false;
}

double operation(char s, double b, double a){
    if(s=='+'){
        return a+b;
    }
    if(s=='^'){
        return pow(a,b);
    }
    if(s=='-'){
        return a-b;
    }
    if(s=='/' && b!=0){
        return a/b;
    }
    if(s=='*'){
        return a*b;
    }
    return INT_MIN;
}

int main(){
    my_stack st; //creating object
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]==' ' || s[i]==',')
            continue;
        if(isOperand(s[i])){
            st.push(s[i]-'0');
        }
        else{
            double b = st.topp();
            st.pop();
            double a = st.topp();
            st.pop();
            double res = operation(s[i],b,a);
            st.push(res);
        }
    }
    double ans = st.topp();
    cout<<ans <<endl;
}

