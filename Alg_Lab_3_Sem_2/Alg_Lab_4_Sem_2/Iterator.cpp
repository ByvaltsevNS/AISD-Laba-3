#include "Iterator.h"

//Dft_iterator::Dft_iterator(avl_tree* tree)
//{
//	if (tree->head == nullptr)
//	{
//		throw "Tree is empty";
//	}
//	else
//	{
//		current = tree->head; // ������ � ������ ������ �������� ������ ��� ������ ��������� ������ � �������
//		while ((current->left != nullptr) || (current->right != nullptr))
//		{
//			if (current->left == nullptr)
//			{
//				current = current->right;
//			}
//			else
//				current = current->left;
//		}
//	}
//}
//
//bool Dft_iterator::has_next()
//{
//	return (current != nullptr);
//}
//
//int Dft_iterator::next()
//{
//	int key = current->key;
//	if (current->up) // ���� ���� ���� ����
//	{
//		if ((current->up->right != nullptr) && (current->up->right != current)) //���� ����� ������ �� ������ �����, �� ��������
//		{
//			current = current->up->right;
//			while ((current->left != nullptr) || (current->right != nullptr)) // ��� � ����� ������ ������� ����� (�� ����������� �����)
//			{
//				if (current->left == nullptr)
//				{
//					current = current->right;
//				}
//				else
//					current = current->left;
//			}
//		}
//		else // ���� ������ ����� ���, ����������� �����
//			current = current->up;
//	}
//	else
//		current = nullptr;
//	return key; //���������� ���� ��������
//}
