#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//quicksort impl. 
int partition(vector<int>& A,int l, int r )
{
  int pivot = A.at(l);
  int i=l+1;
  int j=l+1;
 

 // @NOTE: the terminating cue is j<=r not j<r 
 while(j<=r){
   if(A[j]<pivot) {
      swap(A[j],A[i]);
      ++i; 
      ++j;
   }
   else{
   ++j;
   }



 }
  

  swap(A[i-1],A[l]);
  return (i-1);
  
}

void qsort(vector<int>& A, int l , int r)
{
  int p;
  if(l<r){
   p = partition(A,l,r);
   qsort(A,l,p-1);
   qsort(A,p+1,r);
  }
}


int main()
{
  cout<<"please give an array\n";
  vector<int> A( (istream_iterator<int>(cin)), (istream_iterator<int>())   );
  cout<<"array before sorting: \n";
  copy(A.begin(),A.end(),ostream_iterator<int>(cout," ")); cout<<"\n";
  int r = A.size()-1;
  qsort(A,0,r);
  cout<<"sorted array:\n";
copy(A.begin(),A.end(),ostream_iterator<int>(cout," ")); cout<<"\n";

}
