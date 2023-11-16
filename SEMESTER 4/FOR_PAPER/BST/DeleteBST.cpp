#include<iostream>
using namespace std;


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

node* del(node *root,int input){
	if(root == NULL){
		return root;
	}
	if(input < root->data){
		root->left=del(root->left,input);
	}
	else{
	  if(input > root->data){
		root->right=del(root->right,input);
	  }
	  else{
	  	
	  	if(root->left != NULL && root->right != NULL){
	
	  		root->data=findmin(root->right)->data;
	  		root->right=del(root->right,root->data);
	
		  }
		  else{
		  	
		  	if(!root->left){
		  	  return root->right;	
			  }
			if(!root->right){
		  	  return root->left;
			  }
		  	node *prev=root;
	  		prev=NULL;
			return prev;
		}
	  }
	}
	}
	
int main(){
	
	node *root=NULL;
	root=insert(root,10);
	insert(root,8);
	insert(root,19);
	insert(root,5);
	insert(root,9);
	insert(root,17);
		
	
	
	del(root ,8);
	
	cout<<"\n ll "<<endl;
	inprint(root);
	
	
	del(root ,17);
	
	cout<<"\n ll "<<endl;
	inprint(root);
	
}
