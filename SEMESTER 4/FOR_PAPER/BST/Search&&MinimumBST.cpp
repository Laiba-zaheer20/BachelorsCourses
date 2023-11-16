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

node* search(node* root,int data){
	if(root==NULL)
		return NULL;
	else if(data < root->data)
		return search(root->left,data);
	else if(data > root->data)
		return search(root->right,data);
	else return root;	
}


node* findmax(node *root){
	if(root == NULL){
		return NULL;
	}
	else{
		if(root->right == NULL)
		return root;
		else
		return findmax(root->right);
	}
}


node* findmin(node *root){
	if(root == NULL){
		return NULL;
	}
	else{
		if(root->left == NULL)
		return root;
		else
		return findmin(root->left);
	}
}


node* predessor(node* root){
	if(root->left!=NULL){
		return findmax(root->left);
	}
}

node* sucessor(node* root){
	if(root->right!=NULL){
		return findmin(root->right);
	}
}


int main(){

	node *root=NULL;
	root=insert(root,10);
    insert(root,1);
    insert(root,6);
    insert(root,3);

   cout<<search(root,6)->data<<" ";-}
