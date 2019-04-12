#pragma once
#include "AVL.h"

struct node;
class avl_tree;
struct Queue {
	struct QueueNode {
		node* tree_node;
		QueueNode *next;
		QueueNode(node *p);
		~QueueNode();
	};
	QueueNode *head;
	QueueNode *tail;
	Queue();
	~Queue();
	void push_back(node *node);
	node* pop_front();
};

class Bft_iterator {
public:
	node* current;
	Queue *tree_Queue = new Queue;
	Bft_iterator(avl_tree* tree);
	int next();
	bool has_next();
};