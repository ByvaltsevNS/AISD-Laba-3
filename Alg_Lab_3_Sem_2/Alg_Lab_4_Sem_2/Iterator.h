#pragma once
#include "AVL.h"
//#include "Queue.h"

struct node;
class avl_tree;
//struct Queue;
class Queue;

class Bft_iterator {
public:
	node* current;
	Queue* tree_Queue;

	Bft_iterator(avl_tree* tree);
	int next();
	bool has_next();
};