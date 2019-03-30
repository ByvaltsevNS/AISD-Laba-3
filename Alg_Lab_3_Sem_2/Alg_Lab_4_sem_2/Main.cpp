#include "AVL.h"

int main() {
	avl_tree tree(5);
	std::cout << tree.head->key;
	std::cin.get();
	return 0;
}