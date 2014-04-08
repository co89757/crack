/*C++11 implementation of a Binary Search Tree class(BST) and compositional class BSTNode
BST template class operations
basics (constructor/desctructor/assignment operators) 
Insert(key) create a node with a given key and insert it to the BST 
Search(key) return the pointer to the node holding given key or NULL 
Delete(Key)
Pred(key)
Max()
Min()

*/ 

#include <iostream> 
#include <cassert>
template<class T>
class BSTNode
{
private:
	T key_ ; 
	BSTNode<T>* parent_;
	BSTNode<T>* left_;
	BSTNode<T>* right_;
	
public:
	BSTNode(T key): key_(key),parent_(NULL),left_(NULL),right_(NULL) {} 
	~BSTNode() {} 
	T getKey(){return key_;} 
	BSTNode<T>* getParent() { return parent_;} 
	BSTNode<T>* getLeft() {return left_;} 
	BSTNode<T>* getRight(){return right_;} 
	void setLeft(BSTNode<T>* p) {left_ = p;}
	void setRight(BSTNode<T>* p) {right_ = p;} 
	void setParent(BSTNode<T>* p) {parent_ = p;}  

	void setKey(T key) {key_=key;} 

	/* data */
}; 


template<class T> 
class BST
{private:
	BSTNode<T>* root_; 
	void destroy(BSTNode<T>* root);
	BSTNode<T>* search(T key, BSTNode<T>* subroot);
	void insert(T key, BSTNode<T>* subroot); 
	void print(BSTNode<T>* root) ;
	BSTNode<T>* min(BSTNode<T>* subroot);
	BSTNode<T>* max(BSTNode<T>* subroot);
	void remove_easy(BSTNode<T>* p);
	// BSTNode<T>* pred(BSTNode<T>* subroot); 
public:
	BST(): root_(NULL) {} 
	BSTNode<T>* search(T key)  ; 
	void insert(T key);
	void  remove(T key); 
	BSTNode<T>* min()  ;
	BSTNode<T>* max()  ;
	BSTNode<T>* pred(T key)  ;
	void print(); //in-order traversal 
	void cleanup(); //destroy the whole tree 
	~BST();

	/* data */
};
// ----------------Private Methods ---------------------------------
template<class T> 
BSTNode<T>* BST<T>::search(T key, BSTNode<T>* subroot)
{
      if (subroot != NULL) 
      {
      	if (subroot->getKey()==key)
      	{
      		return subroot;
      	}

      	if (key <= subroot->getKey() )
      	
      		return search(key, subroot->getLeft()) ;
      	else{
      		return search(key, subroot->getRight()) ; 
      	}
      	
      }
      else
      	return NULL; 
}

template<class T> 
void BST<T>::insert(T key, BSTNode<T>* subroot)
{
	if (key <= subroot->getKey())
	{
		if(subroot->getLeft()) // non-null
			insert(key, subroot->getLeft()) ;
		else{  // subroot is NULL

			subroot->setLeft(new BSTNode<T>(key)) ; 
			subroot->getLeft()->setParent(subroot); //PENDING 

		}
	}

	else{
		if (key > subroot->getKey())
		{
			 if(subroot->getRight()) 
			 	insert(key, subroot->getRight()) ;
			 else
			 	subroot->setRight(new BSTNode<T>(key)) ; 
			 	subroot->getRight()->setParent(subroot);//PENDING 
		}





	}


}

template<class T> 
void BST<T>::destroy(BSTNode<T>* root)
{
	if (root)
	{
		destroy(root->getLeft()) ;
		destroy(root->getRight()) ;
		delete root ; 
	}
}


template<class T>
void BST<T>::print(BSTNode<T>* root)
{
	if (root)
	{
		print(root->getLeft());
		std::cout<<root->getKey()<<" "; 
		print(root->getRight());
	}
	

}

template<class T>
BSTNode<T>* BST<T>::max(BSTNode<T>* subroot)
{ 
	if(!subroot)
		return NULL ;
	if (subroot->getRight()) 
	{
		return max(subroot->getRight());
	}
	else
		return subroot; 
}


template<class T>
BSTNode<T>* BST<T>::min(BSTNode<T>* subroot)
{   
	if(subroot==NULL) return NULL ; 
	if (subroot->getLeft())
	{
		return min(subroot->getLeft());
	}
	else
		return subroot; 
}



template<class T>
void BST<T>::remove_easy(BSTNode<T>* p)
{
	assert(!(p->getLeft() && p->getRight())) ; // make sure it's easy case , 0-1 child 
	if (!p->getLeft() && !p->getRight())
	{
		 delete p ;
	}
	else if (p->getLeft() && !p->getRight())  // one left child 
	{

		BSTNode<T>* p_parent = p->getParent() ; 
		BSTNode<T>* p_left = p->getLeft();
		bool pisLeftChild = p_parent->getLeft() == p ; 
		p_left->setParent(p_parent);
		if(pisLeftChild) 
			p_parent->setLeft(p_left);
		else
			p_parent->setRight(p_left); 

		delete p ;
	}

	else if (!p->getLeft() && p->getRight())  // p has only one right child , symmetrical to left-case above
	{

		BSTNode<T>* p_parent = p->getParent() ; 
		BSTNode<T>* p_right = p->getRight(); 
		bool pisLeftChild = p_parent->getLeft() == p ; 
		p_right->setParent(p_parent);
		if(pisLeftChild) 
			p_parent->setLeft(p_right);
		else
			p_parent->setRight(p_right); 

		delete p ;



	}

	
}












//----- Public Methods --------------------//

template<class T> 
BSTNode<T>* BST<T>::search(T key)  
{

	return search(key, root_);
}

template<class T>
void BST<T>::insert(T key)
{
	if (root_ == NULL)
	{
		root_ = new BSTNode<T>(key) ; 
	}
	else{
		insert(key, root_);  
	}
}


template<class T> 
void BST<T>::print()
{
	print(root_) ; 
}


template<class T>
BST<T>::~BST()
{
	destroy(root_) ;
}

template<class T>
void BST<T>::cleanup()
{
	destroy(root_) ; 
}

template<class T>
BSTNode<T>* BST<T>::max()  
{
	return max(root_) ; 
}

template<class T>
BSTNode<T>* BST<T>::min()  
{
	return min(root_) ; 
}










template<class T> 
BSTNode<T>* BST<T>::pred(T key)  
{
	BSTNode<T>* p = search(key) ;
	if (p->getLeft()) // left subtree is non-null 
	{
		return min(p->getLeft()) ; 
	}

	else  // p has no left child , follow up the parent path
	{
		while(p->getParent()->getKey() > key) 
			p = p->getParent() ; 
		return p->getParent() ; 

	}
}

template<class T>
void BST<T>::remove(T key)
{

	BSTNode<T>* p = search(key) ; 
	//easy-case: p has 0-1 child 
	if (!(p->getRight() && p->getLeft()))
	{
		remove_easy(p); 
	}

	else{    // p has 2 kids. the most complex case. first swap p's predecessor and p , then delete 

		//find p's pred first 
		BSTNode<T>* predp = pred(key) ; 

		// swap predp and p 

		T temp; 
		temp  = p->getKey() ;
		p->setKey(predp->getKey()) ; 
		predp->setKey(temp) ; 

		// end of key-swap 
		// now delete predp  

		remove_easy(predp) ; 
	}

}