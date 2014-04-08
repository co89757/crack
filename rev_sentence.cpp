#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std; 
/* 
reverse a sentence, without reversing individual words 
e.g. given 'i am a boy' should output 'boy a am i' 

algorithm description:

doing 2 passes. 1st pass reverses each word ; 2nd pass reverse the whole sentence string. 

for example: 
"i am colin" -----> "i ma niloc" -----> "colin am i" 


*/

//subroutine: reverse a cstring 
void reverseString(char* s , int len) //len is string size, not incl. \0
{
	for (int i = 0; i < len/2; ++i)
	{
		s[i] ^= s[len-1-i]; 
		s[len-1-i] ^= s[i];
		s[i] ^= s[len-1-i]; 
	}
} 




void reverseSen(char *s)
{
	char *trailing = s;
	while(*trailing) { 
	while(*trailing && *trailing == ' ')
		++trailing; 
	char *forward=trailing;
	while(*forward && *forward != ' ')
		++forward;
	reverseString(trailing,forward-trailing);
	trailing = forward;

					}

	reverseString(s, strlen(s)); 

}

















int main(int argc, char **argv){

	char s[]="abcdefg";
	char ss[]="I am a little boy";

	// int N = 7;
	reverseSen(ss);
	printf("the reversed sentence is : %s\n", ss);
}
