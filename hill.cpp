#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm> 
using namespace std ; 

/*
1.Hill
Given an array of integer elements
Your task is to
        write a function that finds the minimum value X that makes possible the following: generate a new array that is sorted in strictly ascending order by increasing or decreasing each of the elements of the initial array with integer values in the [0, X] range.
o        Example: Having the initial array [5, 4, 3, 2, 8] the minimum value for X is 3. Decrease the first element (5) by 3, decrease the second one (4) by 1, increase the third one (3) by 1, increase the forth one (2) by 3 and do nothing to the last one (8). In the end we obtain the array [2, 3, 4, 5, 8] which is sorted in strictly ascending order.
        print the result X to the standard output (stdout)
Note that your function will receive the following arguments:
        v
o        which is the array of integers

*/

int findX(const vector<int> & v)
{

	if (is_sorted(v.begin(),v.end()))
		return 0;  //X=0 




	size_t N = v.size() ;
	vector<int> vbuffer(N) ; 
	copy(v.begin(),v.end(),vbuffer.begin()); // copy the v content to buffer 
	sort(vbuffer.begin(),vbuffer.end()); // sort vbuffer 

	int X_max = 0 ;
	for (int i = 0; i < N; ++i)
	{
		int delta=abs(v[i]-vbuffer[i]) ;
		if (delta > X_max)
		{
			X_max = delta ; 
		}
	}


	int * temp = new int[N] ; 
	for (int x = 1; x < X_max+1; ++x) // search for minX 
	{
		////////////////// temp array content filling 
		temp[0] = v.at(0)-x ;
		for (int j = 1; j < N; ++j)
		 {
		 	temp[j] = temp[j-1]+1; 
		 } 
		 ///////////////////

		int k ; 
		for (k = 1; k < N; ++k)
		{	
			int minimum_next = temp[k-1]+1 ;
			if (v[k]+x < minimum_next )
				break; // the current x doesn't satisfy, increment to x+1 
		}
		if (k==N)
			return x ;
		else{continue ; }

	}
	

}

























int main(int argc, char **argv){

	vector<int> array = {5,4,3,2,8,1,9};  //C++11

	int x = findX(array) ;

	cout<<"the X = "<<x<<endl ; 

	
}