#include<iostream>
#define N 150
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
	
	int prec(char c){
		if(c=='^')
		return 3;
		if(c=='*' | c=='/' | c=='%')
		return 2;
		if(c=='+' | c=='-')
		return 1;
		
	}
	
	int to_postfixs(char k[]){
	   char postfixs[N];
	   top=-1;
	   int i=0;
	   //APPLYING BRACKETS ON WHOLE EQUATION 
	   while(k[i++] != '\0' );
	   k[i+1]='\0';
	   k[i--]=')';
	   while(i>0){
	   	 k[i]=k[i-1];
	   	 i--;
	   }
	   k[i]='(';
//	    cout<<"The Infixs is "<<endl;
//		cout<<k<<endl<<endl;
	 i=0;
	 int m=0;
	 //CONVERTING IT INTO POSTFIX EQUATION 
	 while(k[i] != '\0'){
	        if(k[i] == '('){
	        	push(k[i]);
			}
			else if((k[i] >= 'a' && k[i]<='z' ) | (k[i] >= 'A' && k[i]<='Z') | (k[i] >= '1' && k[i]<= '9')){
		        		postfixs[m]=k[i];
		        		m++;
			}
			else if(k[i]=='+' |k[i]=='-' |k[i]=='*' |k[i]=='/'|k[i]=='^' ){
			while(k[i]=='+' |k[i]=='-' |k[i]=='*' |k[i]=='/' |k[i]=='^'){
					
				if(prec(peak()) > prec(k[i])){
					postfixs[m]=peak();
					m++;
					pop();
				}
				else{
					break;
				}
				}
				push(k[i]);	
			} 
			
			else if(k[i] == ')'){
				while(peak() != '('){
					postfixs[m]=peak();
					m++;
					pop();
				}
				pop();
			}
			i++;	
	}
	postfixs[i]='\0';
	 cout<<"\nThe Postfix Notation  is "<<endl;
	 for(i=0;postfixs[i] != '\0';i++){
	 	cout<<postfixs[i];
	 }
	 cout<<endl;
     
	 //REVERSING POSTFIX EQUATION TO MAKE IT PREFIX
        i=0;
		while(postfixs[i]!='\0'){
			push(postfixs[i]);
			i++;
		}
		i=0;
		while(peak()){
			postfixs[i]=peak();
			pop();
			i++;}
	 //PRINTING PREFIX NOTATION
	 cout<<"\nTHE PREFIX EQUATION IS  "<<endl;
	 for(i=0;postfixs[i] != '\0';i++){
	 	cout<<postfixs[i];
	 }
	 
	 			
}
	
	int infixs( char infix[]){
	  int i=0;
		//printing infix notation
	 cout<<"The INFIX Notation  is "<<endl;
	 for(i=0;infix[i] != '\0';i++){
	 	cout<<infix[i];
      }
	 cout<<endl;
	 i=0;

		//FIRST REVERSING THE ELEMENTS OF INFIX
		while(infix[i]!='\0'){
			push(infix[i]);
			i++;
		}
		i=0;
		
		while(peak()){
			if(peak() == '(')
				infix[i]=')';
			else{
				if(peak() == ')')
				infix[i]='(';
			    else{
			       infix[i]=peak();
				}
			}
			pop();
			i++;
		}
		
		cout<<"\nAFTER REVERSING INFIX EQUATION"<<endl;
		for(i=0;infix[i] != '\0';i++){
	 	cout<<infix[i];
	 }
		//PASSING REVERESED CHARACTER ARRAY 
   	    to_postfixs(infix);
	}
};

int main(){
	stack s1;
	char d[]="(A+B^C)*D+E^U";
	s1.infixs(d);
}
