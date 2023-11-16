#include<iostream>
using namespace std;

int ratinmaze[4][4]={
   0,0,-1,0,
   -1,0,0,-1,
   0,0,-1,0,
   0,0,0,0,
};

int counts(int i,int j){
	if(j==4){
		j=0;
		++i;
	}
	if(i==4 && j==0){
		return ratinmaze[3][3];
	}
	else{
	        if(ratinmaze[i][j]==-1){
			}
			else{
			if(ratinmaze[i-1][j] > 0){
				ratinmaze[i][j]=ratinmaze[i][j]+ratinmaze[i-1][j];
			}
			if(ratinmaze[i][j-1] > 0){
				ratinmaze[i][j]=ratinmaze[i][j]+ratinmaze[i][j-1];
		    }
		    cout<<"ratinmaze "<<ratinmaze[i-1][j]<<" i "<<i-1<<" j "<<j<<endl;
	}
		    counts(i,j+1);
}
}


int temporary(int n){
for(int i=0;i<n;i++){
		if(ratinmaze[i][0]==0){
			ratinmaze[i][0]=1;
		}
		else
		break;
}
for(int i=0;i<n;i++){
	if(ratinmaze[0][i]==0){
		ratinmaze[0][i]=1;
	}
		else
		break;
	}
	cout<<"dd "<<ratinmaze[1][0]<<endl;
    counts(1,1);
}

int main(){
	cout<<temporary(4)<<endl;
}
