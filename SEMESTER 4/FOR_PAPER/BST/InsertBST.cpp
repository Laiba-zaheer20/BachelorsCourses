#include<iostream>
#define N 5
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

	
node* insert(node *root,int input){
	
	if(root == NULL) 
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

int main(){
 	
	int array[]={3,1,5,9,7};
	node *root=NULL;

	for(int i=0;i<5;i++){
	if(i==0)
	root=insert(root,array[i]);
	else
	insert(root,array[i]);
    }
    
	inprint(root);


}
