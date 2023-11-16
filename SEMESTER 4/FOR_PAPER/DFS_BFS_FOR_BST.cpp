#include<iostream>
using namespace std;
#define SIZE 6
#define N 6

struct node{
	int data;
	node* left;
	node* right;
};



class queue{
	private:
		node* array[SIZE];
		int front;
		int rear;
		
	public:
	 queue(){
	 	front=-1;
	 	rear=-1;
	 }
	 
	 int isempty(){
	 	return ((front == -1)&& (rear == -1));
	 }
	 
	 int isfull(){
	 	return ((rear+1)%N) == front;
	 }
	 
	 int enqueue(node* n){
	 	if(isempty()){
	 		front++;
	 		rear++;
	 		array[rear]=n;
		}
		else{
		 	if(isfull()){
		 		return 0;
			 }
			 else{
			 	rear=(rear+1)%N;
				 array[rear]=n;
			 }
		 }
	 }
	 
	 node* dequeue(){
	 	if(isempty()){
	 		return 0;
		 }
		else{
		 if(front==rear){
		 	node* m=array[front];
			front=-1;
		 	rear=-1;
		 	return m;
		}
		else{
		node* k =array[front];
		front++;	
		return k;
		}
		}
	}
};

class stack{
    private:
    node* arr[SIZE];
    int top;

    public:
   stack(){
   	top=-1;
   }
   
    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    int push(node* value){
        if(top==SIZE-1){
        	return 0;
        }
        else{
            top++;
            arr[top]=value;
            return 1;
        }
    }

    int  pop(){
        if(empty()){
           return 0;
        }
        else{
            top--;
            return 1;
        }
    }
    
    node* topelem(){
        if(empty())
        return 0;
        else{
            return arr[top];
            }
    }
   
	void display(){
    	if(empty()){
    		cout<<"Stack is empty."<<endl;
		}
		else{
			for(int i=top;i>=0;i--){
				cout<<arr[i];
			}
            cout<<endl;
		}
	}
}; 

class bst{
	node* root;
	stack s1;
	public:
		bst(){
			root=NULL;
			int a;
			while(1){
			cout<<"Enter elements of binary search tree(press -1 to stop)"<<endl;
			cin>>a;
			if(a == -1){
				break;
			}
			node* temp=new node;
			temp->data=a;
			temp->left=NULL;
			temp->right=NULL;
			if(root == NULL){
				root=temp;
				continue;
			}
			insert1(temp,&root);	
			}
			
		}
		
		int insert1(node *temp,node **r){
			if(*r == NULL){
				*r=temp;
				return 1;
			}
			else{
				if((*r)->data>= temp->data){
					insert1(temp,&(*r)->left);
				}
				else{
					insert1(temp,&(*r)->right);
				}
				return 0;
			}
		}
		
       void print(){
       	  node *j=root;
		   inprint(j);
	   }	
	   
		void inprint(node *j){
		    
			 if (j != NULL) 
		    { 
		        inprint(j->left);
				cout<<j->data<<" ";
				inprint(j->right);	 
		    } 
		}
		
		void dfs(int a){
			node* j=root;
			cout<<"\nThe stack that will formed when we search an element in bst till the element is found will be (PREORDER TRAVERSAL using stack)"<<endl;
			//dfs_full(j);
		    bfs(j);
		}
		
		node* dfs_full(node *j){
			s1.push(j);
			while(!s1.empty()){
			node* temp=s1.topelem();
			cout<<temp->data<<" ";
			    s1.pop();
				if(temp->right!=NULL){
					s1.push(temp->right);
				}
				if(temp->left!=NULL){
					s1.push(temp->left);
				}
			}
		}
		
		void bfs(node* j){
			queue q1;
			q1.enqueue(j);
			while(!q1.isempty()){
			node* temp=q1.dequeue();
			cout<<temp->data<<" ";
			if(temp->right!=NULL){
				q1.enqueue(temp->right);
			}
			if(temp->left!=NULL){
				q1.enqueue(temp->left);
			}
			}
			
			}
			
		};
		
int main(){
	bst b1;
	cout<<"The inorder traversal(DFS) of bst "<<endl;
	b1.print();
	int a;
	cout<<"\nEnter Element to search in bst using DFS"<<endl;
    cin>>a;
	b1.dfs(a);
}
