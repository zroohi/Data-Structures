#include "map/simple_map.h"
#include "list/list.h"

void test_map()
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

void test_list()
{
    list l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    l1.append(8);

    std::cout << l1[0] << std::endl;
}


int main()
{
    //test_map();
    test_list();
}