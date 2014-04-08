// determine if a integer is a palindrome such as 121 . negatives don't count 
#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
   if(x < 0 ) return false ; 

   int div = 1; 
   while(x/div >= 10 ) 
   	div = div*10 ; // div the 10s power with the same # digits as x. div(121)=100 e.g. 
   while(x!=0)
     {
	int head = x / div ; 
	int tail = x % 10 ; 
	if(head != tail)  return false;

	// remove head and tail of x
	x = (x % div) / 10 ; 

	div /= 100; 




     }

  return true;


}

int main()
{
  cout<<"input an integer(non-negative) to see if it's a palindrome :\n"; 
  int x ;
  cin>>x;
  
  bool re = isPalindrome(x) ;
  
  if(re)
  	cout<<x<<" is a palindrome. \n ";
 else
     cout<<x<<"is not a palindrome.\n";


}




