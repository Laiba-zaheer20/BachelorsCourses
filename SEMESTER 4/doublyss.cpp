#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node* prev;
};
class doubly{
	private:
	node *head;
	node *tail;
	public:
	doubly(){
		head=NULL;
		tail=NULL;
	}
	void insert(int elem){
		node* temp=new node;
		temp->data=elem;
		temp->next=NULL;
		temp->prev=NULL;
		
		if(head==NULL){
			head=temp;
			tail=temp;
			tail->next=head;
			head->prev=NULL;
		}
		else{
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
			tail->next=NULL;
		}
	}
	
	void delete_any(int k){
		node *temp=head;
		node *prev=head;
		
		int i=1;
		if(i==k){
			head=head->next;
			head->prev=NULL;
		}
		else{
		while(temp != NULL && i<k){
			i++;
			prev=temp;
			temp=temp->next;
			temp->prev=prev;
		}
			prev->next=temp->next;
			temp=temp->next;
			temp->prev=prev;
	}}
	
	void swap(){
     	node *temp=head;
		int k=2;int i=1;
		while(temp != NULL && i<k){
			i++;
			temp=temp->next;
		}
		
		node *temp1=head;
		k=4;
		i=1;
	    while(temp1 != NULL && i<k){
			i++;
			temp1=temp1->next;
		}
		
		node *prev1=temp->prev;
		node *prev2=temp1->prev;
		prev1->next=temp1;
		temp1->prev=prev1;
		
		prev2->next=temp;
		temp->prev=prev2;
		
		node *next1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		
		temp1->next=next1;
		next1->prev=temp1;
		
	}
	
	void display(){
		node *temp=head;
		while(temp != NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
};

int main(){
	doubly d1;
	d1.insert(1);
	d1.insert(2);
	d1.insert(3);
	d1.insert(4);
	d1.insert(5);
	d1.swap();
	d1.display();
}
