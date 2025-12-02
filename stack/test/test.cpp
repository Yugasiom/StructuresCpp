#include "test.hpp"



int8_t main_stack_test()
{
    printf("\n");


    the_second_test();


    printf("\n\n");

    return 0;
}


void the_second_test()
{
    Stack stack;



    stack.clear();
    stack.print();


    stack.push(1);
    stack.print();

    stack.push(2);
    stack.print();

    stack.push(3);
    stack.print();

    stack.push(4);
    stack.print();

    stack.push(5);
    stack.print();


    stack.clear();
    stack.print();
}

void the_first_test()
{
    Stack stack;



    stack.push(1);
    stack.print();

    stack.push(2);
    stack.print();

    stack.push(3);
    stack.print();


    stack.pop();
    stack.peek();
    stack.pop();
}
