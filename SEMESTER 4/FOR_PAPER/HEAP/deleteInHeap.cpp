#include<iostream>
using namespace std;

int heapify(int arr[],int k,int n){
	
	int smallest=k;
	int left=(2*k)+1;
	int right=(2*k)+2;
	
	if( left<n && arr[left]<arr[k]){
		smallest=left;
	}
	if( right<n && arr[right]<arr[smallest]){
		smallest=right;
	}
	
	if(smallest != k){
		int swap=arr[k];
		arr[k]=arr[smallest];
		arr[smallest]=swap;
		
		heapify(arr,smallest,n);
	}
	
}

int del(int array[],int n){
	int swap=array[0];
	array[0]=array[n-1];
	array[n-1]=swap;
	
	heapify(array,0,n-1);
	
}
int main(){

int array[]={1,3,2,6,7};

for(int i=0;i<5;i++){
	cout<<array[i]<<endl;
}
	
}

