#include<iostream>
using namespace std;

int findmax(int arr[],int n){
  int max=0;
  for(int i=0;i<n;i++){
  	if(arr[max]<arr[i]){
  	    max=i;
	  }
  }
  	return arr[max];
}

int countsort(int arr[],int n){
	int k=findmax(arr,n);
    int count[k+1];
    for(int i=0;i<k+1;i++){
    	count[i]=0;
	}
	
	for(int i=0;i<n;i++){
    	count[arr[i]]+=1;
	}
	
	for(int i=1;i<k+1;i++){
		count[i]+=count[i-1];
	}
	
	int temp[n];
	for(int i=n-1;i>=0;i--){
		count[arr[i]]-=1;
		temp[count[arr[i]]]=i;
	}

	for(int i=0;i<n;i++){
		cout<<temp[i]<<endl;
	}
	
}

int main(){
int arr[]={13,29,91,34,56};	
countsort(arr,5);
}
