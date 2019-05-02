#include "Queue.h"

//Конструктор элемента очереди
Queue::QueueNode::QueueNode(node *p) {
	tree_node = p;
	next/* = prev*/ = nullptr;
}
//Деструктор элемента очереди
Queue::QueueNode::~QueueNode() {
	tree_node = nullptr;
	next/* = prev*/ = nullptr;
}
//Конструктор пустой очереди
Queue::Queue() {
	tail = head = nullptr;
}
//Конструктор очереди
Queue::Queue(node* p) {
	tail = head = new QueueNode(p);
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
	if (!head)
		return nullptr;
	node* res = head->tree_node;
	QueueNode* del = head;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	delete del;
	return res;
}
//Удаление элемента с заданного места в очереди
void Queue::remove(node* a) {
	QueueNode* p = head;
	for (; p->next && p->next->tree_node != a; p = p->next);
	if (p->next) {
		QueueNode* del = p->next;
		p->next = del->next;
		delete del;
		p = nullptr;
	}
}
//Вывод очереди в консоль
void Queue::print() {
	QueueNode* temp = head;
	for (; temp; temp = temp->next) {
		std::cout << '[' << temp->tree_node->key << ']' << ' ';
	}
	std::cout << std::endl;
}
