#include "test.hpp"

int8_t test_return_code()
{
    Array arr;

    std::cout << "Append test: " << std::endl;
    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.print();    /// 10 20 30

    std::cout << "Prepend test: " << std::endl;
    arr.prepend(5);
    arr.print();    /// 5 10 20 30

    std::cout << "Insert test: " << std::endl;
    arr.insert(2, 15);
    arr.print();    /// 5 10 15 20 30

    std::cout << "Remove test: " << std::endl;
    arr.remove(15); /// 15
    arr.print();    /// 5 10 20 30

    std::cout << "Find index test: " << std::endl;
    std::cout << "Index of 20: " << arr.find_index(20) << std::endl; /// 2
    std::cout << "Index of 99: " << arr.find_index(99) << std::endl; /// 4

    std::cout << "Resize test(Adding more elements): " << std::endl;
    uint8_t i = 0;
    for(; i < 10; ++i) {
        arr.append(100 + i);
    }

    arr.print();    /// 5 10 20 30 100 101 102 103 104 105 106 107 108 109


    std::cout << "Remove non-existent element: " << std::endl;
    arr.remove(999);
    arr.print();


    Array empty_arr(0);
    std::cout << "Empty array print: " << std::endl;
    empty_arr.print();

    Array sized_arr(5);
    std::cout << "Sized array(Capacity=5) print: " << std::endl;
    sized_arr.print();

    sized_arr.append(1);
    sized_arr.append(2);
    sized_arr.print();


    return 0;
}
