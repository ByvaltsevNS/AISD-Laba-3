#include <time.h>
#include "AVL.h"

const int MAXINT = 100;
const int SIZE = 32;

avl_tree* create_rand_tree(const int size = SIZE, const int max = MAXINT);
avl_tree* create_my_tree();

int main() {
	srand(time(NULL));

	avl_tree* tree;
	for (auto i = 0; i < 10; i++) {
		tree = create_rand_tree(10, 100);
		/*avl_tree* tree = create_my_tree();*/
		tree->print();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cin.get();
	return 0;
}

avl_tree* create_rand_tree(const int size, const int max) {
	avl_tree* tree = new avl_tree();
	int temp;
	for (auto i = 0; i < size; i++) {
		do {
			temp = rand() % max;
		} while (tree->find(temp));
		tree->insert(temp);
	}
	return tree;
}

avl_tree* create_my_tree() {
	avl_tree* tree = new avl_tree();
	tree->insert(75);
	tree->insert(66);
	tree->insert(98);
	tree->insert(57);
	tree->insert(80);
	tree->insert(43);
	tree->insert(97);
	tree->insert(54);
	tree->insert(17);
	tree->insert(45);
	return tree;
}
