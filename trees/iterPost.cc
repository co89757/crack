//Given a binary tree, print the elements in post-order iteratively without using recursion. 
// // //////  using 2 stacks
// Push the root node to the first stack.
// Pop a node from the first stack, and push it to the second stack.
// Then push its left child followed by its right child to the first stack.
// Repeat step 2) and 3) until the first stack is empty.
// Once done, the second stack would have all the nodes ready to be traversed in post-order. 
// Pop off the nodes from the second stack one by one and you’re done.

#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iterator>
#include <stack>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

void iterPostorder(Node* root)
{
	if(!root) return ;
	stack<Node*> s;
	stack<Node*> out; 
	s.push(root);
	while(!s.empty()){
		Node* cur = s.top();
		out.push(cur);
		s.pop();
		if(cur->left)
			s.push(cur->left);
		if(cur->right)
			s.push(cur->right);
	}

	 while(!out.empty()){
	 	cout<<out.top()->data <<" ";
	 	out.pop();
	 }

	 cout<<"\n";
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

	iterPostorder(&root);
}