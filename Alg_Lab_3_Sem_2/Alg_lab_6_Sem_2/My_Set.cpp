#include "My_Set.h"

My_Set::My_Set(char name, const int size, const int max) : name(name) {
	Seq.reserve(RES);
	for (int i = 0; i < size; ++i)
	{
		Seq.push_back(*Set.insert(std::rand() % max).first);
	}
}

My_Set::My_Set(My_Set&& var) {
	name = var.name;
	var.Set.swap(Set);
	var.Seq.swap(Seq);
}

void My_Set::print()const {
	std::cout << "\n" << name << ": ";
	for (auto x : Set) 
		std::cout << x << " ";
	std::cout << "\n [ ";
	for (auto x : Seq) 
		std::cout << x << " "; 
	std::cout << "]";
}

bool My_Set::find(int value) const {
	return Set.find(value) != Set.end() ? true : false;
}

void My_Set::remove(int value) {
	if (Set.find(value) != Set.end()) {
		Set.erase(Set.find(value));
		std::vector<int>::iterator It = Seq.begin();
		for (It; It != Seq.end(), *It != value; It++);
		if (It != Seq.end())
			Seq.erase(It);
	}
}

My_Set& My_Set::operator =(My_Set&& var) {
	if (this != &var) {
		var.Set.swap(Set);
		var.Seq.swap(Seq);
	}
	return *this;
}

My_Set My_Set::operator &(const My_Set& var) const  {
	My_Set res('&');
	std::set_intersection(Set.begin(), Set.end(), var.Set.begin(), var.Set.end(), 
		std::inserter(res.Set, res.Set.end()));
	for (auto x : res.Set)
		res.Seq.push_back(x);
	return res;
}

My_Set My_Set::operator |(const My_Set& var) const{
	My_Set res('|');
	std::set_union(Set.begin(), Set.end(), var.Set.begin(), var.Set.end(),
		std::inserter(res.Set, res.Set.end()));
	res.Seq.reserve(res.Set.size());
	for (auto x : res.Set)
		res.Seq.push_back(x);
	return res;
}

My_Set My_Set::operator /(const My_Set& var)  const{
	My_Set res('/');
	std::set_symmetric_difference(Set.begin(), Set.end(), var.Set.begin(), var.Set.end(),
		std::inserter(res.Set, res.Set.end()));
	res.Seq.reserve(res.Set.size());
	for (auto x : res.Set)
		res.Seq.push_back(x);
	return res;
}

My_Set merge(const My_Set& A, const My_Set& B) {
	My_Set res = concat(A, B);
	sort(res.Seq.begin(), res.Seq.end());
	return res;
}

My_Set concat(const My_Set& A, const My_Set& B) {
	My_Set res('C');
	res.Seq = A.Seq;
	res.Seq.reserve(A.Seq.size() + B.Seq.size());
	std::copy(B.Seq.begin(), B.Seq.end(), std::back_inserter(res.Seq));
	std::set_union(A.Set.begin(), A.Set.end(), B.Set.begin(), B.Set.end(),
		std::inserter(res.Set, res.Set.end()));
	return res;
}

My_Set mul(const My_Set& var, size_t num) {
	My_Set res('C');
	if (num > 0 && num <= 5 && !var.Set.empty()) {
		res.Set = var.Set;
		res.Seq.reserve(var.Set.size() * num);
		for (auto i = 0; i < num; i++)
			std::copy(var.Seq.begin(), var.Seq.end(), std::back_inserter(res.Seq));
	}
	return res;
}