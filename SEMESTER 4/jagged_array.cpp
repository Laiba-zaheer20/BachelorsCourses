#include<iostream>
using namespace std;

int main(){
	int **jagged_array=new int *[3];
	for(int i=0;i<3;i++){
		int *k=new int [4];
		for(int j=0;j<4;j++){
			k[j]=1;
		}
		jagged_array[i]=k;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
		cout<<jagged_array[i][j]<<endl;	
		}
	}
	
}
