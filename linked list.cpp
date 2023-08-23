#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
};

int main(){
    node* head = new node();
    node* one = NULL;
    node* two = NULL;
    node* three = NULL;
    one = new node();
    two = new node();
    three = new node();
    one->data = 4;
    two->data = 5;
    three->data = 1;
    one->next = two;
    two->next = three;
    head = one;
    while(head!=NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}
