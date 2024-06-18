#include "map/simple_map.h"

int main()
{
    simple_map<char> m1;
    simple_map<int> m2;
    simple_map<std::string> m3;
    
    m1.insert('a', 'b');
    m2.insert(10001, 250);
    m3.insert("hi", "bye");

    std::cout << m1['a'] << std::endl;
    std::cout << m2[10001] << std::endl;
    std::cout << m3["hi"] << std::endl;
}