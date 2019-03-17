#pragma once
#include <string>
#include <iostream>

extern const int SIZE;
extern const int MAXINT;

int hash_func(const int x, const int size);
class hash_table {
	int* set;
	int size;
	hash_table(const int* arr, const int arr_size = SIZE, const int hash_size = SIZE);
	~hash_table() { delete[] set; }
	void print();
};

hash_table::hash_table(const int* arr, const int arr_size, const int hash_size) : size(hash_size) {
	set = new int[size];
	for (auto i = 0; i < arr_size; i++) {
		set[hash_func(arr[i], size)] = arr[i];
	}
}

void hash_table::print() {
	for (auto i = 0; i < size; i++) {
		if (set[i] < 0) {
			std::cout << std::width(std::to_string(set[i]));
		}
		else {

		}
	}
}

int hash_func(const int x, const int size) {
	auto a = size - 3;
	auto b = 1;
	return (a*x + b) % size;
}

