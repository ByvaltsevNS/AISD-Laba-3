#pragma once
#include <iostream>

struct node {
	int key;
	int height; 
	node* left;
	node* right;
	node(int key): key(key), height(0), left(nullptr), right(nullptr) {}
};

class avl_tree {
private:
	int height; //??
public:
	node* head;
	avl_tree(): head(0), height(0) {}
	avl_tree(int key): height(0) {
		head = new node(key);
	}
	bool find(int key);
	void remove(int key);
	void insert(int key);
};