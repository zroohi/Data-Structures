#ifndef LIST_H
#define LIST_H

#include <string>
#include <cstring>
#include <iostream>


class list
{
    public:
        list();
        list(int input_size);
        list(int input_size, int default_val);
        void clear_memory(int default_val = 0);
        void append(int value);
        int retrieve(int position);
        int size();

        int& operator[] (int index);


    private:
        int current_end;
        int list_size;
        int* l;

};


#endif // LIST_H