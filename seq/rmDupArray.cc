#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int rmDupArray(vector<int> & A)
{
	if (!is_sorted(A.begin(),A.end()) || A.empty())
	{
		return -1; 
	}

    int len = A.size(); 
    int last = A[0];
    int i = 1;
    while( i < len){
    	if(last == A[i]){
    		for (int j = i; j < len-1; ++j)
    		{
    			A[j]=A[j+1];
    			--len;
    			
    			++i;
    		}
    	}
    	else{
    		++i;
    		last = A[i];
    	}
    }

    return len;

}


int main()
{
	cout<<"give a sorted array \n";
	vector<int> v((istream_iterator<int>(cin)), (istream_iterator<int>())  );
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," ")); 

	int newl = rmDupArray(v);
	cout<<"removed duplicates whose new length = "<<newl<<" :\n";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," ")); 
	cout<<"\n";

}