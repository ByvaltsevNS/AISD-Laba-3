#pragma once
#include <iostream>
#include "Iterator.h"

struct node {
	int key;
	unsigned char height;
	unsigned int number;
	node* left;
	node* right;
	node(int key) : key(key), height(1), number(0), left(nullptr), right(nullptr) {}
	node(int key, unsigned int number) : key(key), height(1), number(number), left(nullptr), right(nullptr) {}
	int b_factor();
	void fix_height();
};
//
//struct elem {
//	int key;
//	elem* next;
//	elem(int key): key(key), next(nullptr) {}
//	elem(int key, elem* next): key(key), next(next) {}
//	~elem() {}
//};

class avl_tree {
private:
	node* head;
	int height; 
	unsigned int size;
	void print(node* head, int level);
	node* find(node* head, int key);
	node* insert(node* p, int key);
	node* remove(node* p, int key); 
public:
	friend class Bft_iterator;
	avl_tree(): head(0), height(0), size(0) {}
	avl_tree(int key): head(new node(key, 0)), height(0), size(1) {}
	avl_tree(avl_tree* tree);
	~avl_tree();
	void print();
	node* find(int key);
	void insert(int key);
	void remove(int key);
	node* find_num(int num);
	friend avl_tree* dis(avl_tree* t1, avl_tree* t2);
	friend avl_tree* con(avl_tree* t1, avl_tree* t2);
	friend avl_tree* XOR(avl_tree* t1, avl_tree* t2);
};

node* rotate_right(node* p);
node* rotate_left(node* q);
node* balance(node* p);
node* find_min(node* p); // поиск узла с минимальным ключом в дереве p 
node* remove_min(node* p); // удаление узла с минимальным ключом из дерева p