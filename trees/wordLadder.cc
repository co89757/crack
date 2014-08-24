// Word Ladder
// Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;

// determine if another string is a valid next string (differ by only one char)
bool isValid(string current, string next)
{
	if (current == next || current.size() != next.size())
	 
		return false;  

 	bool diffToggle = false ; 

 	for (int i = 0; i < current.size(); ++i)
 	{
 		if (current[i] != next[i])		
 		{
 			 if(diffToggle==true)
 			 	return false ;  // found at least 2 different char 
 			 else
 			 	diffToggle = true ; 
 		}


 	}

	 return true; 



}

///// use Double BFS , traverse from both ends 
int ladderLength(string start, string end, const unordered_set<string> & dict)
{
	// extreame cases check 
	if(isValid(start,end)) return 2; 

	// initialize 
	struct node
	{
		string str; 
		int lev; 
		node(string s, int lv):str(s),lev(lv) {} 
	};
	queue<node> Q; 
	queue<node> rQ; // reversed direction traversal 
	map<string ,bool> visited;
	map<string, bool> rvisited; 
	for(auto it=dict.cbegin(); it != dict.cend(); ++it)
		{visited[*it] = false;
		rvisited[*it] = false; }

	int curLevel = 1;
	int rcurLevel = 1; 

	Q.push(node(start,1));
	rQ.push(node(end,1)); 

	// end of init 

	//D-BFS start

	while(!Q.empty() && !rQ.empty()){

		if(Q.size() < rQ.size()){
			// Keep traversing Q 
			while(!Q.empty() && Q.front().lev == curLevel)
				{
					  for(auto it = dict.begin(); it != dict.end(); ++it) // cannot use < dict.end()!!! 
					  	{
					  		if(isValid(Q.front().str, *it) && !visited[*it])
					  		{
					  			visited[*it] = true; 
					  			if(rvisited[*it]) return (Q.front().lev + rQ.back().lev);
					  			Q.push(node(*it, curLevel + 1));
					  		}	
					  	}

					   Q.pop();
				}

				++curLevel ;


		}

		else{

			while(!rQ.empty() && rQ.front().lev == rcurLevel)
			{
				 for(auto it = dict.begin(); it != dict.end(); ++it)
				 	{
				 		if(isValid(rQ.front().str, *it) && !rvisited[*it])
				 		{
				 			rvisited[*it] = true; 
				 			if(visited[*it]) return (rQ.front().lev + Q.back().lev);
				 			rQ.push(node(*it, rcurLevel + 1)) ;
				 		}	
				 	}

				 	rQ.pop();
			}

			++rcurLevel ; 
		}




	}

return 0; 

}

/// Using BFS 

int ladderLength2(string start, string end, const unordered_set<string> & dict)
{
	// extreame cases check 
	if(isValid(start,end)) return 2; 

	// initialize 
	struct node
	{
		string str; 
		int lev; 
		node(string s, int lv):str(s),lev(lv) {} 
	};
	queue<node> Q; 
	map<string ,bool> visited;
	for(auto it=dict.cbegin(); it != dict.cend(); ++it)
		{visited[*it] = false;
		 }

	int curLevel = 1;
	Q.push(node(start,1));


	// end of init 

	//BFS start

	while(!Q.empty())
	{

		while(Q.front().lev == curLevel) { 

			cout<<"we are at level "<<curLevel <<"\n" ; //DEBUG 
		// visited[Q.front().str] = true; 
		for(auto it = dict.begin(); it != dict.end(); ++it)
			{
				if(isValid(Q.front().str, *it) && !visited[*it] )
				{   cout<<"visited word: "<<*it<<"\n" ; 
					visited[*it] = true;
					if(visited[end] ) return (curLevel+1);
					if(isValid(*it, end)) return (curLevel + 2); // start and end word don't need to be in dictionary !! 
					Q.push(node(*it, curLevel+1));
				}	
			}

			Q.pop();  
		}


		++curLevel;
			  
	}

	return 0; 

}

 






int main()
{
	string start("hit");
	string end("cog");
	unordered_set<string> dict = {"hot","dot","dog","lot","log"} ; 
	// int ladderlen = ladderLength(start, end, dict) ; 
	int ladderlen = ladderLength2(start, end, dict) ; 
	cout<<ladderlen<<endl; 
}