#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;
// realize a design of LRU cache using double-linked list 
//Design and implement a data structure for Least Recently Used (LRU) cache. 
// It should support the following operations: get and set.
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
// it should invalidate the least recently used item before inserting a new item.

// Consider the basic operations we need:
// (1) Insert a new <key, value> pair to the end of the list.
// (2) delete a <key, value> pair (if the cache is full).
// (3) move a <key, value> pair to the end. (when it is used)
// (3) change the value in a <key, value> pair and move it to the end.

struct Node
{
	int key;
	int value;
	Node* next;
	Node* prev;
	Node(int k, int v): key(k),value(v), next(NULL), prev(NULL) {}
	Node(int k, int v, Node* p, Node* n): key(v), value(v), next(n),prev(p) {}
};

class LRUcache
{
private:
	map<int, Node* > keymap; 
	Node* head;
	Node* tail; 
	int cap; //capacity
	void pushNode(Node* node);
	void pophead();
	void move2tail(Node* node);
public:
	LRUcache(int capacity);	
	void set(int k, int v);
	int get(int k);
	~LRUcache(){} ;
	
};

LRUcache::LRUcache(int capacity): cap(capacity), head(NULL), tail(NULL), keymap()
{

}
// push a new node to the tail 
void LRUcache::pushNode(Node* node) 
{ 
	if (!head)
	{
		head = node ; 
		tail = node;	
	}

	else{

		tail->next = node ; 
		node->prev = tail ; 
		tail = node ;
	}
}

void LRUcache::pophead()
{

	head = head->next ; 
	if(head) head->prev = NULL ; 
}

void LRUcache::move2tail(Node* node)
{
	if(node == tail) return ; 
	else{

		if (node == head)
		{
			 node->next->prev = NULL ;
			 head = node->next;

			 node->prev = tail;
			 tail->next = node;
			 tail = tail->next; 
			 

		}

		else{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			tail->next = node ;
			node->prev = tail ; 
			tail = tail->next; 
		}



	}
}

void LRUcache::set(int k, int v)	
{
   if (keymap.find(k) != keymap.end()) 
   	// key is found		
   {
   	  move2tail(keymap[k]);
   	  keymap[k]->value = v ;

   }

   else{
   	// not found. need a new node

   	if (keymap.size()==cap)
   		{
   		
   		keymap.erase(head->key); // remove head entry 
   		pophead();

   		}
   		Node* temp = new Node(k,v);
   		pushNode(temp); 
   		keymap[k] = temp; 
   	}

   
}


int LRUcache::get(int k)	
{
	if(keymap.find(k) == keymap.end())
		return -1 ;
	else{
		// key found; get value and move2tail
		Node* nd = keymap[k]; 
		move2tail(nd);
		return nd->value;
	}
}




int main()
{
	LRUcache cache(5);
	cache.set(1,1);
	cache.set(2,2);
	cache.set(3,3);
	cache.set(4,4);
	cache.set(5,5);

	cout<<"look up entry 5: \n"<<cache.get(5)<<endl;
	cache.set(6,6);
	cout<<"look up entry 1 : \n"<<cache.get(1)<<endl;
}