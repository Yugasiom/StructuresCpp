#include "list.hpp"


void List::print()
{
    if(head == nullptr) {
        return;
    }

    Node *temp_node = head                 ;
    while(temp_node != nullptr) {
        std::cout << temp_node->data << ' ';
        temp_node  = temp_node->next       ;
    }
}

void List::prepend(int64_t input_data)
{
    Node *new_node = new Node(input_data);
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }

    ++length;
}

void List::append(int64_t input_data)
{
    Node *new_node = new Node(input_data);
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        (*tail).next = new_node;
        tail         = new_node;
    }

    ++length;
}

void List::insert(int64_t input_data, uint64_t index)
{
    Node *new_node = new Node(input_data);
    if(index > (length + 1) || index < 1) {
        return;
    } else if(index == 1) {
        prepend(input_data);
    } else if(index == (length + 1)) {
        append(input_data);
    } else {
        Node *prev_node = get(index - 1) ;
        new_node->next  = prev_node->next;
        prev_node->next = new_node       ;
        ++length                         ;
    }
}

void List::remove(int64_t input_data)
{
    if(head == nullptr) {
        return;
    }

    if(input_data == head->data) {
        Node *next_node = head->next;
        delete head;
        head = next_node;
        if(head == nullptr) {
            tail = nullptr;
        }

        --length;


        return;
    }

    Node *prev_node = head, *current_node = head->next;
    while(current_node != nullptr) {
        if(current_node->data == input_data) {
            Node *next_node = current_node->next;
            prev_node->next = next_node;
            if(current_node == tail) {
                tail = prev_node;
            }

            delete current_node;
            --length;


            return;
        } else {
            prev_node    = current_node;
            current_node = current_node->next;
        }
    }
}

Node *List::get(uint64_t input_index)
{
    Node *current_node = head;
    for(; input_index > 1 && current_node != nullptr; --input_index) {
        current_node = current_node->next;
    }

    return current_node;
}
