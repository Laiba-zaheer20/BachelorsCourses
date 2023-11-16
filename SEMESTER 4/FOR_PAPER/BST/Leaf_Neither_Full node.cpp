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

};
//
//void insert(node** root,node* k){
//			if(*root == NULL){
//				*root=k;
//				return ;
//			}
//				if((*root)->data > k->data){
//					insert(&(*root)->right,k);
//				}
//				else
//			    	insert(&(*root)->left,k);
//			return;
//		}	

int leafnode(node *j){
		if(j == NULL) 
        return 0;
		else{
		if(j->left==NULL && j->right==NULL){
		  return 1;
		}else
		  return leafnode(j->left)+leafnode(j->right);	
		}
}

int neithernode(node *j){
	   if (j == NULL) 
       return 0; 
       
	   int count = 0;
		if(j->left==NULL && j->right!=NULL )
		  count++;
		if(j->left!=NULL && j->right==NULL )
		  count++;
        count += neithernode(j->left)+neithernode(j->right); 
        return count; 
}



int fullnode(node *j){
	   if (j == NULL) 
       return 0; 
       int count = 0; 
       if(j->left && j->right)  
       count++; 
   
    count += fullnode(j->left)+fullnode(j->right); 
    return count; 
}


int main(){
node *root=NULL;

 root = new node(1); 
 root->left= new node(2); 
 root->right= new node(3); 
 root->left->left= new node(4); 
 root->right->right = new node(5); 

cout<<"Number of Full Nodes Are"<<endl;
cout<<fullnode(root)<<endl;

cout<<"\nNumber of LeafNodes Are"<<endl;
cout<<leafnode(root)<<endl;

cout<<"\nNumber of NeitherNodes Are"<<endl;
cout<<neithernode(root)<<endl;

}
