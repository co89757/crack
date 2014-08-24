#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// print combinations of a set. C(n,m) backtracking

//helper 
bool isIn(int a[], int N, int e){
    for (int i = 0; i < N; ++i)
    {
    	if(e==a[i]) return true;
    }

    return false;
}

void permutations(int a[], vector<int>& S, int k, int m)
{	//process solution
	if(k==m)
	{
		cout<<"{ ";
		for (int i = 1; i <= k; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<"}\n";
	}

	else{

		++k;
		// construct candidates 
		vector<int> cands ; 
		for (int i = 0; i != S.size(); ++i)
		{
			if( ! isIn(a,k,S[i]) )
				cands.push_back(S[i]);
		}

		// iterate candidates

		for (int i = 0; i < cands.size(); ++i)
		{
			a[k] = cands[i];
			permutations(a,S,k,m);
		}








	}
}

void combinations(int a[], vector<int>& S, int k, int m)
{	//process solution
	if(k==m)
	{
		cout<<"{ ";
		for (int i = 1; i <= k; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<"}\n";
	}

	else{

		++k;
		// construct candidates 
		vector<int> cands ; 
		for (int i = 0; i != S.size(); ++i)
		{
			if( ! isIn(a,k,S[i]) && S[i]>a[k-1])
				cands.push_back(S[i]);
		}

		// iterate candidates

		for (int i = 0; i < cands.size(); ++i)
		{
			a[k] = cands[i];
			combinations(a,S,k,m);
		}








	}
}

int main()
{
	vector<int> S = {1,2,3};
	int m =2;
	int a[3];
	// permutations(a,S,0,m);
	combinations(a,S,0,m);

}
