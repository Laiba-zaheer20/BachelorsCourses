#include<iostream>
using namespace std;

//rat in maze

int track[4][4]={
  1,1,1,1,
  1,0,0,1,
  0,1,0,1,
  0,0,0,1,
};

int path[4][4]={
   0,0,0,0,
   0,0,0,0,
   0,0,0,0,
   0,0,0,0,
};

int backtrack(int n,int m,int k){
	if(n==k-1 && m==k-1){
		path[n][m] = 1 ;
		return 1;
	}
	
	if(track[n][m]==1){
		path[n][m]=1;
		if(backtrack(n,m+1,k))
		return 1;
		if(backtrack(n+1,m,k))
		return 1;
		
		path[n][m]=0;
	}
	return 0;
}

int main(){
	cout<<"Rat In Maze Problem"<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<track[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	backtrack(0,0,4);
	cout<<"The way to out is "<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(path[i][j]==1)
			cout<<"( "<<i<<" "<<j<<" )"<<endl;
		}
	}
}



