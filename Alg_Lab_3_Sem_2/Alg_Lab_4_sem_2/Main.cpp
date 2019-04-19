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
	avl_tree* tree_3 = merge(tree_1, tree_2);
	avl_tree* tree_4 = concat(tree_1, tree_2);
	avl_tree* tree_5 = mul(tree_2, 3);
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

	/*avl_tree* tree1 = create_rand_tree(4, 30);
	Queue *que1 = new Queue();
	tree1->get_sorted_que(que1);
	que1->print();

	avl_tree* res = concat(tree, tree1);
	Queue *que_res = new Queue();
	res->get_sorted_que(que_res);
	que_res->print();*/

	/*delete tree;*/

	//elem* a = new elem(3);
	/*elem* b = new elem(9, new elem(3));
	delete b;
	std::cout << b->next->key;*/

	/*avl_tree* tree = create_my_tree();
	tree->print();
	tree->remove(75);
	printf("\n\n\n");
	tree->print();
	delete tree;*/

	/*avl_tree*  tree_1 = create_rand_tree();
	avl_tree*  tree_2 = create_rand_tree();
	avl_tree*  tree_3 = create_rand_tree();
	avl_tree*  tree_4 = create_rand_tree();
	avl_tree*  tree_5 = create_rand_tree();
	avl_tree*  res = V30(tree_1, tree_2, tree_3, tree_4, tree_5);
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
	std::cout << "Result:\n";
	res->print();*/
	/*avl_tree* res = con(tree_1, tree_2);
	avl_tree* res = XOR(tree_1, tree_2);
	avl_tree* res = dis(tree_1, tree_2);*/
	//res->print();
	//avl_tree* tree;
	//for (auto i = 0; i < 10; i++) {
	//	tree = create_rand_tree(10, 100);
	//	/*avl_tree* tree = create_my_tree();*/
	//	tree->print();
	//	std::cout << std::endl;
	//	std::cout << std::endl;
	//	std::cout << std::endl;
	//	std::cout << std::endl;
	//	std::cout << std::endl;
	//}

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
	/*tree->insert(5);
	tree->insert(5);
	tree->insert(1);
	tree->insert(6);
	tree->insert(5);
	tree->insert(5);
	tree->insert(2);
	tree->insert(1);
	tree->insert(5);*/
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
