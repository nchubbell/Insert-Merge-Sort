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
constexpr void merge( RandomIt first, RandomIt last, RandomIt tempstart ) {
	// vectors created of left and right sides
	vector<typename iterator_traits<RandomIt>::value_type> left(first, tempstart);
	vector<typename iterator_traits<RandomIt>::value_type> right(tempstart, last);

	auto LIT = left.begin();
	auto RIT = right.begin();
	auto result = first;
	// the iterators that are used to merge the values together

	while (LIT != left.end() && RIT != right.end()) { // runs until one reaches the end so it is done sorting
		if (*LIT <= *RIT) {
			*result = *LIT;		
			result++;
			LIT++;
			// puts the left value in the result in the instance that the left is less than the right and increments
        } else {
			*result = *RIT;	
            result++;
			RIT++;
			// puts the right value in result and iterates the right
        }
	}
	// any remainder values are copied into the result to ensure leaving out no values
	copy(LIT,left.end(),result);
	copy(RIT,right.end(),result);
}

template< class RandomIt >
constexpr void mergesort( RandomIt first, RandomIt last, RandomIt tempstart ) {
	if (distance(first, last) <= 1) return; // return if one value remains to enter merge process
	auto mid = first + distance(first, last)/2; // calculate midpoint to use as reference when splitting the array/vector
	mergesort(first,mid,tempstart); // takes left side
	mergesort(mid,last,tempstart); // takes right side
	merge(first,last,mid); // merges both to be sorted
}




int main(int argc, char *argv[]) {
	int a0[] = {56, 23, 11, 64, 43};
	array<int, 5> a1 = {5, 4, 3, 2, 1};
	array<string, 5> a2 = {"lion", "dog", "cat", "fox", "pig"};
	vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9};
	// Examples using closed and dynamic arrays along with vectors
	
	mergesort(&a0[0], &a0[5], a0);
	print(&a0[0], &a0[5]);

	mergesort(a1.begin(), a1.end(), a1.begin());
	print(a1.begin(), a1.end());

	mergesort(a2.begin(), a2.end(), a2.begin());
	print(a2.begin(), a2.end());

	reverse(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	mergesort(a2.begin(), a2.end(), a2.begin());
	print(a2.begin(), a2.end());

	mergesort(v.begin(), v.end(), v.begin());
	print(v.begin(), v.end());

	std::cout << "Problem Size\tTime Taken (seconds)" << std::endl;
	for (int size = 10; size <= 100000000; size *= 10) {
	
		int *a = new int[size];
	
		std::generate(a, a+size, std::rand);
		auto starttime = chrono::steady_clock::now();
        mergesort(a,a+size, a);
		auto endtime = std::chrono::steady_clock::now();
		std::chrono::duration<double> timetaken = endtime - starttime;
		std::cout << size << "\t" << timetaken.count() << std::endl;

		delete[] a;
	}

	return 0;
}
