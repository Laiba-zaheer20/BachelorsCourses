#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class singlylinklist{
 node* head;
 node* tail;
 public:
 	singlylinklist(){
 		head=NULL;
 		tail=NULL;
	}
	
	void insert(int data){
		node* temp =new node;
		temp->data=data;
		temp->next=NULL;
		
		if(head==NULL){
		    head=temp;
		    tail=temp;
		}
		else{
		   tail->next=temp;
		   tail=tail->next;
		}
	}
	
	
	//DISPLAY DDLIST
    void display(){
		node *temp=head;
		while(temp != NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	} 


int search(int y){
		node *temp=head;
		node* prev=head;
		while(temp->next != NULL){
		prev=temp;
		temp=temp->next;
		if(temp->data+prev->data == y){
		return 1; 
        break;
	    }
	
		}
		return 0;
}

};
int main(){
	
	singlylinklist s1;
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	s1.display();
	if(s1.search(9)){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
}
