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

void iterInorderTravBT(Node* root)
{	stack<Node* > s ; //stack of nodes to visit 
	Node* current = root ;
	if(!root) return ;
	bool done = false;

	//use a stack and a cursor 
	while(!done){

		if(current){
			s.push(current); 
			current = current->left; 
		}
		else{  // non-NULL 

			if (s.empty())
			{
				done = true ; 		
			}


			else{

				current = s.top();
				s.pop();
				cout<<current->data<<" ";
				current = current->right; 


			}


		}




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

	iterInorderTravBT(&root); 
	cout<<"\n" ; 
}