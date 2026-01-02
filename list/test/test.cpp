#include "test.hpp"

int8_t test_rc()
{
    List l;


    l.print();
    l.remove(100);
    l.insert(7, 1);
    l.print();              /// 7

    std::cout << std::endl;

    l.insert(8, 0);
    l.insert(9, 5);
    l.print();              /// 7

    std::cout << std::endl;

    l.prepend(6);           /// 6 7
    l.append(10);           /// 6 7 10
    l.print();

    std::cout << std::endl;

    l.insert(20, 2);        /// 6 20 7 10
    l.print();

    std::cout << std::endl;

    l.remove(6);            /// 20 7 10
    l.print();

    std::cout << std::endl;

    l.remove(10);           /// 20 7
    l.print();

    std::cout << std::endl;

    l.remove(999);
    l.print();

    std::cout << std::endl;

    l.remove(20);           /// 7
    l.remove(7);
    l.print();


    return 0;
}
