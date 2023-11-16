#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

class doubly_linked_list{
	private:
		node *head;
		node *tail;
	public:
	doubly_linked_list(){
		head=NULL;
		tail=NULL;
	}
	
	void insert(int elem){
	    
			node* temp=new node;
			temp->data=elem;
			temp->prev=NULL;
			temp->next=NULL;
		
			if(head==NULL){
				head=temp;
				tail=temp;
		}
			
			else{
			
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
				tail->next=NULL;		}			
	}
	void display(){
		node *temp=head;
		while(temp != NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	
	void display_circular(){
		node *temp=head;
		do{
			cout<<temp->data<<endl;
			temp=temp->next;
		}while(temp != head);
	}
	
	
	void sorting(){
		node *temp=head;
		node *cur=new node;
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
	
	 
    void circular(doubly_linked_list l1){
	 node *temp=tail;
	 node *n_temp=l1.head;
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
    
	doubly_linked_list d1;
    d1.insert(1);
    d1.insert(12);
	d1.insert(13);
	
	doubly_linked_list d2;
    d2.insert(22);
    d2.insert(23);
	d2.insert(24);
	
	d1.circular(d2);
	d1.display_circular();
}
