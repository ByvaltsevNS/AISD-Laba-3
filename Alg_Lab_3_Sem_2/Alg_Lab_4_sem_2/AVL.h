#pragma once
#include <iostream>
#include <exception>
#include "Queue.h"

struct Queue;

struct node {
	int key;
	unsigned char height;
	node* left;
	node* right;

	node(int key) : key(key), height(1),  left(nullptr), right(nullptr) {}
	int b_factor();
	void fix_height();
};

class avl_tree {
private:
	node* head;
	Queue* seque;

	void print(node* head, int level);
	node* find(node* head, int key);
	node* insert(node* p, int key);
	node* remove(node* p, int key); 
public:
	friend class Bft_iterator;

	avl_tree();
	avl_tree(int key);
	avl_tree(avl_tree* tree);
	~avl_tree();

	void print();
	node* find(int key);
	void insert(int key);
	void remove(int key);
	void get_sorted_que(Queue* que);

	friend avl_tree* dis(avl_tree* t1, avl_tree* t2);
	friend avl_tree* con(avl_tree* t1, avl_tree* t2);
	friend avl_tree* XOR(avl_tree* t1, avl_tree* t2);
	friend avl_tree* merge(avl_tree* t1, avl_tree* t2);
	friend avl_tree* concat(avl_tree* t1, avl_tree* t2);
	friend avl_tree* mul(avl_tree* tree, int n);
};

node* rotate_right(node* p);
node* rotate_left(node* q);
node* balance(node* p);
node* find_min(node* p); // ����� ���� � ����������� ������ � ������ p 
node* remove_min(node* p); // �������� ���� � ����������� ������ �� ������ p

void get_sorted_que(node* head, Queue* que);