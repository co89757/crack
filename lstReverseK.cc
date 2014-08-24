#include <iostream>

using namespace std;
// given a linked list a1--a2--a3.... reverse part of the list starting from p+1 to q-1, k nodes 

struct node
{
	int val;
	node* next;
	node(int x): val(x), next(NULL) {} 
};

// reverse k elements starting from p->next 
void reverseK(node* p, int K)
{
	//find the node next to the end of the to-be-reversed element
	int c = 0; // counter 
	node* q = p->next;

	// find the one-past-end elem q 
	while(c++ != K)
	{
		q = q->next; 
	}

	 
	node* cursor = p->next;
	node* prev = q;
	
	//reverse only k-1 times 
	c=1;
	while(c++<=K)
	{
		node* next = cursor->next; 
		cursor->next = prev ;
		prev = cursor; 
		cursor = next; 


	}

	p->next = prev;

}


int main()
{
	node n1(1);
	node n2(2);
	node n3(3);
	node n4(4);
	node n5(5);
	node n6(6);
	n1.next = &n2 ;
	n2.next = &n3 ;
	n3.next = &n4 ;
	n4.next = &n5 ;
	n5.next = &n6 ;

	reverseK(&n1, 3); 
	node* head = &n1 ;

	cout<<"after partial reversion \n";
	while(head)
	{
		cout<<head->val<<"->"; 
		head=head->next;
	}

	cout<<endl;

}
