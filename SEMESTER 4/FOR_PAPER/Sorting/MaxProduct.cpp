#include<iostream>
using namespace std;

int merge(int left[],int right[],int arr[],int a ,int b){
	int i=0,j=0,k=0;
	while(i<a && j<b){
		if(left[i]>=right[j]){
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

int main(){
	
	int arr[]={1,4,6,-6,-10};
	mergesort(arr,5);
    int n=5;
	int max2;
	if(arr[n-1]<0 && arr[n-2]<0){
    	max2=arr[n-1]*arr[n-2]*arr[0];
	}
	
    int max1=arr[1]*arr[2]*arr[0];
    if(max1>max2)
    cout<<" Max "<<max1<<endl;
	else
    cout<<" Max "<<max2<<endl;
    
    for(int i=0;i<5;i++){
    	cout<<arr[i]<<" ";
	}
	
	int arr1[]={1,2,3,4,5};
	int arr2[]={6,7,8,9,10};
	
	
//	Algorithm MedianOfTheTwoArraysOfSameLength
//Input: Array A [] and Array B [] of length n
//Output: median
//1. Calculate median m1 for array A
//2. Calculate median m2 for array B
//3. If m1 == m2 return m1;
//4. If m1 > m2 then median will be from A[n/2….n] and B[1…n/2]
//5. If m2 > m1 then median will be from B[n/2….n] and A[1…n/2]
//6. Goto step 1 if A and B both contains more than 2 elements.
//7. Else return m = (max(A[i], B[i]) + min(A[i+1], B[i+1]))/2; 

//Algorithm MedianOfTheTwoArraysOfSameLength
//Input: Array A [] and Array B [] of length n
//Output: median
//Merge the two sorted Arrays A and B, you will get a third Array C of length 2n.
///* => 2n will be an even number by definition of even number. Hence the median will be the
//average of the two middle elements. */
//The median will be m= {C[n] + C[n+1]} / 2; 


}
