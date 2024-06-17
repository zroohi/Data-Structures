#include <string>
#include <iostream>

struct node_t
{
    int key;
    int val;
    node_t* next = nullptr;
};

class simple_map
{ 
    public:
        simple_map();
        ~simple_map();

        void insert(int key, int val);
        int retrieve(int key);

    private:
        int arr_size;
        node_t* arr;
        
        int hash_val(int key);
        

};