/* 
    Name: Nathan Hubbell
 	Email: nchubbell@crimson.ua.edu
	Course Section: Fall 2024 CS 201
	Homework #: 0
*/
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>

using namespace std;

template< class RandomIt >
void print(RandomIt start, RandomIt end) {
	while (start != end) {
		cout << *start << " ";
		++start;
	}
	cout << endl;
}

template< class RandomIt >
constexpr void insertionsort(RandomIt start, RandomIt end) {
	// Loop that iterates for the amount of values are in the array/vector minus one
    for (RandomIt j = next(start); j != end; ++j) {
		// Key is the value that I will be compared to
        auto key = *j;
        RandomIt i = prev(j);
		

        while (i != prev(start) && *i > key) {
            *next(i) = *i;
            i--;
        }
        *next(i) = key;
    }
}


int main(int argc, char *argv[]) {
	int a0[] = {56, 23, 11, 64, 43};
	array<int, 5> a1 = {5, 4, 3, 2, 1};
	array<string, 5> a2 = {"lion", "dog", "cat", "fox", "pig"};
	vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9};
	// Examples using closed and dynamic arrays along with vectors

	insertionsort(begin(a0), end(a0));
	print(a0, a0+5);

	insertionsort(&a0[0], &a0[5]);
	print(&a0[0], &a0[5]);

	insertionsort(a1.begin(), a1.end());
	print(a1.begin(), a1.end());

	insertionsort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	reverse(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	insertionsort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	insertionsort(v.begin(), v.end());
	print(v.begin(), v.end());

	std::cout << "Problem Size\tTime Taken (seconds)" << std::endl;
	for (int size = 10; size <= 100000000; size *= 10) {
	
		int *a = new int[size];
	
		std::generate(a, a+size, std::rand);
		auto starttime = chrono::steady_clock::now();
        insertionsort(a,a+size); //run insertion sort funtcion
		auto endtime = std::chrono::steady_clock::now();
		std::chrono::duration<double> timetaken = endtime - starttime;
		std::cout << size << "\t" << timetaken.count() << std::endl;

		delete[] a;
	}

	return 0;
}
