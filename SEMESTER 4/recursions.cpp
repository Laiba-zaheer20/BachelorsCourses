#include<iostream>
using namespace std; 

struct node{
	int data;
	node* next;
};

class singly_linked_list{
	public:
		node *head;
		node *tail;
	public:
	singly_linked_list(){
		head=NULL;
		tail=NULL;
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
	
	void display(){
		node *temp=head;
		while(temp != NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	void singly_reverse(){
//	
//	node *temp=head;
//	node *cur=head;
//	node *next1=head->next;
//	
//	temp->next=NULL;
//	while(next1 != NULL){
//		cur=next1;
//		next1=cur->next;
//		cur->next=temp;
//		temp=cur;
//	}

//	head=cur;
//	node *prev=new node;
//	node *cur=head;
//	node *temp=new node;
//	
//	prev=NULL;
//	temp=NULL;
//	while(cur !=NULL){
//       
//       temp=cur->next;
//		cur->next=prev;
//		prev=cur;
//		cur=temp;
//	}
//	head=prev;
//	
//
//	node *prev=NULL;
//	node *cur=NULL;
//	node *temp=head;
//    
//    while(temp !=NULL){
//    	cur=temp->next;
//    	temp->next=prev;
//    	prev=temp;
//    	temp=cur;
//	}
//	head=prev;
	}
	void reverse(node *cur,node *prev,node *next1){
		if(cur == NULL ){
			head=prev;
			return ;
		}
		else{
			next1=cur->next;
			cur->next=prev;
			reverse(next1,cur,next1);
		}
	}
	int facts(int n){
		if(n<10){
			return n;
		}
		else{
			facts(fact(n));
		}
	}
	int fact(int k){
		if(k==0){
			return 0;
		}
		else{
			return (k%10)+fact(k/10);
		}
	}
	
	void reverse(){
		node *temp=head;
		node *temp1=head;
		
		int i=0;
		
		while(temp != NULL){
			i++;
			temp=temp->next;
		}
		int l=i/2;
		temp=head;
		int k=0;
		int p=i;
		int t=0;
		cout<<"l "<<l<<endl;
		while(temp !=NULL && k<l ){
		  while(temp1!= NULL && t<p-k){
		  	temp1=temp1->next;
		    t++;
		     cout<<"t "<<t<<endl;
		  }
		  cout<<"l "<<l<<endl;
		  cout<<temp->data<<"  "<<temp1->data<<" ggg "<<endl;	
		temp=temp->next;
		k++;
		
		}
		
	}
};
int main(){
	
	singly_linked_list s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.reverse();
    //s1.singly_reverse();
	//s1.reverse(s1.head,NULL,s1.head);
   // cout<<s1.facts(1234)<<endl;

}
