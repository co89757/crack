#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


// iterative inorder traversal of BT 

void iterPreorderTrav(Node* root)
{	stack<Node* > s ; //stack of nodes to visit 
	Node* current = root ;
	if(!root) return ;
	s.push(current);
	while(!s.empty()){

		Node* top = s.top();
		cout<<top->data<<" ";
		s.pop();
		if(top->right) s.push(top->right);
		if(top->left) s.push(top->left);
	}




	
}


int main()
{
	Node root = {1, NULL, NULL} ;
	Node n2 = {2,NULL,NULL};
	Node n3 = {3, NULL,NULL} ;
	Node n4 = {4, NULL, NULL} ;
	Node n5 = {5, NULL,NULL} ;

	root.left = &n2 ; 
	root.right = &n3;
	n2.left = &n4;
	n2.right = &n5; 

	iterPreorderTrav(&root); 
	cout<<"\n" ; 
}
