#pragma once
#include "AVL.h"

struct node;
class avl_tree;

class Bft_iterator {
private:
	struct Queue {
		struct QueueNode {
			//friend avl_tree;
			node* tree_node;
			QueueNode *next;

			QueueNode(node *p);
			~QueueNode();
		};
		//friend avl_tree;
		QueueNode *head;
		QueueNode *tail;

		Queue();
		~Queue();
		void push_back(node *node); //
		node* pop_front(); //
	};
public:
	
	node* current;
	Queue *tree_Queue = new Queue;

	Bft_iterator(avl_tree* tree);
	int next();
	bool has_next();
};