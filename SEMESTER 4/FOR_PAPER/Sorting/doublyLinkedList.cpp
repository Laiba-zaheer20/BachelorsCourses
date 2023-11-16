#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

class linkedlist{
	
	Node* head;
	Node* tail;
	public:
		linkedlist(){
			head=NULL;
			tail=NULL;
		}
	//INSERT IN DDLIST	
	void insert(int elem){
		Node* temp=new Node;
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
	//DISPLAY DDLIST
    void display(){
		Node *temp=head;
		while(temp != NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	
	
	//DELETE ANY NODE
	void delete_any(int k){
		Node *temp=head;
		Node *prev=head;
		
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
	
	//swap elements
	void swap(){
     	Node *temp=head;
		int k=2;int i=1;
		while(temp != NULL && i<k){
			i++;
			temp=temp->next;
		}
		
		Node *temp1=head;
		k=3;
		i=1;
	    while(temp1 != NULL && i<k){
			i++;
			temp1=temp1->next;
		}
		
		
		Node *prev1=temp->prev;
		Node *prev2=temp1->prev;
		prev1->next=temp1;
		temp1->prev=prev1;
		
		prev2->next=temp;
		temp->prev=prev2;
		
		Node *next1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		
		temp1->next=next1;
		next1->prev=temp1;
		
	}
	
	void display_circular(){
		Node *temp=head;
		do{
			cout<<temp->data<<endl;
			temp=temp->next;
		}while(temp != head);
	}
	
	void sorting(){
		Node *temp=head;
		Node *cur=new Node;
		while(temp != NULL){
			cur=temp->next;
			while(cur != NULL){
				if(temp->data>cur->data){
				int k=temp->data;
				temp->data=cur->data;
				cur->data=k;
			}
			cur=cur->next;
			}
			temp=temp->next;
		}
	}
	
	void circular(linkedlist l1){
	 Node *temp=tail;
	 Node *n_temp=l1.head;
	 while(n_temp != NULL){
          temp->next=n_temp;
          n_temp->prev=temp;
          temp=n_temp;
          n_temp=n_temp->next;
	 }
	 l1.tail->next=head;
	 head->prev=l1.tail;
     tail=l1.tail;
	}
	
};

int main(){
  linkedlist l1;
  l1.insert(6); 
  l1.insert(11); 
  l1.insert(1);
  l1.insert(5);
  //l1.delete_any(1);
  
  l1.swap();
  l1.sorting(); 
//  l1.display();
 
  
  linkedlist l2;
  l2.insert(18); 
  l2.insert(119);
  l2.insert(12);
  l2.insert(51);
  
  l1.circular(l2);
  l1.display_circular(); 
}
