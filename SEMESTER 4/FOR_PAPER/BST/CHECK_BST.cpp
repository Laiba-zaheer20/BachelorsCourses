#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};


node* insert(node *root,int input){
	
	if (root == NULL) 
{
	node *k=new node;
	k->data=input;
	k->left=NULL;
	k->right=NULL;

	return k;
} 
  
    if (input < root->data) 
        root->left= insert(root->left, input); 
    else if (input > root->data) 
        root->right = insert(root->right, input);    
  
    return root; 

}

void inprint(node* root){
	if(root== NULL){
		return ;
	}
	else{
		inprint(root->left);
		cout<<root->data<<" ";
		inprint(root->right);
	}
}

int check_bst(node *root){
 if(root !=NULL){
 	    if(root->left !=NULL && root->data > root->left->data)
 		check_bst(root->left);
 		else
 		return false;
 		
		if(root->right !=NULL && root->data < root->right->data)
 		check_bst(root->right);
     	
}
}

bool isBST(node* root, node* l, node* r) 
{ 
    if (root == NULL) 
        return true; 
  
    if (l != NULL && root->data <= l->data) 
        return false; 
  
    if (r != NULL && root->data >= r->data) 
        return false; 
  
    return isBST(root->left, l, root) && isBST(root->right, root, r); 
} 

int main(){

	node *root=NULL;
	root=insert(root,10);
    insert(root,1);
    insert(root,6);
    insert(root,3);
   
   if(isBST(root,NULL,NULL))
      cout<<"yay"<<endl;
   else
   	  cout<<"no"<<endl;
   
}
