// Given a binary tree, print out the tree in level order (ie, from left to right, level by level). Output a newline after the end of each level.

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int d, TreeNode* l, TreeNode* r): data(d), left(l), right(r) {} 
	TreeNode():data(0), left(nullptr), right(nullptr) {}
};


//print a tree in level order 

void levelOrderPrint(TreeNode* root)
{
	if(root==nullptr) return ; 
	queue<TreeNode* > curLevel, nextLevel; 
	curLevel.push(root);

	while(!curLevel.empty())
	{
		TreeNode* curNode = curLevel.front();
		curLevel.pop();
		if (curNode)
		{   
			cout<<curNode->data<<" ";
			nextLevel.push(curNode->left);
			nextLevel.push(curNode->right);
		}

		// if the current level reaches the end
		if (curLevel.empty()) 
		{   cout<<endl; 
			curLevel.swap(nextLevel); // clear the nextLevel queue and move currentlevel down by one 
		}
	}

}


//zigzag print: using 2 stacks and a toggle flag
void zigzagPrint(TreeNode* root)
{
    if(!root) return;
    stack<TreeNode* > curLevel, nextLevel; 
    bool inorder = true; 
    curLevel.push(root); 
    while(!curLevel.empty())
    {
    	  TreeNode* curNode = curLevel.top();
    	  curLevel.pop(); 
    	  if (curNode)
    	  {  cout<<curNode->data <<" "; 
    	  	 if (inorder)
    	  	 {  
    	  	 	nextLevel.push(curNode->left);
    	  	 	nextLevel.push(curNode->right);
    	  	 }
    	  	 else{
    	  	 	nextLevel.push(curNode->right);
    	  	 	nextLevel.push(curNode->left);
    	  	 }
    	  }

    	  if (curLevel.empty())
    	  {
    	  	cout<<endl;
    	  	inorder = !inorder ; 
    	  	swap(curLevel,nextLevel); 
    	  }
    	 

    }

}


int main()
{
	TreeNode n1(1,NULL,NULL);
	TreeNode n2(2,NULL,NULL);
	TreeNode n3(3,NULL,NULL);
	TreeNode n4(4,NULL,NULL);
	TreeNode n5(5,NULL,NULL);
	TreeNode n6(6,NULL,NULL);

	n1.left = &n2; 
	n1.right = &n3;
	n2.left = &n6;
	n3.left = &n4;
	n3.right = &n5;
	cout<<"level order print:\n"; 
	levelOrderPrint(&n1); 
	cout<<"zigzag print: \n";
	zigzagPrint(&n1);

	return 0;
}