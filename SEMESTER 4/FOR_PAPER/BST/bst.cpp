#include<iostream>
#define N 5
using namespace std;

class bst{
	int array[N];
	int top;
	
	public:
	bst(){
		for(int i=0;i<N;i++){
			array[i]=0;
		}
	}
	
int insert(int k,int n){
	if(k < N){
		
	if(array[k]==0){
		cout<<n<<"f"<<endl;
		array[k]=n;
	}
	else{
	if (n <= array[k]) 
        insert((2*k)+1,n); 
    else if (n > array[k]) 
        insert((2*k)+2, n);    
	}
}

}

int print(int k){
	if(k < N){
		print((2*k)+1);
		cout<<array[k]<<endl;
		print((2*k)+2);
	   }
}

};
int main(){
 	
	int array[]={3,1,5,9,7};
	bst h1;
	for(int i=0;i<5;i++){
		h1.insert(0,array[i]);	
	}
    h1.print(0);
}
