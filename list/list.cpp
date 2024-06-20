#include "list.h"

list::list()
{
    list_size = 1;
    current_end = 0;
    l = new int[list_size];
    clear_memory();
}

list::list(int input_size)
{
    list_size = input_size;
    current_end = 0;
    l = new int[list_size];
    clear_memory();
}

list::list(int input_size, int default_val)
{
        list_size = input_size;
        current_end = list_size;
        l = new int[list_size];
        clear_memory(default_val);
}

void list::clear_memory(int default_val)
{
    for (int i = 0 ; i < list_size ; i++)
    {
        l[i] = default_val;
    }
}

void list::append(int value)
{
    // A new list is needed
    if (current_end + 1 >= list_size)
    {
        list_size *= 2;
        int* new_list = new int(list_size);
        std::memcpy(new_list, l, list_size);
        delete l;
        l = new_list;
    }

    // Append the value
    l[current_end] = value;
}

int list::retrieve(int position)
{
    return l[position];
}

int list::size()
{
    return current_end;
}

int& list::operator[] (int index)
{
    if (index > current_end)
    {
        std::cout << "ERROR - Index " << index << " is out of bounds";
        throw;
    }
    return l[index];
}