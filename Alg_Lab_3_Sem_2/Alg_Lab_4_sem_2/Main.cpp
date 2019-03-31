#include <time.h>
#include "AVL.h"

const int MAXINT = 100;
const int SIZE = 32;

avl_tree* create_rand_tree(const int size = SIZE, const int max = MAXINT);

int main() {
	srand(time(NULL));

	avl_tree* tree = create_rand_tree(10, 100);
	tree->print();

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

