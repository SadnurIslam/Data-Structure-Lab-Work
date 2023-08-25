#include<bits/stdc++.h>
using namespace std;

int size;

void heapify(int tree[],int current){
    int par = (current-1)/2;
    if(tree[par]<tree[current]){
        swap(tree[par],tree[current]);
        heapify(tree,par);
    }
}

void insert(int tree[],int item){
    tree[size]=item;
    size++;
    heapify(tree,size-1);
}

void display(int tree[]){		
	int i, j, space, lineGap, level = log2(size+1);
	for(i=0; i<=level; i++){					
		for(j=0; j<(1<<i); j++){			
			space = 2*(1<<(level-i));
			while(space--){
				cout<<" ";
			}
			if(tree[(1<<i)+j-1]==0){
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
    size=5;
    display(heap);
    insert(heap,15);
    display(heap);
}
