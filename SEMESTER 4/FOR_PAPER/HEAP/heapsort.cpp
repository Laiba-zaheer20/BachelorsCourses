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

int heapsort(int arr[],int n){
	for(int i=(n/2)-1;i>=0;i--){
		heapify(arr,i,n);
	}
	
	for(int i=n-1;i>=0;i--){
	 	int swap=arr[0];
		arr[0]=arr[i];
		arr[i]=swap;

	heapify(arr,0,i);
	}
}
int main(){
	int arr[7]={9,5,7,2,1,3,0};
	heapsort(arr,7);
	
	
	for(int i=6;i>=0;i--){
		cout<<arr[i]<<endl;
	}
}
