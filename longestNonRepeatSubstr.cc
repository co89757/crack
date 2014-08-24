/*Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for “abcabcbb” is “abc”, which the length is 3. 
For “bbbbb” the longest substring is “b”, with the length of 1. */ 

// linear scan , keep track of head and tail (2 ends ) of the candidate substring 

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int lengthLongestSubstr(string s)
{   
	int n = s.length() ; 
	if(s.empty()) return 0;
	int i=0 ; int j=0; // 2 cursors keeping track of two ends of the substring 
	int maxLen = 0; // maxLen : max so far , update if necessary 
	bool exist[256] = {false} ; // hash to check duplicate 

	while(j<n)
	{
		if (exist[s[j]]==false) // no exist so far 
		{   
			maxLen = max(maxLen, j-i+1);
			exist[s[j]] = true ; 
			++j ; //move on 
		}
		else{
			//meet an existing char, update maxlen 
			// maxLen = max(maxLen, j-i); // why at this point? 
			
			//update i cursor 
			while(s[i]!=s[j]){
				// now all chars before next start of substring should clear their entry in the table. things start anew
				exist[s[i]] = false; 
				++i ; 
						}
			maxLen= max(maxLen,j-i);

			++i; //move beyond the found duplicate 
			++j; // move on 	

		}
	}

	// maxLen = max(maxLen, n-i);

	return maxLen; 

}



int main()
{
	string s; 
	cout<<"type a string consisting of lower case letters\n";
	cin>>s;
	int maxlen  = lengthLongestSubstr(s);
	cout<<"The length of longest duplicate-free substring is "<<maxlen<<"\n"; 
}