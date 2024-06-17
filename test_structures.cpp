#include "map/simple_map.h"

int main()
{
    simple_map h;

    h.insert(1, 25);
    h.insert(10001, 250);

    std::cout << h.retrieve(1) << std::endl;
    std::cout << h.retrieve(10001) << std::endl;
}