#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

struct Node
{
	char cha; 
	bool is_end;
	std::vector<Node* > children; 
	int prefix_count;
	Node(char key, bool end=false): children(26, nullptr), cha(key), is_end(end), prefix_count(0) {  }
};

class Trie
{
private:
	Node* root ; 
public:
	Trie();
	~Trie();
	void insert(std::string word);
	bool search(std::string word);
	int wordsWithPrefix(string word);
	
};

Trie::Trie()
{
	root = new Node('\0'); 

}

Trie::~Trie()
{
	delete root ; 
}

void Trie::insert(std::string word)
{
	Node* current = root ; 
	if(word.empty()) {
		root->is_end = true ; 
		return ; 
	}

	for (auto i = word.begin(); i != word.end(); ++i)
	{
		int int_value = *i - 'a';
		assert(int_value >= 0 && int_value < 26);
		if (current->children[int_value])
		{
			current = current->children[int_value];
			++ current->prefix_count; 
			
		}
		else{
			Node* temp = new Node(*i); 
			current->children[int_value] = temp ; 
			current = temp; 
			++ current->prefix_count;
		}

		

	}

	current->is_end = true;
}


bool Trie::search(std::string word) 
{
	Node* current= root ;

	for (auto i = word.begin(); i != word.end(); ++i)
	{    
		int int_value = *i - 'a';
		assert(int_value >= 0 && int_value < 26);

		if (current->children[int_value])
		{
			current = current->children[int_value] ; 
		}
		else{
			return false; 
		}


	}

	return current->is_end ; 

}

int Trie::wordsWithPrefix(string word)
{
	Node* current = root;
	for (auto c: word)
	{
		int int_value = c - 'a'; 
		assert(int_value >= 0 && int_value < 26);
		if (!current->children[int_value]) // is NULL 
		{
			 return -1; 
		}

		else{
			current = current->children[int_value];
		}
	}

	return current->prefix_count;
}

int main(int argc, char const *argv[])
{
	Trie atrie ; 
	atrie.insert("python");
	atrie.insert("pythonardd");
	atrie.insert("pythonarddrdd");
	atrie.insert("colin");
	atrie.insert("john");
	atrie.insert("johndeer");
	atrie.insert("johndeerad");
	atrie.insert("johndeeradead");
	std::cout<<"search for colin \n";
	if(atrie.search("colin"))
		std::cout<<"found !\n";

	std::cout<<"wordsWithPrefix python \n";
	int a = atrie.wordsWithPrefix("python") ;
	cout<<"words of prefix python = "<<a<<endl;
		 
	 
	// delete atrie;
	// return 0;



}

