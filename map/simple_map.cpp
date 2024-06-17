#include "simple_map.h"

simple_map::simple_map()
{
    arr_size = 10000;
    arr = new node_t[arr_size];
};

simple_map::~simple_map()
{

};

int simple_map::hash_val(int key)
{
    return key % arr_size;
};

void simple_map::insert(int key, int val)
{
    node_t* loc = arr + hash_val(key);

    // If there's already something here, iterate to the end of the linked list
    while (loc->next)
    {
        loc = loc->next;
    }

    // If there was a collision, setup a new node at the final location
    if (loc->key)
    {
        loc->next = new node_t;
        loc = loc->next;
    }
    
    // Insert the appropriate key and value at this location in memory
    loc->key = key;
    loc->val = val;
};

int simple_map::retrieve(int key)
{
    node_t* loc = arr + hash_val(key);

    // Iterate along the linked list until we find the node with the correct key
    while(loc && loc->key != key)
    {
        loc = loc->next;
    }

    // If the end node is null, then it means we didn't find that key
    if (!loc)
    {
        std::cout << "ERROR - The key " << key << " is not in this map." << std::endl;
        throw;
    }

    return loc->val;
};