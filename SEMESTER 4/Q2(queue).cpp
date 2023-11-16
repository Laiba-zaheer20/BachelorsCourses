#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int data;
	node *next;
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

int peep(){
	if(front == NULL){
		return 0;
	}
	else{
		return front->data;
	}
}

int operator==(queue q2){

	while(peep()){
	
		if(peep()!=q2.peep()){
			return 0;
		}
		else{
			dequeue();
			q2.dequeue();
       }
   }
	if(q2.peep()){
		return 0;
	}
	return 1;
}
};

int main(){

	queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	queue q2;
	q2.enqueue(1);
	q2.enqueue(2);
	q2.enqueue(3);
	q2.enqueue(4);
		
	if(q1==q2)
		cout<<"Equal!"<<endl;
	else
	cout<<"Not Equal!"<<endl;

}
