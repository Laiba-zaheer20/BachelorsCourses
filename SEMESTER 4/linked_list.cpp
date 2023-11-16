#include<iostream>
using namespace std;
struct node{
int data;
node* next;
};
node* head=NULL;
node* tail=NULL;
class made_node{
	public:
	void del(int p){
		node* curr=new node();
		curr=head;
		int k=1;
		while(1){
		if(k!=p-1){
		curr=curr->next;
		k++;
		}	
		else{
			curr->next=curr->next->next;
		break;
		}}
	}
	void insert(int k){
		node* first=new node();
	    first->data=k;
	    first->next=NULL;
		if(head==NULL){
			first->next=NULL;
			head=first;
			tail=first;
		
		}
		else{
			tail->next=first;
			tail=first;
		}	
	}
	void insert_middle(int a,int val){
		node* curr=new node();
		curr=head;
		node* first=new node();
		first->data=val;
	    first->next=NULL;
	    int k=1;
		while(1){
		if(k!=a-1){
		curr=curr->next;
		k++;
		}	
		else{
			first->next=curr->next->next;
		    curr->next=first;
		break;
		}}				
	}
	public:
	void show(){
		cout<<"hey"<<endl;
		node *temp=new node();
		temp=head;
		while(1){
	    if(temp->next==NULL){
		cout<<temp->data<<endl;
		break;}
		else{
		cout<<temp->data<<endl;
		temp=temp->next;
	}}
	}
};
int main(){
	made_node a3,a1,a2,a4,a5;
   a1.insert(1);	
   a2.insert(2);
   a3.insert(3);
   a4.insert(4);
   a5.show();
   cout<<"yayay";
   a5.insert_middle(2,8);
   a5.show();
   cout<<"\nlaiba"<<endl;
   a5.del(3);
   a5.show();
}
