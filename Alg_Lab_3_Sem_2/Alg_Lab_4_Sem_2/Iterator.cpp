#include "iterator.h"

//Конструктор элемента очереди
Queue::QueueNode::QueueNode(node *p) {
	tree_node = p;
	next = nullptr;
}
//Деструктор элемента очереди
Queue::QueueNode::~QueueNode() {
	tree_node = nullptr;
	next = nullptr;
}
//Конструктор пустой очереди
Queue::Queue() {
	tail = head = nullptr;
}
//Деструктор очереди
Queue::~Queue() {
	while (tail) {
		this->pop_front();
	}
}
//Добавление элемента в конец очереди
void Queue::push_back(node *p) {
	if (head == nullptr)
		head = tail = new QueueNode(p);
	else {
		tail->next = new QueueNode(p);
		tail = tail->next;
	}
}
//Удаление элемента с начала очереди
node* Queue::pop_front() {
	node* res = head->tree_node;
	QueueNode* del = head;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	delete del;
	return res;
}

Bft_iterator::Bft_iterator(avl_tree* tree)
{
	current = tree->head;
	tree_Queue->push_back(current);
}

bool Bft_iterator::has_next()
{
	return (current != nullptr);
}

int Bft_iterator::next()
{
	if (!has_next()) { //
		throw ("The next element does not exist!");
	}
	int key = current->key; //Получение ключа текущего узла
	if (current->left)
		tree_Queue->push_back(current->left); //Добавление в очередь левого потомка текущего узла
	if (current->right)
		tree_Queue->push_back(current->right); //Добавление в очередь правого потомка текущего узла
	if (tree_Queue->head->next)
		current = tree_Queue->head->next->tree_node; //Переход к следующему элементу в очереди
	else
		current = nullptr;
	tree_Queue->pop_front(); //Удаление элемента из очереди
	return key;
}
