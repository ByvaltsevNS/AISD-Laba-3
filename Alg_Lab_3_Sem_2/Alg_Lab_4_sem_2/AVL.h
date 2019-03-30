#pragma once
#include <iostream>

node* rotate_right(node* p);
node* rotate_left(node* q);
node* balance(node* p); 
void print_tree(node* head, int level);
bool contain(node* head, int key);

struct node {
	int key;
	int height; 
	node* left;
	node* right;
	node(int key): key(key), height(0), left(nullptr), right(nullptr) {}
	int bfactor();
	void fixheight();
};

class avl_tree {
private:
	node* head;
	int height; //??
public:
	avl_tree(): head(0), height(0) {}
	avl_tree(int key): head(new node(key)), height(0) { /*	head = new node(key);*/ }
	~avl_tree() {}
	void print();
	bool find(int key);
	void remove(int key);
	void insert(int key);
};