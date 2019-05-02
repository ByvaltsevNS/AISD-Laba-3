#include "Queue.h"

//����������� �������� �������
Queue::QueueNode::QueueNode(node *p) {
	tree_node = p;
	next/* = prev*/ = nullptr;
}
//���������� �������� �������
Queue::QueueNode::~QueueNode() {
	tree_node = nullptr;
	next/* = prev*/ = nullptr;
}
//����������� ������ �������
Queue::Queue() {
	tail = head = nullptr;
}
//����������� �������
Queue::Queue(node* p) {
	tail = head = new QueueNode(p);
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
		tail = tail->next;
	}
}
//�������� �������� � ������ �������
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
//�������� �������� � ��������� ����� � �������
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
//����� ������� � �������
void Queue::print() {
	QueueNode* temp = head;
	for (; temp; temp = temp->next) {
		std::cout << '[' << temp->tree_node->key << ']' << ' ';
	}
	std::cout << std::endl;
}
