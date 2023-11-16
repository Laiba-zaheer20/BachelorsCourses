#include<iostream>
using namespace std;

int merge(int left[],int right[],int arr[],int a ,int b){
	int m=1,i=0,j=0,k=0;
	while(i<a && j<b){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			k++;
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
			k++;
		}
	}
	
	while(i<a){
		arr[k]=left[i];
		k++;
		i++;
	}
	while(j<b){
		arr[k]=right[j];
		k++;
		j++;
	}
}


int mergesort(int arr[],int n){
	if(n<2){
		return 0; 
	}
	else{
		
		int mid=n/2;
		int left[mid]={0};
		int right[n-mid]={0};
		

		for(int i=0;i<mid;i++){
			left[i]=arr[i];
		}
		for(int i=mid;i<n;i++){
			right[i-mid]=arr[i];
		}
		
	    mergesort(left,mid);
		mergesort(right,n-mid);
		merge(left,right,arr,mid,n-mid);
        
}
}


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
	 if(i != n-1){
	 if(arr[i] == arr[i+1]){
	   cout<<"NOT UNIQUE"<<endl;
	 }
	 }
	heapify(arr,0,i);
	}
}


int main(){
int arr[]={8,200,200,9,1};
//mergesort(arr,5);
//        int k=1;
//        for(int i=1;i<5;i++){
//	      if(arr[i]==arr[i-1]){
//		   cout<<"NOT UNIQUE "<<endl;
//		   k=2;
//		   break;
//	    }
//        }
//if(k==1){
//	cout<<"UNIIQUE"<<endl;
//}


heapsort(arr,5);

	
for(int i=4;i>=0;i--){
	cout<<arr[i]<<endl;
}

}
