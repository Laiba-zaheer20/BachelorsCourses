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
	
	void display(){
		while(peep()){
			cout<<peep()<<endl;
		   pop();
		}
	}
	void factor(int m){
	while(m%2==0){
      push(2);
	  m=m/2;}
	for(int i=3;i<=sqrt(m);i=i+2){
      while(m%i== 0){
		push(i);
         m=m/i;
	}
    }
	if(m>2){
		push(m);
	}	
    }	
    
};

int main(){
int l=14;
stack s1;
s1.factor(l);
cout<<"The factors of "<<l<<" is "<<endl;
s1.display();
}
