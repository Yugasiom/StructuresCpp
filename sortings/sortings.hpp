#ifndef SORTINGS_HPP_INCLUDED

#define SORTINGS_HPP_INCLUDED


/// C libs(Modern):
#include <ctime>
#include <cstdio>
#include <cstdint>
#include <cstdlib>

/// C++ libs:
#include <random>       // for the std::random_device & std::mt19937
#include <limits>
#include <iostream>
#include <algorithm>


#define SIZE            10000

#define NOT_SORT        'n'
#define BUBBLE          'b'
#define OPTIMIZE_BUBBLE 'o'
#define INSERT          'i'
#define SELECTION       's'
#define MERGE           'm'
#define QUICK           'q'


class SortArr
{
	private:
		enum {size = SIZE};
		uint64_t arr[size];

	public:
		SortArr()
		{
			for(uint64_t i = 0; i < size; ++i) {
				arr[i] = i + 1;
			}

			std::random_device rd;
			std::mt19937 gen(rd());

			for(uint64_t i = size - 1; i > 0; --i) {
				std::uniform_int_distribution<uint64_t> dist(0, i);
				uint64_t j = dist(gen);
				std::swap(arr[i], arr[j]);
			}
		}


		void sort_bubble();
		void sort_optimize_bubble();
		void sort_insert();
		void sort_selection();
		void sort_merge(uint64_t [], uint64_t = size);
		void merge_sort(uint64_t [], uint64_t [], uint64_t [], uint64_t, uint64_t);
		void sort_quick(uint64_t, uint64_t);

		void print() const;
		void print(char = NOT_SORT);
};


#endif                  // SORTINGS_HPP_INCLUDED
