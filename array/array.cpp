#include "array.hpp"



Array::Array(uint64_t input_capacity)
{
    capacity = input_capacity;
    if(capacity == 0) {
        data = nullptr;
    } else {
        data = new int64_t[capacity];
    }

    current_size = 0;
}


void Array::print() const
{
    uint64_t i = 0;
    for(; i < current_size; ++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}

void Array::resize(uint64_t new_capacity)
{
    int64_t *new_data = new int64_t[new_capacity];
    if(data != nullptr) {
        uint64_t i = 0;
        for(; i < current_size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
    }

    data = new_data;
    capacity = new_capacity;
}

uint64_t Array::find_index(int64_t value) const
{
    uint64_t i = 0;
    for(; i < current_size; ++i) {
        if(data[i] == value) {
            return i;
        }
    }

    return current_size;
}

void Array::prepend(int64_t value)
{
    if(current_size == capacity) {
        resize(++capacity);
    }

    uint64_t t = current_size;
    for(; t > 0; --t) {
        data[t] = data[t - 1];
    }

    data[0] = value;
    ++current_size;
}

void Array::append(int64_t value)
{
    if(current_size == capacity) {
        resize(++capacity);
    }

    data[current_size] = value;
    ++current_size;
}

void Array::insert(uint64_t index, int64_t value)
{
    if(index > current_size) {
        return;
    }

    if(current_size == capacity) {
        resize(++capacity);
    }

    uint64_t t = current_size;
    for(; t > index; --t) {
        data[t] = data[t - 1];
    }

    data[index] = value;
    ++current_size;
}

void Array::remove(int64_t value)
{
    uint64_t i = find_index(value);
    if(i == current_size) {
        return;
    }

    for(; i < current_size - 1; ++i) {
        data[i] = data[i + 1];
    }

    --current_size;
}


Array::~Array()
{
    current_size = 0           ;
    capacity     = current_size;
    delete[]       data        ;
}
