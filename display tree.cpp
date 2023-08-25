#include<iostream>
#include<math.h>
using namespace std;

int tree[100],size;

void displayTree(){		
	int i, j, space, lineGap, level = log2(size+1);
	for(i=0; i<=level; i++){					
		for(j=0; j<(1<<i); j++){			
			space = 2*(1<<(level-i));
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
	tree[] ={3,5,1,2,7,9,4);
	size = 7;
	displayTree();

return 0;
}
