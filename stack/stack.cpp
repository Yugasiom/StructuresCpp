#include "stack.hpp"



void Stack::push(int64_t input_elem)
{
	/* if(arr[SIZE - 1] != 0) {
	    ERROR

	    return;
	}

	or

	*/


	if(top_index >= SIZE - 1) {
		ERROR

		return;
	}


	arr[++top_index] = input_elem;


	/// peek();
}

void Stack::pop()
{
	/// peek();

	if(top_index == -1) {
		ERROR

		return;
	}

	--top_index; // or arr[top_index--];
}

void Stack::clear()
{
	if(top_index == -1) {
		return;
	}

	uint8_t current_size = size();
	for(uint8_t i = 0; i < current_size; ++i) {
		pop();
	}

	printf("Cleaning is complete!!!");
}


void Stack::peek() const
{
	printf("\nThe top of the Stack: %ld\n", arr[top_index]);
}

void Stack::print() const
{
	if(top_index == -1) {
		return;
	}

	uint8_t current_size = size();
	for(uint8_t i = 0; i < current_size; ++i) {
		printf("%ld\n", arr[i]);
	}

	printf("\n");
}


uint8_t Stack::size() const
{
	return top_index + 1;
}

