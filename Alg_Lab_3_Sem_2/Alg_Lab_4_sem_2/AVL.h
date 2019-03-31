#pragma once
#include <iostream>
#include "Iterator.h"

struct node {
	int key;
	int height;
	node* left;
	node* right;
	node(int key) : key(key), height(0), left(nullptr), right(nullptr) {}
	int b_factor();
	void fix_height();
};

class avl_tree {
private:
	node* head;
	int height; 
	void print(node* head, int level);
	bool find(node* head, int key);
	node* insert(node* p, int key);
	node* remove(node* p, int key); 
public:
	avl_tree(): head(0), height(0) {}
	avl_tree(int key): head(new node(key)), height(0) { /*	head = new node(key);*/ }
	avl_tree(avl_tree &tree);
	~avl_tree() {}
	void print();
	bool find(int key);
	void insert(int key);
	void remove(int key);
};

node* rotate_right(node* p);
node* rotate_left(node* q);
node* balance(node* p);
node* find_min(node* p); // поиск узла с минимальным ключом в дереве p 
node* remove_min(node* p); // удаление узла с минимальным ключом из дерева p