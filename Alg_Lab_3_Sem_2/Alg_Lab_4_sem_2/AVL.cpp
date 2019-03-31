#include "AVL.h"

//avl_tree::avl_tree(avl_tree &tree) {
//	Dft_iterator it(&tree);
//	while (it.has_next())
//		this->insert(it.next());
//}

void avl_tree::print() {
	print(head, 0);
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
			height = 0;
	}
	else if (!right) {
		if (left)
			height = left->height + 1;
		else
			height = 0;
	}
}

node* rotate_right(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	p->fix_height();
	q->fix_height();
	return q;
}

node* rotate_left(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	q->fix_height();
	p->fix_height();
	return p;
}

node* balance(node* p) // балансировка узла p
{
	p->fix_height();
	if (p->b_factor() == 2)
	{
		if (p->right->b_factor() < 0)
			p->right = rotate_right(p->right);
		return rotate_left(p);
	}
	if (p->b_factor() == -2)
	{
		if (p->left->b_factor() > 0)
			p->left = rotate_left(p->left);
		return rotate_right(p);
	}
	return p; // балансировка не нужна
}

bool avl_tree::find(node* head, int key) {
	if (head == nullptr)
		return false;
	if (head->key == key)
		return true;
	if (find(head->left, key))
		return true;
	else if (find(head->right, key))
		return true;
	else
		return false;
}

bool avl_tree::find(int key) // вставка ключа k в дерево с корнем p
{
	return find(head, key);
}

node* avl_tree::insert(node* p, int key) // вставка ключа k в дерево с корнем p
{
	if (!p)
		return new node(key);
	if (key < p->key)
		p->left = insert(p->left, key);
	else
		p->right = insert(p->right, key);
	return balance(p);
}

void avl_tree::insert(int key) {
	head = insert(head, key);
}

node* find_min(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? find_min(p->left): p;
}

node* remove_min(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = remove_min(p->left);
	return balance(p);
}

node* avl_tree::remove(node* p, int key) // удаление ключа k из дерева p
{
	if (!p)
		return nullptr;
	if (key < p->key)
		p->left = remove(p->left, key);
	else if (key > p->key)
		p->right = remove(p->right, key);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
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
	head = remove(head, key);
}