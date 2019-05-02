#pragma once
#include "AVL.h"

struct node;
class avl_tree;
class Queue;

class Bft_iterator {
public:
	node* current;
	Queue* tree_Queue;

	Bft_iterator(avl_tree* tree);
	int next();
	bool has_next();
};