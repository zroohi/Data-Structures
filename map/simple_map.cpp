#include "simple_map.h"

template<class data_t> simple_map<data_t>::simple_map()
{
    arr_size = 10000;
    arr = new node_t<data_t>[arr_size];
};

template<class data_t> simple_map<data_t>::~simple_map()
{

};

template<class data_t> int simple_map<data_t>::hash_val(int key)
{
    return key % arr_size;
};
template<class data_t> int simple_map<data_t>::hash_val(double key)
{
    return static_cast<int>(key) % arr_size;
};
template<class data_t> int simple_map<data_t>::hash_val(float key)
{
    return static_cast<int>(key) % arr_size;
};
template<class data_t> int simple_map<data_t>::hash_val(char key)
{
    return (key + '0') % arr_size;
};
template<class data_t> int simple_map<data_t>::hash_val(std::string key)
{
    int val = 0;
    for (int i = 0 ; i < key.size() ; i++)
    {
        val += (key[i] - '0') * 13;
    }
    return val % arr_size;
};

template<class data_t> void simple_map<data_t>::insert(data_t key, data_t val)
{
    node_t<data_t>* loc = arr + hash_val(key);

    // If there's already something here, iterate to the end of the linked list
    while (loc->next)
    {
        loc = loc->next;
    }

    // If there was a collision, setup a new node at the final location
    if (loc->key)
    {
        loc->next = new node_t<data_t>;
        loc = loc->next;
    }
    
    // Insert the appropriate key and value at this location in memory
    loc->key = new data_t(key);
    loc->val = new data_t(val);
};

template<class data_t> data_t& simple_map<data_t>::retrieve(data_t key)
{
    node_t<data_t>* loc = arr + hash_val(key);

    // Iterate along the linked list until we find the node with the correct key
    while(loc && *(loc->key) != key)
    {
        loc = loc->next;
    }

    // If the end node is null, then it means we didn't find that key
    if (!loc)
    {
        std::cout << "ERROR - The key " << key << " is not in this map." << std::endl;
        throw;
    }

    return *(loc->val);
};

// Declare all the different types of templates available
template class simple_map<int>;
template class simple_map<float>;
template class simple_map<double>;
template class simple_map<char>;
template class simple_map<std::string>;