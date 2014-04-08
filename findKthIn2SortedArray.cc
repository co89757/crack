// find K-th smallest number in 2 sorted arrays A and B 


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// using 2 pointers. move the min of the two each time until K-th smallest is found O(k) better: O(lgm + lgn) 
int findKth(std::vector<int> & A, std::vector<int>& B, int K)
{
	int currentRank = 0; 
	vector<int>::iterator p = A.begin() ;
	vector<int>::iterator q = B.begin() ; 
	while(currentRank != K){
		 if(*p < *q)
		 {
		 	++currentRank; 
		 	if(currentRank == K)
		 		return *p ; 
		 	++p ;  
		 }

		 else{
		 	++currentRank; 
		 	if(currentRank == K)
		 			return *q ; 
		 	++q ; 

		 }  // BUG: What if *p == *q ? 



	}
} 





int main()
{
	vector<int> A = {1,10,14,19,25};
	vector<int> B = {3,5,17,29} ;
	int z = findKth(A,B,5);
	cout<<z<<endl; 
}