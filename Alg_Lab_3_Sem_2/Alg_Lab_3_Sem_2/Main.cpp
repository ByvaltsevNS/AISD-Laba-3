#include <time.h>
#include "Hash.h"

const int MAXINT = 100;
const int SIZE = 32;

hash_table* create_set(const int size = SIZE, const int max_val = MAXINT); //The creation of many of the given power
hash_table* V30(const hash_table &h1, const hash_table &h2, const hash_table &h3, const hash_table &h4, const hash_table &h5); //Our function

int main() {
	srand(time(NULL));

	/*const int size = 16;
	int arr[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	hash_table* tab = new hash_table(arr, size, 5);
	tab->print();
	tab->remove(0);
	tab->print();*/

	/*hash_elem* el_1 = new hash_elem(1);
	hash_elem* el_2 = new hash_elem(2, el_1);
	hash_elem* el_3 = new hash_elem(3, el_2);
	delete el_3;
	std::cout << el_1->val;*/

	hash_table* tab_1 = create_set();
	tab_1->print();
	hash_table* tab_2 = create_set();
	tab_2->print();
	hash_table* tab_3 = create_set();
	tab_3->print();
	hash_table* tab_4 = create_set();
	tab_4->print();
	hash_table* tab_5 = create_set();
	tab_5->print();
	hash_table* res = V30(*tab_1, *tab_2, *tab_3, *tab_4, *tab_5);
	res->print();
	
	std::cin.get();
	return 0;
}

hash_table* create_set(const int size, const int max_val) {
	hash_table* table = new hash_table(size);
	int temp;
	for (auto i = 0; i < size; i++) {
		do {
			temp = rand() % max_val;
		} while (table->find(temp));
		table->add(temp);
	}
	return table;
}

hash_table* V30(const hash_table &h1, const hash_table &h2, const hash_table &h3, const hash_table &h4, const hash_table &h5) {
	hash_table* var1 = con(h2, h3);
	hash_table* var2 = dis(h1, *var1);
	hash_table* var3 = dis(*var2, h4);
	hash_table* var4 = dis(*var3, h5);
	return var4;
}