#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};
node *head=NULL;
node *tail=NULL;


class element{
	public:
      void insert(int data){
      	node *temp=new node;
      	temp->data=data;
      	temp->next=NULL;
      	if(head==NULL){
      		head=temp;
      		tail=temp;
		  }
      	else{
      		tail->next=temp;
      		tail=temp;
		  }
	  }		
	  void show(){
	  	node *temp=new node;
	  	temp=head;
	  	
	    while(temp!=NULL){
	    cout<<temp->data<<endl;
			temp=temp->next;
		}
	  }
	  
	  void reverse(){
	  	
	  	node *net=new node;
	  	node *prev=new node;
	  	prev=NULL;
	  	node *cur=new node;
	  	cur=head;
	  	while(cur!=NULL){
	    net=cur->next;
	    cur->next=prev;
	    prev=cur;
		cur=net;
		}
		head=prev;
	  }	
		
};
int main(){
	element e1;
	e1.insert(1);
	e1.insert(2);
	e1.insert(3);
	e1.insert(44);
	
	e1.show();
    e1.reverse();
    e1.show();
}
