#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int data;
	node *next;
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
};
class queue{
	public:
		node *front;
	    node *rear;
	queue(){
		front=NULL;
		rear=NULL;
	}
	int isempty(){
		return(!front);
	}
	int enqueue(int data){
		node *temp=new node;
		temp->data=data;
		temp->next=NULL;
		
		if(isempty()){
			front=temp;
			rear=temp;
		}
		
		else{
			rear->next=temp;
			rear=temp;
		}
		return 1;
	}
	int peep(){
		if(front == NULL)
		return 0;
		else
		return front->data;
	}
	int dequeue(){
		if(isempty()){
			return -1;
		}
		else{
			node *temp=front;
			front=front->next;
			delete(temp);
		}
	}
	
	int factor(int a){
		stack s1;
		while(a%2==0){
		s1.push(2);
		//enqueue(2);
		a=a/2;	
		}
		for(int i=3;i<sqrt(a);i+=2){
			if(a%i==0){
				s1.push(i);
				a=a/i;
			}
		}
		if(a>2){
			s1.push(a);
		}
		
		while(s1.peep()){
			enqueue(s1.peep());
			s1.pop();
		}
	}
    int display(){
    	while(peep()){
    		cout<<peep()<<endl;
    		dequeue();
		}
	}	
};

 
int main(){

	queue q1;
	q1.factor(14);
	q1.display();
}
