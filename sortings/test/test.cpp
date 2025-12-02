#include "test.hpp"

int8_t main_sortings_test()
{
	printf("\n");


	srand(time(NULL));


	SortArr sort_arr;

	printf("Available options:\n    %s\n    %s\n    %s"
	       "\n    %s\n    %s\n    %s\n    %s\n\n",
	       "NOT_SORT", "BUBBLE", "OPTIMIZE_BUBBLE",
	       "INSERT", "SELECTION", "MERGE", "QUICK");

	sort_arr.print();
	/// sort_arr.print(NOT_SORT);

	printf("\n\n");

	/// _arr.print(DESIRED_SORTING);
	sort_arr.print(QUICK);


	printf("\n\n");

	return 0;
}
