#pragma once
#include "AVL.h"

struct node;
class avl_tree;

struct Queue{
	struct QueueNode {
		node* tree_node;
		QueueNode *next;
		QueueNode *prev;

		QueueNode(node *p);
		~QueueNode();
	};
	QueueNode *head;
	QueueNode *tail;

	Queue();
	Queue(node* p);
	~Queue();

	void print();
	void push_back(node *node);
	node* pop_front();
	node* remove(node* a);
};
