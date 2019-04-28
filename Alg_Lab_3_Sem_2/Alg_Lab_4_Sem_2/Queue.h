#pragma once
#include "AVL.h"

struct node;
class avl_tree;

class Queue{
public:
	struct QueueNode {
		node* tree_node;
		QueueNode *next;
		/*QueueNode *prev;*/

		QueueNode(node *p);
		~QueueNode();
	};

	Queue();
	Queue(node* p);
	~Queue();

	void print();
	void push_back(node *node);
	node* pop_front();
	void remove(node* a);
	QueueNode* get_head() { return head; }
	/*void concat(Queue* que);*/
private:
	QueueNode *head;
	QueueNode *tail;
};
