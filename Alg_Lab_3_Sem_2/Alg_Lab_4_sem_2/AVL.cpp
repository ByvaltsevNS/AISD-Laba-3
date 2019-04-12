#include "AVL.h"

//avl_tree::avl_tree(avl_tree &tree) {
//	Dft_iterator it(&tree);
//	while (it.has_next())
//		this->insert(it.next());
//}

avl_tree::avl_tree(avl_tree* tree) {
	Bft_iterator it(tree);
	while (it.has_next())
		insert(it.next());
}

avl_tree::~avl_tree() {
	Bft_iterator it(this);
	while (it.has_next()) {
		node* p = it.current;
		it.next();
		delete p;
	}
}

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
		std::cout << head->key << " " << head->number << "<" << std::endl;
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

node* avl_tree::find(node* head, int key) {
	if (head == nullptr)
		return nullptr;
	if (head->key == key)
		return head;
	if (node* p = find(head->left, key))
		return p;
	else if (node* p = find(head->right, key))
		return p;
	else
		return nullptr;
}

node* avl_tree::find(int key) // вставка ключа k в дерево с корнем p
{
	return find(head, key);
}

node* avl_tree::insert(node* p, int key) // вставка ключа k в дерево с корнем p
{
	if (!p) 
		return new node(key, size++);
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
	if (node* p = find(key)) {
		int num = p->number;
		head = remove(head, key);
		Bft_iterator it(this);
		while (it.has_next()) {
			if (it.current->number > num)
				it.current->number--;
			it.next();
		}
	}
}

//void rec_dis_order(node* head_1, avl_tree* tree_2, avl_tree* res) {
//	if (!tree_2->find(head_1->key))
//		res->insert(head_1->key);
//	//////////////////////////
//	if (head_1->left != nullptr)
//		rec_dis_order(head_1->left, tree_2, res);
//	if (head_1->right != nullptr) 
//		rec_dis_order(head_1->right, tree_2, res);
//}
//
//avl_tree* dis(avl_tree* tree_1, avl_tree* tree_2) {
//	avl_tree* res = new avl_tree(tree_1);
//	rec_dis_order(tree_1)
//	return res;
//}

avl_tree* dis(avl_tree* t1, avl_tree* t2) {
	avl_tree* res;
	Bft_iterator* it;
	if (t1->height < t2->height) {
		res = new avl_tree(t2);
		it = new Bft_iterator(t1);
		while (it->has_next()) {
			int key = it->next();
			if (!res->find(key))
				res->insert(key);
		}
	}
	else {
		res = new avl_tree(t1);
		it = new Bft_iterator(t2);
		while (it->has_next()) {
			int key = it->next();
			if (!res->find(key))
				res->insert(key);
		}
	}
	return res;
}

avl_tree* con(avl_tree* t1, avl_tree* t2) {
	avl_tree* res = new avl_tree();
	Bft_iterator* it;
	if (t1->height < t2->height) {
		it = new Bft_iterator(t1);
		while (it->has_next()) {
			int key = it->next();
			if (t2->find(key))
				res->insert(key);
		}
	}
	else {
		it = new Bft_iterator(t2);
		while (it->has_next()) {
			int key = it->next();
			if (t1->find(key))
				res->insert(key);
		}
	}
	return res;
}

avl_tree* XOR(avl_tree* t1, avl_tree* t2) {
	avl_tree* res;
	Bft_iterator* it;
	if (t1->height < t2->height) {
		res = new avl_tree(t2);
		it = new Bft_iterator(t1);
		while (it->has_next()) {
			int key = it->next();
			if (!res->find(key))
				res->insert(key);
			else
				res->remove(key);
		}
	}
	else {
		res = new avl_tree(t1);
		it = new Bft_iterator(t2);
		while (it->has_next()) {
			int key = it->next();
			if (!res->find(key))
				res->insert(key);
			else
				res->remove(key);
		}
	}
	return res;
}

////////////////////////////////////////////////////

node* avl_tree::find_num(int num){
	Bft_iterator it(this);
	while (it.has_next()) {
		if (it.current->number == num)
			return it.current;
	}
	return nullptr;

}

avl_tree* get_sorted_que(node& head, Queue* que) {
	if (head) { //Пока не встретится пустой узел
		get_sorted_que(head->left, tree_node_queue);  //Рекурсивная функция вывода левого поддерева
		tree_node_queue->push_back(head); //Запись элемента в массив
		get_sorted_que(head->right, tree_node_queue); //Рекурсивная функция вывода правого поддерева
	}
}

avl_tree* merge(avl_tree& t1, avl_tree& t2) {

}