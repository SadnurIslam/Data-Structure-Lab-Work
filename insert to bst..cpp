#include<iostream>
#include<math.h>
using namespace std;

int tree[100],size;
void insert(int key){
	int pos = 0;
	while(tree[pos]!=-1){
        if(key>tree[pos]){
            pos = pos*2+2;
        }
        else if(key<tree[pos]){
            pos = pos*2+1;
        }
        else{
            cout<<"Found at "<<pos <<endl;
            return;
        }
	}
	tree[pos]=key;
	size=pos;
}
void displayTree(){		//works better with single-digit nodes.
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
			if(tree[(1<<i)+j-1]==-1){
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
    for(int i=0;i<100;i++){
        tree[i]=-1;
    }
    int n;
    cin>>n;
    int pos, mxSize = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(x);
        displayTree();
    }

	return 0;
}

