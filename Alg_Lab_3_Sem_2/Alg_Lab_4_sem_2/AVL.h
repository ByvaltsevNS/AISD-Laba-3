#pragma once
#include <iostream>
#include "Iterator.h"

struct node {
	int key;
	int height;
	node* left;
	node* right;
	node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}
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
	friend class Bft_iterator;
	avl_tree(): head(0), height(0) {}
	avl_tree(int key): head(new node(key)), height(0) {}
	avl_tree(avl_tree* tree);
	~avl_tree() {}
	void print();
	bool find(int key);
	void insert(int key);
	void remove(int key);
	friend avl_tree* dis(avl_tree* t1, avl_tree* t2);
	friend avl_tree* con(avl_tree* t1, avl_tree* t2);
	friend avl_tree* XOR(avl_tree* t1, avl_tree* t2);
};

node* rotate_right(node* p);
node* rotate_left(node* q);
node* balance(node* p);
node* find_min(node* p); // ����� ���� � ����������� ������ � ������ p 
node* remove_min(node* p); // �������� ���� � ����������� ������ �� ������ p