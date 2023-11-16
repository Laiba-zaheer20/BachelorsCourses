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

int max(node *root){
	if(root == NULL){
		return -1;
	}
	else{
	int left=max((root)->left);
	int right=max((root)->right);
	
	if(left<right)
	return right+1;
	else
	return left+1;
	}
}

int main(){
    node *root=NULL;

 root = new node(1); 
 root->left= new node(2); 
 root->right= new node(3); 
 root->left->left= new node(4); 
 root->left->right = new node(5); 
 root->left->right->left = new node(5); 

 cout<<"The height/levels of tree is "<<max(root)<<endl;

	
}
