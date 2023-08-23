#include<bits/stdc++.h>
using namespace std;

int size;

void heapify(int tree[],int k){
    int pos = k;
    int left = pos*2+1;
    int right = pos*2+2;
    if(left<size && tree[pos]<tree[left]){
        pos=left;
    }
    if(right<size && tree[pos]<tree[right]){
        pos=right;
    }
    if(pos!=k){
        swap(tree[k],tree[pos]);
        heapify(tree,pos);
    }
}

void deletion(int tree[],bool booli[], int item){
    int pos = size;
    for(int i = 0;i<size;i++){
        if(tree[i]==item){
            pos=i;
            break;
        }
    }
    if(pos==size){
        cout<<"Doesn't exist"<<endl;
        return;
    }
    swap(tree[pos],tree[size-1]);
    size--;
    booli[size]=false;
    heapify(tree,pos);
}

void display(int tree[],bool booli[]){		//works better with single-digit nodes.
	int i, j, space, lineGap, level = log2(size+1);
	for(i=0; i<=level; i++){					//levels
		for(j=0; j<(1<<i); j++){			//nodes of each level
			space = 2*(1<<(level-i));
//			if(j>0 && j%2==0){
//                space=space/2;
//			}
			while(space--){
				cout<<" ";
			}
			if(booli[(1<<i)+j-1]==0){
                cout<<" ";
			}
			else
			cout<<tree[(1<<i)+j-1];
			space = 2*(1<<(level-i))-1;
			while(space--){
				cout<<" ";
			}
		}
		for(lineGap=0; lineGap<(level-i); lineGap++){
			cout<<"\n";
		}
	}
	cout<<endl;
}

int main(){
    int heap[100]={10,5,3,2,4};
    bool booli[100]={false};

    size=5;
    for(int i=0;i<size;i++){
        booli[i]=true;
    }
    display(heap,booli);
    deletion(heap,booli,2);
    display(heap,booli);
}

