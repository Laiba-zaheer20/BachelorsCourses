#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		node(int n){
			data=n;
			left=NULL;
			right=NULL;
		}
		node(){
			left=NULL;
			right=NULL;
		}
};

struct node1{
	node* data;
	node1* next;	
};


class queue{
	public:	
		node1 *front;
	    node1 *rear;
	queue(){
		front=NULL;
		rear=NULL;
	}
	int isempty(){
		return(!rear);
	}
	int enqueue(node** data){
		node1 *temp=new node1;
		temp->data=*data;
		temp->next=NULL;
		
		if(isempty()){
			front=temp;
			rear=temp;
		}
		
		else{
			rear->next=temp;
			rear=temp;
		}
		return 1;
	}
	
	node* dequeue(){
		if(isempty()){
			return 0;
		}
		else{
			node1 *temp=front;
			front=front->next;
			if(front==NULL){
				rear=NULL;
			}
			
		   return temp->data;
		}
	}	
};

int bfs(node **root){
  queue q1;
  node *temp=new node;
  temp=*root;
  q1.enqueue(&temp);
  
  while(!q1.isempty()){
  	temp=q1.dequeue();
  	cout<<temp->data<<" ";
	if(temp->left != NULL)
  	q1.enqueue(&(temp)->left);
  	if(temp->right != NULL)
	q1.enqueue(&(temp)->right);
  	
  }  	
}
int main(){
    node *root=NULL;

 root = new node(9); 
 root->left= new node(7); 
 root->right= new node(8); 
 root->left->right= new node(5); 
 root->left->left = new node(6); 
 root->left->right->left = new node(2);
 
 cout<<"(*printing is hardcode*)The tree is like this \n\t\t9\n\n\t7\t\t8\n\n     6\t    5\n\n\t  2\n\n"; 
 cout<<"The level order traversal is "<<endl<<endl;
 bfs(&root);
 
}
