#include <iostream>
#include <string>

int main()
{
 std::string word("abcdef");
 for(auto c: word)
    std::cout<<c<<"=";
 std::cout<<"\n";
}
