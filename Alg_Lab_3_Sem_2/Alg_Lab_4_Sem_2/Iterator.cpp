#include "iterator.h"

//����������� �������� �������
Queue::QueueNode::QueueNode(node *p) {
	tree_node = p;
	next = nullptr;
}
//���������� �������� �������
Queue::QueueNode::~QueueNode() {
	tree_node = nullptr;
	next = nullptr;
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
	int key = current->key; //��������� ����� �������� ����
	if (current->left)
		tree_Queue->push_back(current->left); //���������� � ������� ������ ������� �������� ����
	if (current->right)
		tree_Queue->push_back(current->right); //���������� � ������� ������� ������� �������� ����
	if (tree_Queue->head->next)
		current = tree_Queue->head->next->tree_node; //������� � ���������� �������� � �������
	else
		current = nullptr;
	tree_Queue->pop_front(); //�������� �������� �� �������
	return key;
}
