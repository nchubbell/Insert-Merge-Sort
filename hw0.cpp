#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std;

template< class RandomIt >
constexpr void insertionsort(RandomIt start, RandomIt end) {
    for (RandomIt j = next(start); j != end; ++j) {
        auto key = *j;
        RandomIt i = j;
        
        // Move elements of the sorted segment that are greater than key to one position ahead
        while (i != start && *prev(i) > key) {
            *i = *prev(i);
            --i;
        }
        *i = key;
    }
}

int main(int argc, char *argv[]) {

	std::cout << "Problem Size\tTime Taken (seconds)" << std::endl;
	for (int size = 10; size <= 100000000; size *= 10) {
	
		int *a = new int[size];
	
		std::generate(a, a+size, std::rand);
		auto starttime = std::chrono::steady_clock::now();
        sort(a,a+size);
		// insertionsort(a, a+size);
		auto endtime = std::chrono::steady_clock::now();
		std::chrono::duration<double> timetaken = endtime - starttime;
		std::cout << size << "\t" << timetaken.count() << std::endl;

		delete[] a;
	}

	return 0;
}