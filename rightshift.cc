// right shift by k positions in place for an input array of size N 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void reverse(vector<int> & A, int begin, int end)
{
   for(auto i = begin; i <= begin + (end-begin)/2 ; ++i)
       std::swap(A.at(i), A.at(end+begin-i) );

}

void rightShift(vector<int> & A, int k )
{
   size_t N = A.size();

   reverse(A,0,N-k-1);
    
   reverse(A,N-k,N-1);
    
   reverse(A,0,N-1);
    

}


int main()
{
   vector<int> A = {1,2,3,4,5,6,7,8,9}; 
   int k=3;
   size_t n = A.size();
   cout<<"initial array \n";
   // istream_iterator<int> iterRead(cin);
   // copy(iterRead, istream_iterator<int>(),back_inserter(A) );
   copy(A.cbegin(), A.cend(), ostream_iterator<int>(cout," "));
   cout<<"\n"; 
   rightShift(A,k);
   cout<<"shifted array is \n";
   copy(A.cbegin(), A.cend(), ostream_iterator<int>(cout," "));
   cout<<"\n"; 
    

   // copy(A.cbegin(), A.cend(), ostream_iterator<int>(cout," "));

   // cout<<"\n give shift number k = \n";
   // cin>>k;
   // rightShift(A,k);

   // cout<<"shifted array is \n";
   // copy(A.cbegin(), A.cend(), ostream_iterator<int>(cout," "));




}
