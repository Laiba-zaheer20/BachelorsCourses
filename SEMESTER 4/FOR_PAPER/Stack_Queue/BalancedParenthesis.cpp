#include<iostream>
#define N 10
using namespace std;


class stack{
	int top;
	char array[N];
	
	public:
	stack(){
		top=-1;
	}
	
	int isempty(){
		return top==-1;
	}
	
	int isfull(){
		return top==N;
	}
	
	char peak(){
		if(isempty())
		return 0;
		else{
		return array[top]; 
	}
    }
	
	int push(char n){
		if(isfull())
		return 0;
		else{
			top++;
			array[top]=n;
			return 1;
		}
	}
	
	int pop(){
		if(isempty())
		return 0;
		else{
			top--;
			return 1;
		}
	}
	
	int check(char arr[]){
	 stack s1;
	 int i=0;
	 int k=1;
	 while(arr[i] != '\0'){
	 	
	 	if(arr[i] == '{' || arr[i] == '(' || arr[i] == '['){
	 				 s1.push(arr[i]);
		}
		if(arr[i] == '}'){
			if(s1.peak() != '{'){
			k=0;
			break;	
			}
			s1.pop();
		}
		
		if(arr[i] == ')'){
			if(s1.peak() != '('){
			k=0;
			break;	
			}
			s1.pop();
		}
		
		if(arr[i] == ']'){
			if(s1.peak() != '['){
			k=0;
			break;	
			}
			s1.pop();
		}
		i++;
	 }
	 
	 if(k==1){
	 cout<<"Balanced"<<endl;	
	 }
	 else{
	 	cout<<"Not Balanced"<<endl;
	 }
	 
	}
};
int main(){
	stack s2;
	char arr[]="{(1+2})";
	s2.check(arr);
}
