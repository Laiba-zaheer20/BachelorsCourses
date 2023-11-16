#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int data;
	node* next;
};
class stack{
	private:
		node *head;	
	public:	
	stack(){
		head=NULL;
	}
	int push(int k){
		node *temp=new node();
		temp->data=k;
		temp->next=head;
		head=temp;
	}
		
    
	int pop(){
		if(head==NULL)
		return 0;
		else{
			head=head->next;
			return 1;
		}
	}
	
	int peep(){
		if(head ==NULL)
		return 0;
		else
		return head->data;
	}
	
    int operator==(stack s1){    	
		while(peep()){
    		int n=s1.peep();
    		int k=peep();
			if(n != k){
    			return false;
			}
		s1.pop();
		pop();
		}
		
		if(pop())
		return false;
		return true;
	} 
};

int main(){
int l=14;
stack s1;
s1.push(1);
s1.push(2);
s1.push(3);
s1.push(4);
s1.push(5);
stack s2;
s2.push(1);
s2.push(2);
s2.push(3);
s2.push(4);
s2.push(5);
if(s1==s2){
	cout<<"EQUAL"<<endl;
}
else{
	cout<<"NOT EQUAL"<<endl;
}
}
