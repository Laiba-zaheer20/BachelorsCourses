#include<iostream>
using namespace std;

struct node{
	int data;
	int m;
	node* left;
	node* right;
};


node* insert(node *root,int input,int l){
	
	if (root == NULL) 
{
	node *k=new node;
	k->data=input;
	k->m=l;
	k->left=NULL;
	k->right=NULL;

	return k;
} 
  
    if (input < root->data) 
        root->left= insert(root->left, input,l); 
    else if (input > root->data) 
        root->right = insert(root->right, input,l);    
  
    return root; 

}
//
//void inprint(node* root){
//	if(root== NULL){
//		return ;
//	}
//	else{
//		inprint(root->left);
//		cout<<root->data<<" ";
//		inprint(root->right);
//	}
//}

node* search(node* root,int data=-1,int add=-1){
	if(root==NULL)
		return NULL;
	else if(data < root->data)
		return search(root->left,data);
	else if(data > root->data)
		return search(root->right,data);
	else return root;	
}
//
//node* predessor(node* root){
//	if(root->left!=NULL){
//		return max(root->left);
//	}
//}
//
//node* sucessor(node* root){
//	if(root->right!=NULL){
//		return min(root->right);
//	}
//}
//
//node* findmin(node *root){
//	if(root == NULL){
//		return NULL;
//	}
//	else{
//		if(root->left == NULL)
//		return root;
//		else
//		return findmin(root->left);
//	}
//}


int main(){

	node *root=NULL;
	root=insert(root,10,9);
    insert(root,1,3);
    insert(root,6,5);
    insert(root,3,8);

   cout<<search(root,6)->data<<" ";
}
