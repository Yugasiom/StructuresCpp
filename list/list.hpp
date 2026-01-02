#ifndef  LIST_HPP_INCLUDED




#define  LIST_HPP_INCLUDED





#include <cstdint>




#include <iostream>





class Node
{
    public:
        int64_t data;
        Node   *next;

        Node(int64_t input_data) : data(input_data)
        {
            next = nullptr;
        }
};




class List
{
    private:
        Node *head,  *tail;
        uint64_t    length;



    public:
        List() : length(0)
        {
            head = nullptr;
            tail = nullptr;
        }


        void   print()                 ;
        void prepend(int64_t)          ;
        void  append(int64_t)          ;
        void  insert(int64_t, uint64_t);
        void  remove(int64_t)          ;

        Node    *get(uint64_t)         ;


        ~List()
        {
            Node *current_node = head, *next_node;
            while(current_node != nullptr) {
                next_node = current_node->next;
                delete current_node;
                current_node = next_node;
            }

            head = nullptr;
            tail = nullptr;
            length = 0;
        }
};





#endif   /// LIST_HPP_INCLUDED
