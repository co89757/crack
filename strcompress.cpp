#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
using std::string;
using std::cout;
using std::endl;
// count the digits of a integer
int countDigits(int x)
{
 	int cnt = 1;

 	while(x/10)
 		++cnt; 
 	return cnt ; 
}


int sizeCompressed(string s)
{
	if (s.empty())
		return 0;
	char last = s.at(0);
	int count = 1;
	int size = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s.at(i)==last)
		{
			++ count;

		}

		else{

			size += 1 + countDigits(count); 
			last = s.at(i);
			count = 1; 

		}


	}

	size += 1 + countDigits(count);
	return size; 
}







string compressStr(string & s)
{
	// check if to proceed to compression
	int comp_size = sizeCompressed(s);
	if (comp_size > s.size())
	{
		return s; 
	}

	// compression starts 
	string mystr;
	char last = s.at(0);
	int count = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (last == s.at(i))
		{
			++ count ;
		}
		else{
			mystr = mystr + last + std::to_string(count); //C++11 
			last = s.at(i);
			count = 1;
		}
	}

	mystr = mystr + last + std::to_string(count);

	return mystr; 


}




int main(int argc, char const *argv[])
{
	string str_a("aaaabbbbbbccccddd");
	cout<<"originial string :\n"<<str_a<<'\n';
	cout<<"compressed string is:\n"; 
	cout<<compressStr(str_a)<<endl; 
	return 0;
}