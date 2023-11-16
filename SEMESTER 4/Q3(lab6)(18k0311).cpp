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
		if(head == NULL)
		return 0;
		else
		return head->data;
	}
	
	void display(){
		node *k=head;
		while(peep()){
			cout<<peep()<<endl;
		   pop();
		}
		head=k;
	}
	
    int reversestack(stack s1){
    	while(peep()){
			pop();
    	}
    	node *k=s1.head;
		while(s1.peep()){
    		push(s1.peep());
    		cout<<peep()<<endl;
			s1.pop();
		}
		s1.head=k;
	}
};

int main(){
int l=14;
stack s1;
s1.push(10);
s1.push(9);
s1.push(8);
s1.push(7);
s1.push(6);
stack s2;
s2.push(1);
s2.push(2);
s2.push(3);
s2.push(4);
s2.push(5);
cout<<"THE STACK ONE ELEMENTS"<<endl;
s1.display();
cout<<"THE STACK TWO ELEMENTS"<<endl;
s2.display();
cout<<"AFTER REVERSING ELEMENT OF STACK 1 AND PLACING IT IN STACK 2"<<endl;
s2.reversestack(s1);
cout<<"THE STACK ONE ELEMENTS"<<endl;
s1.display();
cout<<"THE STACK TWO ELEMENTS"<<endl;
s2.display();
}
