#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
class circular{
	private:
		node *head;
		node *tail;
	public:
	circular(){
		head=NULL;
		tail=NULL;
	}
	void insert(int element){
		node *temp=new node;
		temp->data=element;
     	temp->next=NULL;
		if(head==NULL){
     		head=temp;
     		tail=temp;
     		tail->next=head;}
     	else{
     		tail->next=temp;
     		tail=temp;
     		tail->next=head;
		}
	}
	void maximum(){
		node *temp=head;
	  
	   do{
	   	node *cur=temp->next;
	   	while(cur != head){
	   	if(temp->data < cur->data){
	   		int k=temp->data;
	   		temp->data=cur->data;
	   		cur->data=k;
		   }
		   cur=cur->next;	
		}
		temp=temp->next;
	   }while(temp!=head);
	   
	   temp=head;
	   int i=1;
	   int product=1;
	   
	   do{
	   	product*=temp->data;
	   	temp=temp->next;
	   cout<<product<<"kk"<<endl;
	   i++;
	   }while(temp != NULL && i<3);
	   cout<<product<<endl;
	}
	void display(){
		node *temp=head;
		do{
			cout<<temp->data<<endl;
			temp=temp->next;
		}while(temp != head);
	}	
};
int main(){
	circular c1;
	c1.insert(7);
	c1.insert(-11);
	c1.insert(3);
	c1.insert(4);
	c1.insert(0);
	c1.maximum();
	c1.display();
	
}
