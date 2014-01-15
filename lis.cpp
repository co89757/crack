#include <iostream>
#include <iterator>
// #include <cstdio>
// #include <string>
// #include <cmath>
#include <vector>
// #include <cstdlib>
#include <algorithm> 
using namespace std; 

/* Longest Increasing Subsequence (strictly increasing)
given an array/vector A , e.g. A=[3 2 4 6]
find the LIS of A, LIS=[2 4 6]. 
a typical problem of Dynamical Problem 

L[i] -- LIS up to A[i] that ends with A[i] 

L[i] = Max(L[j] s.t. j<i && A[j]<A[i]) + A[i] 

and find the max(L[i])

*/

inline void printVec(const vector<int> & v)
{
	for(auto i: v)
		cout<<i<<" ";
	cout<<endl; 
}






void findLIS(const vector<int> & A)
{
	vector<vector<int> > LIS(A.size()) ; // create a LIS list of list of size n 
	LIS[0].push_back(A[0]) ; // initialize L[0] 

	for (int i = 1; i < A.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if((A[j]<A[i]) && (LIS[i].size() <= LIS[j].size() ) ) 
				LIS[i] = LIS[j] ; //relaxation 
		}

		LIS[i].push_back(A[i]) ; 
	}



for(auto sub: LIS)
	printVec(sub); 



}







int main(int argc, char **argv){


	vector<int> A = {4,2,3,7,1,10};
	cout<<"original vector is :\n";
	printVec(A); 
	cout<<endl; 
	cout<<"LIS from 0 to (N-1) are : \n"; 
	findLIS(A); 

	
}