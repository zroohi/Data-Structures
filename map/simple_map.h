#ifndef SIMPLE_MAP_H
#define SIMPLE_MAP_H

#include <string>
#include <iostream>

template<class data_t> struct node_t
{
    data_t* key = nullptr;
    data_t* val = nullptr;
    node_t<data_t>* next = nullptr;
};

template<class data_t> class simple_map
{ 
    public:
        simple_map();
        ~simple_map();

        void insert(data_t key, data_t val);
        data_t& retrieve(data_t key);

        data_t& operator[](const data_t key);

    private:
        int arr_size;
        node_t<data_t>* arr;
        
        int hash_val(int key);
        int hash_val(double key);
        int hash_val(float key);
        int hash_val(char key);
        int hash_val(std::string key);
};

template<class data_t> inline data_t& simple_map<data_t>::operator[](const data_t key)
{
   return this->retrieve(key);
};

#endif // SIMPLE_MAP_H