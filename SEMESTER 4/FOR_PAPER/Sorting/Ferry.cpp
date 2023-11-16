#include<iostream>
using namespace std; 

struct node{
	int x;
	int y;
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
	
	void insert(int x,int y){
		node* temp =new node;
		temp->x=x;
		temp->y=y;
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
	
	void display(){
		node *temp=head;
		while(temp != NULL){
			cout<<temp->x<<" / "<<temp->y<<endl;
			temp=temp->next;
		}
	} 

	bool cmp(node* a, node* b) 
	{ 
		return a->x * b->y < b->x * a->y; 
	} 

	int gcd(int a, int b) 
	{ 
		if (b == 0) 
			return a; 
		return gcd(b, a % b); 
	} 



	void farey(int n) 
	{ 
		for (int i = 1; i <= n; ++i) { 
			for (int j = i + 1; j <= n; ++j) 
	
				if (gcd(i, j) == 1) 
				  insert(i,j);
		} 
		
		cout << "0/1 "; 
	    
		node* temp=head;
		while(temp != NULL){
			cout << temp->x << "/" << temp->y << " "; 
            temp=temp->next;
        }
		cout << "1/1"; 
		
	} 
	};

//class Term { 
//public: 
//	int x, y; 
//
//	Term(int x, int y) 
//		: x(x), y(y) 
//	{ 
//	} 
//
//}; 

int main() 
{ 
    singlylinklist l1;
	int n = 3; 
	cout << "Farey Sequence of order " << n << " is\n"; 
	l1.farey(n); 
	return 0; 
} 

