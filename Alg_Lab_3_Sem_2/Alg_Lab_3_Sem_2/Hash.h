#pragma once
#include <string>
#include <iostream>
#include <vector>

extern const int SIZE;
extern const int MAXINT;

int hash_func(const int x, const int size);

class hash_table;

class hash_elem {
private:
	int val;
	hash_elem* next;
public:
	hash_elem(int val, hash_elem* next = nullptr) : val(val), next(next) {}
	friend hash_table* dis(const hash_table &h1, const hash_table &h2);
	friend hash_table;
};

class hash_table {
private:
	std::vector<hash_elem*> *set;
public:
	hash_table(const int* arr, const int arr_size = SIZE);
	hash_table(const int arr_size = SIZE);
	~hash_table() { delete[] set; }
	void print();
	void add(int val);
	friend hash_table* dis(const hash_table &h1, const hash_table &h2);
};


