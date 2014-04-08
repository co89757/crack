#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
int main(){
	using namespace std;
	bool isUniqueChar(char *str);
	char * s="icde";
	bool ant=isUniqueChar(s);
	cout<<ant<<endl;

}
bool isUniqueChar(char *str){
	bool repeat[256];
	int i ;
	for(i=0;i<strlen(str);i++){
		char val = str[i];
		if(repeat[val]) return false;
		else repeat[val]=true; 
	}
	return true ; 
}