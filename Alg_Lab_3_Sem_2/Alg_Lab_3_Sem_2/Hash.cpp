#include "Hash.h"

hash_table::hash_table(const int* arr, const int arr_size) {
	set = new std::vector<hash_elem*>(arr_size, nullptr);
	for (auto i = 0; i < arr_size; i++) {
		add(arr[i]);
	}
}

hash_table::hash_table(const int size) {
	set = new std::vector<hash_elem*>(size, nullptr);
}

void hash_table::print() {
	for (auto i = 0; i < size; i++) {
		std::cout << "[";
		std::cout.width(std::to_string(MAXINT).size());
		if (set[i] < 0)
			std::cout.fill(' ');
		else {
			std::cout << set[i];
			std::cout.fill(' ');
		}
		std::cout << "]";
	}
	std::cout << std::endl;
}

int hash_func(const int x, const int size) {
	auto a = size - 3;
	auto b = 1;
	return (a*x + b) % size;
}

hash_table* dis(const hash_table &h1, const hash_table &h2) {
	int size = h1.set->size() >= h2.set->size() ? h1.set->size() : h2.set->size();
	hash_table* res = new hash_table(size);
	for (auto i = 0; i < size; i++) {
		if (i < h1.set->size()) {
			for (hash_elem* p = h1.set->at(i); p; p = p->next)
				res->add(h1.set->at(i)->val);
		}
		if (i < h2.set->size()) {
			for (hash_elem* p = h2.set->at(i); p; p = p->next)
				res->add(h2.set->at(i)->val);
		}
	}
	return res;
}