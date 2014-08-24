#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


// given an array consisting of only 0s and 1s and 2s. sort it st. all 0s precede all 1s; all 1s precede 2s. "Dutch national flag" problem  
// use the quicksort partition idea

void partition(std::vector<int> & A, int l, int r)
{  
	int i = l ; 
	int j = l;

	while(j<=r)
	{
		if(A[j]==0){
			swap(A[i],A[j]);
			++i;
			++j;
		}
		else{
			++j;
		}
	}

	j = i ;
	while(j<=r)
	{
		if(A[j]==1){
			swap(A[i],A[j]);
			++i;
			++j;
		}
		else{
			++j;
		}
	}
}

int main()
{
	cout<<"give an array of only 0s and 1s and 2s:\n ";
	vector<int> A( (istream_iterator<int>(cin)), (istream_iterator<int>())   );
	cout<<"before sort: \n";
	copy(A.begin(), A.end(), ostream_iterator<int>(cout," ")  ); cout<<"\n";
	int r = A.size()-1;
	partition(A,0,r);
	cout<<"after sort: \n";
	copy(A.begin(), A.end(), ostream_iterator<int>(cout," ")  ); cout<<"\n";
}