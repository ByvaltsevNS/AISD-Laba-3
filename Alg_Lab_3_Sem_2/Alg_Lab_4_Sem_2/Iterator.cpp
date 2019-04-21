#include "iterator.h"

Bft_iterator::Bft_iterator(avl_tree* tree)
{
	current = tree->head;
	tree_Queue = new Queue(tree->head);
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
