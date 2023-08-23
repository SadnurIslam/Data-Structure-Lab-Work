
#include<iostream>
#include<math.h>
using namespace std;

int binTree[100] = {0};
bool isOccupied[100] = {false};
int insert(int data){
	int pos = 0;
	while(1){
		if(!isOccupied[pos]){
			binTree[pos] = data;
			isOccupied[pos] = true;
			return pos+1;
		}
		if(data == binTree[pos]){
			cout<<"The number "<<data<<" already exists in the binary tree at position "<<pos+1<<"\n";
			return pos+1;
		}
		else if(data < binTree[pos]){
			pos = 2*pos + 1;
		}
		else{
			pos = 2*pos + 2;
		}
	}
}
void displayTree(int tree[], int size){		//works better with single-digit nodes.
	int i, j, space, lineGap, level = log2(size)+1;
	for(i=0; i<level; i++){					//levels
		for(j=0; j<(1<<i); j++){			//nodes of each level
			space = (1<<(level-i))-1;
			if(j == 0){
				space /= 2;
			}
			while(space--){
				cout<<" ";
			}
			cout<<tree[(1<<i)-1+j];
		}
		for(lineGap=0; lineGap<(level-i-1); lineGap++){
			cout<<"\n";
		}
	}
}
int main(){
	int data[] = {8,3,10,1,6,-1,14,-1,-1,7};
	int pos, mxSize = 0;
	for(int i=0; i<10; i++){
		pos = insert(data[i]);
		mxSize = max(mxSize,pos);
	}
	displayTree(binTree, mxSize);
	return 0;
}
