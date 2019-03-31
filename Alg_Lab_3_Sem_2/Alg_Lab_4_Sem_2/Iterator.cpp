#include "Iterator.h"

//Dft_iterator::Dft_iterator(avl_tree* tree)
//{
//	if (tree->head == nullptr)
//	{
//		throw "Tree is empty";
//	}
//	else
//	{
//		current = tree->head; // проход к самому левому элементу дерева для начала обратного обхода в глубину
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
//	if (current->up) // если есть куда идти
//	{
//		if ((current->up->right != nullptr) && (current->up->right != current)) //если можно пройти на правую ветку, то проходим
//		{
//			current = current->up->right;
//			while ((current->left != nullptr) || (current->right != nullptr)) // идём в самый нижний элемент ветки (по возможности левый)
//			{
//				if (current->left == nullptr)
//				{
//					current = current->right;
//				}
//				else
//					current = current->left;
//			}
//		}
//		else // если справа веток нет, поднимаемся вверх
//			current = current->up;
//	}
//	else
//		current = nullptr;
//	return key; //возвращаем ключ элемента
//}
