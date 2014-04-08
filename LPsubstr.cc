// Given a string S, find the longest palindromic substring in S.
// using DP O(N^2) 
// a sub string P[i,j] <- true iff S_i->j  is a palindromic 
//P[i,j] <- (P[i+1,j-1] and Si=Sj)
//Base Cases:
// P[i,i] <- true ;  P[i,i+1] <- (Si=Si+1) 

#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iterator>
#include <string>
using namespace std;

string longestPLsubstr(string s)
{
	size_t N = s.size() ; 
	int lpsBegin = 0;
	int maxLen = 1;
	bool isP[1000][1000] = {false} ;

	// initialize isP table with base cases 

	for (int i = 0; i < N; ++i)
	{
		isP[i][i] = true ;
	}

	// base case 2: P[i,i+1]
	for (int i = 0; i < N-1; ++i)
	{
		if(s[i]==s[i+1]){
			isP[i][i+1] = true ;
			maxLen = 2;
			lpsBegin = i ; 
		}
	}

	// deductive 
	for (int len = 0; len < N+1; ++len)
	{
		for (int i = 0; i < N-len + 1; ++i)
		{
			int j = i + len -1; //end index of substring 
			if (s[i]==s[j] && isP[i+1][j-1] )
			{
				isP[i][j] = true ;
				lpsBegin = i ;
				maxLen = len ; 
			}
		}
	}



return s.substr(lpsBegin, maxLen) ;


}







int main()
{
	string s ; 
	cout<<"input a string to find out the maxLen palindromic substr:\n" ; 
	cin>>s ; 

	string lps = longestPLsubstr(s) ; 

	cout<<"maxlen palindromic substr is \n "<<lps << endl ; 
}