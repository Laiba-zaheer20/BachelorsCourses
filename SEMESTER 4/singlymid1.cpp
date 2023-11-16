#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class singly_linked_list{
	private:
		node *head;
		node *tail;
		node *head1;
		node *tail1;
		node *head2;
		node *tail2;

	public:
	singly_linked_list(){
		head=NULL;
		tail=NULL;
		head1=NULL;
		tail1=NULL;
		head2=NULL;
		tail2=NULL;
	}
	
	void insert(int elem){
	    
			node* temp=new node;
			temp->data=elem;
			temp->next=NULL;
		
			if(head==NULL){
				head=temp;
				tail=temp;
		}
			
			else{
			
				tail->next=temp;
				tail=temp;
				tail->next=NULL;}			
	}
//	void half(){
//		node *temp=head;
//	
//		int k=0;
//		while(temp != NULL){
//			k++;
//			temp=temp->next;
//		}
//		
//		k=k/2;
//		cout<<"k is "<<k<<endl;
//		
//		temp=head;
//		while(temp != NULL){
//			if(k!=0){
//				k--;
//			if(head1==NULL){
//				head1=temp;
//				tail1=temp;}
//			else{
//				tail1->next=temp;
//				tail1=temp;
//				tail1->next=NULL;
//				}	
//				temp=temp->next;
//		}
//		else{
//			
//			if(head2==NULL){
//				head2=temp;
//				tail2=temp;}
//			else{
//				tail2->next=temp;
//				tail2=temp;
//				tail2->next=NULL;}	
//			temp=temp->next;
//		}
//		}
//	}
	void display(){
		node *temp=head;
		while(temp != NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	void deletes(singly_linked_list s1){
		node *temp=s1.head;
		while(temp != NULL){
		delete_array(temp->data);
		temp=temp->next;
		}
	}
	void delete_array(int n){
		node *temp=head;
		node *temp1=head;
		node *prev=head;
		int i=0,k=0;
		while(temp1 !=NULL){
			k++;
			temp1=temp1->next;
		}
		if(n==k){
         while(temp->next!=NULL && i!=n){
			i++;
			prev=temp;
			temp=temp->next;
			}
			prev->next=NULL;
		}
		else{
			if(i==0){
				head=head->next;
			}
			else{
		while(temp!=NULL && i!=n){
			i++;
			prev=temp;
			temp=temp->next;
			}
		prev->next=temp->next;}
	}
	}
	
//	void display1(){
//		node *temp=head1;
//		cout<<" a "<<head1->data<<endl;
//		while(temp != NULL){
//			cout<<temp->data<<endl;
//			temp=temp->next;
//		}
//	}
//	void display2(){
//		node *temp=head2;
//		cout<<" b "<<head2->data<<endl;
//		while(temp != NULL){
//			cout<<temp->data<<endl;
//			temp=temp->next;
//		}
//	}
	
	};
int main(){
	singly_linked_list s1;
	s1.insert(1);
	s1.insert(2);
	singly_linked_list s2;
	s2.insert(11);
	s2.insert(22);
	s2.insert(33);
	s2.insert(34);
	s2.insert(35);
	s2.deletes(s1);
	s2.display();
	//s1.half();
	//s1.display1();
	//s1.display2();
}
