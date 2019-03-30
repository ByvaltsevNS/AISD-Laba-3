#include "Hash.h"
///////////////////////////////
hash_table::hash_table(const int* arr,int arr_size, int size) {
	set = new std::vector<hash_elem*>(size, nullptr);
	for (auto i = 0; i < arr_size; i++)
		add(arr[i]);
}
///////////////////////////////
hash_table::hash_table(const int size): filled(0) {
	set = new std::vector<hash_elem*>(size, nullptr);
}

hash_table::hash_table(const hash_table& A) : filled(0) {
	set = new std::vector<hash_elem*>(A.set->size());
	for (auto i = 0; i < set->size(); i++)
		for (hash_elem* p = A.set->at(i); p; p = p->next)
			add(p->val);
}

void hash_table::print() {
	for (auto i = 0; i < set->size(); i++) {
		std::cout << "[";
		if (!set->at(i)) {
			std::cout.width(std::to_string(MAXINT).size());
			std::cout.fill(' ');
			/*std::cout << "   ";*/
		}
		else {
			for (hash_elem* p = set->at(i); p; p = p->next) {
				std::cout.width(std::to_string(MAXINT).size());
				std::cout << p->val;
				std::cout.fill(' ');
			}
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

void hash_table::add(int to_add) {
	if (filled >= set->size()) {
		std::vector<hash_elem*> *old_set = set;
		set = new std::vector<hash_elem*>(old_set->size(), nullptr);
		filled = 0;
		for (int i = 0; i < old_set->size(); i++) {
			for (hash_elem* p = old_set->at(i); p != nullptr; p = p->next) {
				this->add(p->val);
			}
		}
		delete old_set;
	}
	int hash_to_add = hash_func(to_add, set->size());
	hash_elem *p = set->at(hash_to_add);
	if (p == nullptr) {
		set->at(hash_to_add) = new hash_elem(to_add);
		filled++;
	}
	else {
		for (; p->next != nullptr; p = p->next);
		p->next = new hash_elem(to_add);
	}
}

bool hash_table::find(int to_find) const {
	int hash_to_find = hash_func(to_find, set->size());
	if (!set->at(hash_to_find))
		return false;
	else if (set->at(hash_to_find)->val == to_find)
		return true;
	else {
		for (hash_elem *p = set->at(hash_to_find); p != nullptr; p = p->next)
			if (p->val == to_find)
				return true;
	}
	return false;
}

void hash_table::remove(int val) {
	if (find(val)) {
		if (filled < set->size() / 2) {
			std::vector<hash_elem*> *old_set = set;
			set = new std::vector<hash_elem*>(old_set->size() * 0.5, nullptr);
			filled = 0;
			for (int i = 0; i < old_set->size(); i++) {
				for (hash_elem* p = old_set->at(i); p != nullptr; p = p->next) {
					this->add(p->val);
				}
			}
			delete old_set;
		}
		int hash_to_remove = hash_func(val, set->size());
		hash_elem *p = set->at(hash_to_remove);
		if (p->val == val) {
			set->at(hash_to_remove) = p->next;
			if (p->next == nullptr)
				filled--;
		}
		else {
			for (; p->next->val != val; p = p->next);
			hash_elem *deleted = p->next;
			p->next = deleted->next;
			deleted->next = nullptr;
		}
	}
}

hash_table* dis(const hash_table &h1, const hash_table &h2) {
	int size = h1.set->size() >= h2.set->size() ? h1.set->size() : h2.set->size();
	hash_table* res = new hash_table(size);
	for (auto i = 0; i < size; i++) {
		if (i < h1.set->size()) {
			for (hash_elem* p = h1.set->at(i); p; p = p->next)
				if (!res->find(p->val))
					res->add(p->val);
		}
		if (i < h2.set->size()) {
			for (hash_elem* p = h2.set->at(i); p; p = p->next)
				if (!res->find(p->val))
					res->add(p->val);
		}
	}
	return res;
}

hash_table* con(const hash_table &h1, const hash_table &h2) {
	hash_table* res;
	if (h1.set->size() >= h2.set->size()) {
		res = new hash_table(h2.set->size());
		for (auto i = 0; i < h2.set->size(); i++) 
			for (hash_elem* p = h2.set->at(i); p; p = p->next) 
				if (h1.find(p->val)) 
					res->add(p->val);
	}
	else {
		res = new hash_table(h1.set->size());
		for (auto i = 0; i < h1.set->size(); i++) 
			for (hash_elem* p = h1.set->at(i); p; p = p->next) 
				if (h2.find(p->val)) 
					res->add(p->val);
	}
	return res;
}

hash_table* XOR(const hash_table &h1, const hash_table &h2) {
	hash_table* res;
	if (h1.set->size() >= h2.set->size()) {
		res = new hash_table(h1);
		for (auto i = 0; i < h2.set->size(); i++)
			for (hash_elem* p = h2.set->at(i); p; p = p->next) {
				if (res->find(p->val))
					res->remove(p->val);
				else
					res->add(p->val);
			}
	}
	else {
		res = new hash_table(h2);
		for (auto i = 0; i < h1.set->size(); i++)
			for (hash_elem* p = h1.set->at(i); p; p = p->next) {
				if (res->find(p->val))
					res->remove(p->val);
				else
					res->add(p->val);
			}
	}
	return res;
}