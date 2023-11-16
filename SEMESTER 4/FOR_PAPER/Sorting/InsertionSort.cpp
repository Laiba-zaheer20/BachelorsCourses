#include<iostream>
using namespace std;

int insertionsort(int arr[] ,int n ){
	int i,key,j;
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
			
		}
		arr[j+1]=key;
	}
}


int findmin(int arr[],int a,int n){
  int min=a;
  for(int i=a;i<n;i++){
    if(arr[min]>arr[i]){
       	min=i;
       }   
   }
   return min;
}


int selectionsort(int arr[],int n){
	for(int i=0;i<=n-2;i++){
		int min=findmin(arr,i,n);
		int swap=arr[i];
		arr[i]=arr[min];
		arr[min]=swap;
	}
}

int bubblesort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(arr[j]<arr[j-1]){
				int swap=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=swap;
			}
		}
	}
}

int Modifiedbubblesort(int arr[],int n){
	bool check=true;
	for(int i=0;i<n-1 && check ;i++){
		for(int j=n-1,check=false;j>i;j--){
			if(arr[j]<arr[j-1]){
				int swap=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=swap;
			}
		}
	}
}

int combsort(){
	
}

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
		temp[count[arr[i]]]=arr[i];
	}

	for(int i=0;i<n;i++){
		cout<<temp[i]<<endl;
	}
	
}


int countsort_for_radixs(int arr[],int n,int e){
	int count[10];
	for(int i=0;i<10;i++){
    	count[i]=0;
	}
	for(int i=0;i<n;i++){
    	count[arr[i]/e % 10]=1;
	}
	
	for(int i=1;i<10;i++){
		count[i]+=count[i-1];
	}
	
	int temp[n];
	for(int i=n-1;i>=0;i--){
		count[arr[i]/e % 10]-=1;
		temp[count[arr[i]/e % 10]]=arr[i];
	}
	
	for(int i=0;i<n;i++){
		arr[i]=temp[i];
	}
}

int radixsort(int arr[],int n){
	int max=findmax(arr,n);
	for(int i=1;max/i > 0 ;i*=10){
		countsort_for_radixs(arr,n,i);
	}
}

//
//int dcountsort(int arr[],int n){
//	if(n<2){
//		return 1;
//	}
//	else{
//		int mid=n/2;
//		left[mid]={0};
//		right[n-mid]={0};
//		
//		for(int i=0;i<mid;i++)
//		left[i]=arr[i];
//		
//		for(int i=mid;i<n;i++)
//		left[i-mid]=arr[i];
//		
//		mergesort(left,mid);
//		mergesort(right,n-mid);
//		
//		merge(left,right,arr);
//	}
//}

int merge(int left[],int right[],int arr[],int a ,int b){
	int i=0,j=0,k=0;
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

int partition(int array[],int start,int end){
	
//FOR BEST APPROACH(keeping worst case scenario)
    
//	int arr[3];
//	arr[0]=array[start];
//    arr[1]=array[(start+end)/2];
//    arr[2]=array[end];
//    
//	int high=0;
//    int t;
//    for(int s=0;s<3;s++){
//    	if(arr[s]>high){
//    		high=array[s];
//    	    t=s;	
//		}
//	}
//	
//	if(t!=b){
//		int swap=array[t];
//		array[t]=array[end];
//		array[end]=swap;
//	}
//	
//    

    int pivot=array[end];
	int index=start;
	
	for(int i=start;i<end;i++){
		if(array[i] <= pivot){
			int swap=array[i];
			array[i]=array[index];
			array[index]=swap;
		    index++;
		}
	}
	
	int k=array[index];
	array[index]=array[end];
	array[end]=k;
	
	return index;
}

int quicksort(int arr[],int start,int end){

//Best and Average running time O(nlogn)
//
//Worst case running time O(n2)
//
//Quick and merge need to be used when we have large
//number of elements. We can say that for less than 30
//elements insertion sort shall be used rather.

	if(start<end){
		int index=partition(arr,start,end);
		quicksort(arr,start,index-1);
		quicksort(arr,index+1,end);
	}
}

int main(){
	int arr[]={3,1,2,6,7};
	//insertionSort
//	insertionsort(arr,5);
//	for(int i=0;i<5;i++){
//		cout<<arr[i]<<endl;
//	}
//	
	//selection Sort
//    
//    selectionsort(arr,5);
//	for(int i=0;i<5;i++){
//		cout<<arr[i]<<endl;
//	}

//    bubblesort(arr,5);
//	for(int i=0;i<5;i++){
//		cout<<arr[i]<<endl;
//	}
   
//   countsort(arr,5);

//  radixsort(arr,5);
//	for(int i=0;i<5;i++){
//		cout<<arr[i]<<endl;
//	}

//   mergesort(arr,5);
//	for(int i=0;i<5;i++){
//		cout<<arr[i]<<endl;
//	}

  quicksort(arr,0,4);
  for(int i=0;i<5;i++){
		cout<<arr[i]<<endl;
	}

}
