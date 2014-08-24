#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

// given an array, shuffle it so that a0<=a1>=a2<=a3.... 

inline void swap(int & a, int& b)
{
	a ^= b;
	b ^= a; 
	a ^= b ; 
}

void shuffle(vector<int> & A)
{
	size_t N = A.size();
	if(N==1) return ;
	for (int i = 1; i < N; i += 2)
	{
		if (i==N-1)
		{
			if (A[i] < A[i-1])
			{
				swap(A[i],A[i-1]) ; 
			}
		}
		else{

			if (A[i]< max(A[i-1], A[i+1]))
			{
				 if(A[i-1]>= A[i+1])
				 	swap(A[i],A[i-1]);
				 else
				 	swap(A[i], A[i+1]); 
			}
		}
	}
}


int main()
{
	cout<<"please input the array \n";
	std::vector<int> A( (istream_iterator<int>(cin) ), (istream_iterator<int>() ) ); 
	cout<<"the array you put is \n";
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, " ")  );
	cout<<"\n";
	shuffle(A); 
	cout<<"shuffled array \n";
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, " ")  );
	cout<<endl; 
}