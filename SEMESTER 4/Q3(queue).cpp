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
		return(!rear);
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
	
	int dequeue(){
		if(isempty()){
			return 0;
		}
		else{
			node *temp=front;
			front=front->next;
			if(front==NULL){
				rear=NULL;
			}
			delete(temp);
			return 1;
		}
		
	}
	
	int factor(int a){
		while(a%2==0){
		enqueue(2);
		a=a/2;	
		}
		
		for(int i=3;i<sqrt(a);i+=2){
			if(a%i==0){
				enqueue(i);
				a=a/i;
			}
		}
		if(a>2){
			enqueue(a);
		}
	}
	
int display( node *front1){
	if(front1 == NULL){
		return 1;
	}
	else{
		display(front1->next);
	    cout<<front1->data<<endl;
	
	}	

}

int peep(){
	if(front == NULL){
		return 0;
	}
	else{
		return front->data;
	}
}

int moved(queue q2){
stack k1;
	while(dequeue());
	while(q2.peep()){
		k1.push(q2.peep());
		//enqueue(q2.peep());
		q2.dequeue();
	}
	while(k1.peep()){
		enqueue(k1.peep());
		k1.pop();
	}
}
};

int main(){
   
	queue q1;
	
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(9);
	
	queue q2;
	q2.enqueue(7);
	q2.enqueue(8);

	q2.moved(q1);
	cout<<"After deleting all element of linked list 2 and copying elements of linked list1 into linked list 2"<<endl;
	
	while(q2.front != NULL){
		cout<<q2.front->data<<endl;
		q2.front=q2.front->next;
	}
}
