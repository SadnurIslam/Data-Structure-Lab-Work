#include<bits/stdc++.h>
using namespace std;
int size;
class node{
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        size++;
        return;
    }
    n->next = head;
    head = n;
    size++;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        size++;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
    size++;
}

void insertAtPos(node* &head, int val, int pos){

    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    if(pos==size+1){
        insertAtTail(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    int k = 1;
    while(temp!=NULL){
        k++;
        if(k==pos){
            break;
        }
        temp=temp->next;
    }
    if(pos>size+1){
        cout<<"No such position exist"<<endl;
        return;
    }
    n->next=temp->next;
    temp->next = n;
    size++;
}

bool search(node* head, int item){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data == item){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deletion(node* &head, int val){
    node* temp = head;
    if(head->data==val){
        head=head->next;
        return;
    }
    node* prev = NULL;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            break;
        }
        temp=temp->next;
    }
    temp->next = temp->next->next;
}

node* reverse(node* &head){
    node* pre = NULL;
    node* next;
    node* cur = head;

    while(cur!=NULL){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void sort(node* &head){
    node* i, *j;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,4);
    display(head);
    insertAtPos(head,10,2);
    display(head);
    insertAtPos(head,11,1);
    display(head);
    insertAtPos(head,12,7);
    display(head);
    insertAtPos(head,13,7);
    display(head);
    insertAtPos(head,13,10);
    display(head);
    cout<<search(head,4)<<endl;
    cout<<search(head,14)<<endl;
    deletion(head,12);
    display(head);
    deletion(head,4);
    display(head);
    deletion(head,11);
    display(head);
    head = reverse(head);
    display(head);
    sort(head);
    display(head);
}

