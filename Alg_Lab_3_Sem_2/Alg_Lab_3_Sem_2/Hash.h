#pragma once
#include <string>
#include <iostream>
#include <vector>

extern const int SIZE;
extern const int MAXINT;

int hash_func(const int x, const int size);

struct hash_elem {
	int val;
	hash_elem* next;
	hash_elem(int val, hash_elem* next = nullptr) : val(val), next(next) {}
};

class hash_table {
private:
	std::vector<hash_elem*> *set;
	int filled;
public:
	hash_table(const int* arr, const int arr_size = SIZE);
	hash_table(const int arr_size = SIZE);
	hash_table(const hash_table& A);
	~hash_table() { delete set; }
	void print();
	void add(int val);
	bool find(int to_find) const;
	void remove(int val);
	friend hash_table* dis(const hash_table &h1, const hash_table &h2);
	friend hash_table* con(const hash_table &h1, const hash_table &h2);
	friend hash_table* XOR(const hash_table &h1, const hash_table &h2);
};


