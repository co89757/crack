#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;



// BUGGY @Jul 25
void prefixfunc(string pattern, int pi[])
{
	int m = pattern.size();
	pi[0] = -1 ;
	int k;
	for (int i = 1; i < m; ++i)
	{
		k = pi[i-1];
		while(k>=0){
			if(pattern[k]==pattern[i-1])
				break;
			else
				k = pi[k]; 
		}
		pi[i] = k + 1;
	}
}

int KMP(string pattern, string text)
{   
	int m = pattern.size();
	int n = text.size();
	int x = 0; // indexing the cursor of text 
	int k=0; 
	int pi[m];
	int nMatch = 0;
	// precompute prefix table
	prefixfunc(pattern, pi );

	while(x<n)
	{
		if(k==-1){
			x++;
			k=0;
		}
		else if(pattern[x]==pattern[k])
		{
			++x;
			++k;
			if(k==m)
			{
				cout<<"match found at index "<< x-k << "\n" ;
				++ nMatch;
				
				k = 0;
			}

		}
		else{
			k = pi[k] ;
		}
	}

	return nMatch; 

}





int main()
{
	
	string tar = "san and linux training lin lin";
    string pat = "lin";
    int matches = KMP(pat, tar);
    cout<<"total "<<matches<<" matches \n";
}