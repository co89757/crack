#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
void reverse(char *str);
int main(){
	char s[]="abcdefg";
	reverse(s);
	printf("reversed string is:\n %s\n",s );
}
void reverse(char *str){
	char * end = str;
	char tmp;
	if(str){
		while(*end) ++end;
		--end;
		while(str < end){
			tmp = *str;
			*str++ = *end;
			*end--=tmp;
		}
	}
}