#include<iostream>
using namespace std;

bool palindrome(string k,int n,int m,int t){
	if(n>(m/2)){
		return 1;
	}
	else{
		if(k[n]!=k[t]){
		cout<<"hey"<<endl;
		 return 0;
		  }
		else{
		  return palindrome(k,n+1,4,t-1);
	}
	}
}

int main(){

 string k="laial";
 int size_of_string=k.length();
 if(palindrome(k,0,size_of_string,size_of_string-1)){
 	cout<<"PALINDROME"<<endl;	
 }
 else{
 	cout<<"NOT A PALINDROME"<<endl;
 }
}
