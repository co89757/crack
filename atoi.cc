#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iterator>
// #include <memory>
using namespace std;
int atoi(char * str)
{   
	int reval = 0 ;
	if(!str|| ! *str) return -1 ;
	int mult = (*str == '-')? -1: 1 ; 
	if(mult == -1) ++str ; 
	while('0'<= *str && '9'>= *str )
		reval = reval*10 + *str++ - '0' ;

	return mult*reval; 



}
int main()
{
	char s[] = "-231";
	int toi = atoi(s);
	cout<<toi; 
}