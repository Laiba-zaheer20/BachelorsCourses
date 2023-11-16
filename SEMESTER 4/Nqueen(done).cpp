#include<iostream>
using namespace std;

int board[4][4]={
0,0,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,0,
};
int rows_col(int row,int col){
	for(int i=0;i<4;i++){
		if(board[row][i]==1){
			return false;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int m=j-i;
			if(m==(row-col) | m==(col-row) ){
				if(board[i][j]==1){
				return false;
			}
			}
		}
	}
	return true;
}
//
//int check(){
//	int k=0;
//	for(int i=0;i<4;i++){
//		for(int j=0;j<4;j++){
//			if(board[i][j]==1){
//				k++;
//			}
//		}
//	}
//	if(k==4){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
bool nqueens(int col) 
{ 
    if (col >= 4) 
		return true; 
    
	for (int i = 0; i < 4; i++) { 
		
		if (rows_col(i, col)) { 
			board[i][col] = 1; 
            if (nqueens(col + 1)) 
				return true; 
            
			board[i][col] = 0; // BACKTRACK 
		} 
} 
return false; 
}

//
//int nqueen(int row,int col){
//	if(col==4){
//		col=0;
//		row++;
//    }
//	if(row==4){
//		return true;
//	}
//	if(check()){
//		return true;
//	}
//	else{
//	if(rows_col(row,col)){
//		board[row][col]=1;
//	}
//    nqueen(row,col+1);	
//	}
//	return false;
//}


int main(){
	nqueens(0);	
   for(int i=0;i<4;i++){
   for(int j=0;j<4;j++){
   		cout<<board[i][j]<<" ";
	   }
	   cout<<endl;
   }
}

