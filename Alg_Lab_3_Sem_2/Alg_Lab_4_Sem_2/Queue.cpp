#include "Queue.h"

//����������� �������� �������
Queue::QueueNode::QueueNode(node *p) {
	tree_node = p;
	next = prev = nullptr;
}
//���������� �������� �������
Queue::QueueNode::~QueueNode() {
	tree_node = nullptr;
	next = prev = nullptr;
}
//����������� ������ �������
Queue::Queue() {
	tail = head = nullptr;
}
//���������� �������
Queue::~Queue() {
	while (tail) {
		this->pop_front();
	}
}
//���������� �������� � ����� �������
void Queue::push_back(node *p) {
	if (head == nullptr)
		head = tail = new QueueNode(p);
	else {
		tail->next = new QueueNode(p);
		tail->next->prev = tail;
		tail = tail->next;
	}
}
//�������� �������� � ������ �������
node* Queue::pop_front() {
	node* res = head->tree_node;
	QueueNode* del = head;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	else
		head->prev = nullptr;

	delete del;
	return res;
}

node* Queue::remove(node* a) {
	QueueNode* p = head;
	for (; p && p->tree_node != a; p = p->next);
	if (!p)
		return nullptr;

	QueueNode* del = p;
	p->next = del->next;
	del->next->prev = p;
	return del->tree_node;
}
//����� ������� � �������
void Queue::print() {
	QueueNode* temp = head;
	for (; temp; temp = temp->next) {
		std::cout << '[' << temp->tree_node->key << ']' << ' ';
	}
	std::cout << std::endl;
}
