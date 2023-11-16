#include<iostream>
#define N 5
using namespace std;

class heap{
	int array[N];
	int top;
	public:
	
	heap(){
		top=-1;
	}
	
	int insert(int a){
		top++;
		if(N == top-1){
			cout<<"Full"<<endl;
		}
		else{
			if(top==0){
				array[top]=a;
			}
			else{
				array[top]=a;
				int i=top;
				
				while(i>=0 && array[(i-1)/2]>array[i]){
					int swap=array[(i-1)/2];
					array[(i-1)/2]=array[i];
					array[i]=swap;
					
				    i=(i-1)/2; 	
				}
			}
		}
	}
	
	int print(){
		for(int i=0;i<5;i++){
			cout<<array[i]<<endl;
		}
	}

//	int print(int k){
//		if(k < N){
//		cout<<array[k]<<endl;
//		print((2*k)+1);
//		print((2*k)+2);
//	   }
//	}

};

int main(){
	int array[]={3,1,5,9,7};
	heap h1;
	for(int i=0;i<5;i++){
		h1.insert(array[i]);	
	}
    h1.printss();
}
