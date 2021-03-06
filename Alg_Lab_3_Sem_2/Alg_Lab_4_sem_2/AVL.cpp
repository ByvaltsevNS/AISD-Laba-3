#include "AVL.h"

avl_tree::avl_tree() : head(0) { seque = new Queue; }

avl_tree::avl_tree(int key) : head(new node(key)) { seque = new Queue(head); }

avl_tree::avl_tree(avl_tree* tree) {
	if (!tree) {
		throw std::exception("Error in copy constructor: argument = nullptr");
	}
	Queue::QueueNode* temp = tree->seque->get_head();
	seque = new Queue();
	for (Queue::QueueNode* temp = tree->seque->get_head(); temp; temp = temp->next) {
		this->insert(temp->tree_node->key);
	}
}

avl_tree::~avl_tree() {
	while (seque->get_head())
		delete seque->pop_front();
	delete seque;
}

void avl_tree::print() {
	print(head, 0);
	std::cout << "....................................." << std::endl;
	seque->print();
}

void avl_tree::print(node* head, int level)
{
	if (head)
	{
		print(head->right, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << "     ";
		std::cout << head->key << "<" << std::endl;
		print(head->left, level + 1);
	}
}

int node::b_factor()
{
	if (left && right)
		return right->height - left->height;
	if (!left) {
		if (right)
			return right->height;
		else
			return 0;
	}
	if (!right) {
		if (left)
			return -left->height;
		else
			return 0;
	}
}

void node::fix_height()
{
	if (left && right)
		height = (left->height > right->height ? left->height : right->height) + 1;
	else if (!left) {
		if (right)
			height = right->height + 1;
		else
			height = 1;
	}
	else if (!right) {
		if (left)
			height = left->height + 1;
		else
			height = 1;
	}
}

node* rotate_right(node* p) // ������ ������� ������ p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	p->fix_height();
	q->fix_height();
	return q;
}

node* rotate_left(node* q) // ����� ������� ������ q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	q->fix_height();
	p->fix_height();
	return p;
}

node* balance(node* p) // ������������ ���� p
{
	p->fix_height();
	if (p->b_factor() >= 2)
	{
		if (p->right->b_factor() < 0)
			p->right = rotate_right(p->right);
		return rotate_left(p);
	}
	if (p->b_factor() <= -2)
	{
		if (p->left->b_factor() > 0)
			p->left = rotate_left(p->left);
		return rotate_right(p);
	}
	return p; // ������������ �� �����
}

node* avl_tree::find(node* head, int key) {
	if (head == nullptr)
		return nullptr;
	if (head->key == key)
		return head;
	if (key < head->key) {
		if (node* p = find(head->left, key))
			return p;
	}
	else if (node* p = find(head->right, key))
		return p;
	else
		return nullptr;
}

node* avl_tree::find(int key) // ������� ����� k � ������ � ������ p
{
	return find(head, key);
}

node* avl_tree::insert(node* p, int key) // ������� ����� k � ������ � ������ p
{
	if (!p) {
		node* new_node = new node(key);
		seque->push_back(new_node);
		return new_node;
	}
	if (key < p->key)
		p->left = insert(p->left, key);
	else
		p->right = insert(p->right, key);
	return balance(p);
}

void avl_tree::insert(int key) {
	head = insert(head, key);
}

node* find_min(node* p) // ����� ���� � ����������� ������ � ������ p 
{
	return p->left ? find_min(p->left) : p;
}

node* remove_min(node* p) // �������� ���� � ����������� ������ �� ������ p
{
	if (p->left == 0)
		return p->right;
	p->left = remove_min(p->left);
	return balance(p);
}

node* avl_tree::remove(node* p, int key) // �������� ����� k �� ������ p
{
	if (!p)
		return nullptr;
	if (key < p->key)
		p->left = remove(p->left, key);
	else if (key > p->key)
		p->right = remove(p->right, key);
	else 
	{
		node* q = p->left;
		node* r = p->right;
		seque->remove(p);
		delete p;
		if (!r)
			return q;
		node* min = find_min(r);
		min->right = remove_min(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void avl_tree::remove(int key) {
	if (node* p = find(key))
		head = remove(head, key);
}

avl_tree* dis(avl_tree* t1, avl_tree* t2) {
	if (!t1 || !t2) {
		throw std::exception("Error in dis: one of the arguments = nullptr");
	}
	avl_tree* res = nullptr;
	if (!t1->head || t2->head && t1->head->height < t2->head->height) {
		res = new avl_tree(t2);
		for (Queue::QueueNode* temp = t1->seque->get_head(); temp; temp = temp->next) {
			if (!res->find(temp->tree_node->key))
				res->insert(temp->tree_node->key);
		}
	}
	else {
		res = new avl_tree(t1);
		for (Queue::QueueNode* temp = t2->seque->get_head(); temp; temp = temp->next) {
			if (!res->find(temp->tree_node->key))
				res->insert(temp->tree_node->key);
		}
	}
	return res;
}

avl_tree* con(avl_tree* t1, avl_tree* t2) {
	if (!t1 || !t2) {
		throw std::exception("Error in con: one of the arguments = nullptr");
	}
	avl_tree* res = new avl_tree();
	if (!t1->head || t2->head && t1->head->height < t2->head->height) {
		for (Queue::QueueNode* temp = t1->seque->get_head(); temp; temp = temp->next) {
			if (t2->find(temp->tree_node->key))
				res->insert(temp->tree_node->key);
		}
	}
	else {
		for (Queue::QueueNode* temp = t2->seque->get_head(); temp; temp = temp->next) {
			if (t1->find(temp->tree_node->key))
				res->insert(temp->tree_node->key);
		}
	}
	return res;
}

avl_tree* XOR(avl_tree* t1, avl_tree* t2) {
	if (!t1 || !t2) {
		throw std::exception("Error in XOR: one of the arguments = nullptr");
	}
	avl_tree* res;
	if (!t1->head || t2->head && t1->head->height < t2->head->height) {
		res = new avl_tree(t2);
		for (Queue::QueueNode* temp = t1->seque->get_head(); temp; temp = temp->next) {
			if (!res->find(temp->tree_node->key))
				res->insert(temp->tree_node->key);
			else
				res->remove(temp->tree_node->key);
		}
	}
	else {
		res = new avl_tree(t1);
		for (Queue::QueueNode* temp = t2->seque->get_head(); temp; temp = temp->next) {
			if (!res->find(temp->tree_node->key))
				res->insert(temp->tree_node->key);
			else
				res->remove(temp->tree_node->key);
		}
	}
	return res;
}

void get_sorted_que(node* head, Queue* que) {
	if (head) { //���� �� ���������� ������ ����
		get_sorted_que(head->left, que);
		que->push_back(head);
		get_sorted_que(head->right, que);
	}
}

void avl_tree::get_sorted_que(Queue* que) {
	::get_sorted_que(head, que);
}

avl_tree* merge(avl_tree* t1, avl_tree* t2) {
	try {
		avl_tree* res = concat(t1, t2);
		Queue* var = new Queue();
		res->get_sorted_que(var);
		delete res->seque;
		res->seque = var;
		return res;
	}
	catch (std::exception& e) {
		throw;
	}
}

avl_tree* concat(avl_tree* t1, avl_tree* t2) {
	if (!t1 || !t2) {
		throw std::exception("Error in concat: one of the arguments = nullptr");
	}
	avl_tree* res = new avl_tree(t1);
	Queue::QueueNode* temp = t2->seque->get_head();
	for (; temp; temp = temp->next) {
		res->insert(temp->tree_node->key);
	}
	return res;
}

avl_tree* mul(avl_tree* tree, int n) {
	if (!tree|| n < 1) {
		throw std::exception("Error in mul: Tree = nullptr or n < 1");
	}
	avl_tree* res = new avl_tree();
	for (int i = 0; i < n; i++) {
		for (Queue::QueueNode* p = tree->seque->get_head(); p; p = p->next)
			res->insert(p->tree_node->key);
	}
	return res;
}

