#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

extern const int MAX;
const int RES = 30;

class My_Set {
	char name;
	std::set<int> Set;
	std::vector<int> Seq;
public: 
	My_Set(char name) : name(name) { Seq.reserve(RES); }
	My_Set(char name, const int size, const int max = MAX);
	My_Set(const My_Set& var) = default;
	My_Set(My_Set&& var);
	My_Set& operator =(const My_Set& var) = default;
	My_Set& operator =(My_Set&& var);

	void print() const;
	void insert(int value) { Seq.push_back(*Set.insert(value).first); }
	bool find(int value) const;
	void remove(int value);
	size_t get_power() { return Set.size(); }

	My_Set operator &(const My_Set& var) const;
	My_Set operator |(const My_Set& var) const;
	My_Set operator /(const My_Set& var) const;

	friend My_Set merge(const My_Set& A, const My_Set& B);
	friend My_Set concat(const My_Set& A, const My_Set& B);
	friend My_Set mul(const My_Set& var, size_t num);
};