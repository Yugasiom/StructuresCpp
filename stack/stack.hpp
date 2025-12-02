#ifndef STACK_HPP_INCLUDED

#define STACK_HPP_INCLUDED


/// C libs(Modern):
#include <cstdio>
#include <cstdlib>
#include <cstdint>

/// C++ libs:
#include <iostream>


#define ERROR_CODE 1
#define ERROR      printf("ERROR\n\n");
#define EXIT       exit(ERROR_CODE);
#define ERROR_EXIT ERROR EXIT


class Stack
{
	private:
		enum {SIZE = 128};

		int64_t arr[SIZE];
		int8_t top_index = -1; // because stack is empty


	public:
		Stack()
		{
			for(uint8_t i = 0; i < SIZE; ++i) {
				arr[i] = 0;
			}
		}


		void push(int64_t);
		void pop();
		void clear();

		void peek() const;
		void print() const;

		uint8_t size() const;
};


#endif // STACK_HPP_INCLUDED
