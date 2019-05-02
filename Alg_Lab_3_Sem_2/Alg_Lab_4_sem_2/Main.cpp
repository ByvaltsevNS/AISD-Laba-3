	#include <time.h>
	#include "AVL.h"

	const int MAXINT = 100;
	const int SIZE = 32;

	avl_tree* create_rand_tree(const int size = SIZE, const int max = MAXINT);
	avl_tree* V30(avl_tree* h1, avl_tree* h2, avl_tree* h3, avl_tree* h4, avl_tree* h5);
	avl_tree* create_my_tree();

	int main() {
		srand(time(NULL));
	
		avl_tree* tree_1 = create_rand_tree(10, 30);
		avl_tree* tree_2 = create_rand_tree(5, 20);
		std::cout << "A:\n";
		tree_1->print();
		std::cout << "........................................................................................" << std::endl;
		std::cout << "B:\n";
		tree_2->print();
		std::cout << "........................................................................................" << std::endl;
		try {
			avl_tree* tree_3 = merge(tree_1, tree_2);
			std::cout << "MERGE(A, B):\n";
			tree_3->print();
			std::cout << "........................................................................................" << std::endl;
			avl_tree* tree_4 = concat(tree_1, tree_2);
			std::cout << "CONCAT(A, B):\n";
			tree_4->print();
			std::cout << "........................................................................................" << std::endl;
			avl_tree* tree_5 = mul(tree_2, 3);
			std::cout << "MUL(B, 3):\n";
			tree_5->print();
			std::cout << "........................................................................................" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		/*avl_tree* tree_1 = create_rand_tree(5, 30);
		avl_tree* tree_2 = create_rand_tree(5, 30);
		avl_tree* tree_3 = create_rand_tree(5, 30);
		avl_tree* tree_4 = create_rand_tree(5, 30);
		avl_tree* tree_5 = create_rand_tree(5, 30);
		std::cout << "A:\n";
		tree_1->print();
		std::cout << "........................................................................................" << std::endl;
		std::cout << "B:\n";
		tree_2->print();
		std::cout << "........................................................................................" << std::endl;
		std::cout << "C:\n";
		tree_3->print();
		std::cout << "........................................................................................" << std::endl;
		std::cout << "D:\n";
		tree_4->print();
		std::cout << "........................................................................................" << std::endl;
		std::cout << "E:\n";
		tree_5->print();
		std::cout << "........................................................................................" << std::endl;
		try {
			avl_tree*  res = V30(tree_1, tree_2, tree_3, tree_4, tree_5);
			std::cout << "Result:\n";
			res->print();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}*/

		std::cin.get();
		return 0;
	}

	avl_tree* create_rand_tree(const int size, const int max) {
		avl_tree* tree = new avl_tree();
		int temp;
		for (auto i = 0; i < size; i++) {
			/*do {*/
				temp = rand() % max;
			/*} while (tree->find(temp));*/
			tree->insert(temp);
		}
		return tree;
	}

	avl_tree* V30(avl_tree* h1, avl_tree* h2, avl_tree* h3, avl_tree* h4, avl_tree* h5) {
		avl_tree* var1 = con(h2, h3);
		avl_tree* var2 = dis(h1, var1);
		avl_tree* var3 = dis(var2, h4);
		avl_tree* var4 = XOR(var3, h5);
		return var4;
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
