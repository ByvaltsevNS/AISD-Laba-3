#include "AVL.h"

void avl_tree::print() {
	print_tree(head, 0);
}

void print_tree(node* head, int level)
{
	if (head)
	{
		print_tree(head->right, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << "     ";
		std::cout << head->key << "<" << std::endl;
		print_tree(head->left, level + 1);
	}
}

int node::bfactor()
{
	return right->height - left->height;
}

void node::fixheight()
{
	height = (left->height > right->height ? left->height : right->height) + 1;
}

node* rotate_right(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	p->fixheight();
	q->fixheight();
	return q;
}

node* rotate_left(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	q->fixheight();
	p->fixheight();
	return p;
}

node* balance(node* p) // балансировка узла p
{
	p->fixheight();
	if (p->bfactor() == 2)
	{
		if (p->right->bfactor() < 0)
			p->right = rotate_right(p->right);
		return rotate_left(p);
	}
	if (p->bfactor() == -2)
	{
		if (p->left->bfactor() > 0)

			p->left = rotate_left(p->left);
		return rotate_right(p);
	}
	return p; // балансировка не нужна
}


bool contain(node* head, int key) {
	if (head->key == key)
		return true;
	if (contain(head->left, key))
		return true;
	else if (contain(head->right, key))
		return true;
	else
		return false;
}

bool avl_tree::find(int key) // вставка ключа k в дерево с корнем p
{
	contain(head, key);
}


