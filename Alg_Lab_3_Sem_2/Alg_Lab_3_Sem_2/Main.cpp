#include <iostream>
#include <time.h>
#include "Hash.h"

const int MAXINT = 100;
const int SIZE = 32;

using namespace std;

int* create_set(const int size = SIZE, const int max_val = MAXINT);//Создание множества заданной мощности

int main() {
	srand(time(NULL));

	/*const int hash_size = MAXINT * 2;*/
	int* arr = create_set();
	for (auto i = 0; i < SIZE; i++) {
		arr[i] = rand() % MAXINT;
	}
	cin.get();
	for (auto i = 0; i < SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (auto i = 0; i < SIZE; i++) {
		cout << hash_func(arr[i], SIZE) << " ";
	}
	/*int hash[SIZE * 2];
	for (auto i = 0; i < SIZE; i++) {
		hash[(60 * arr[i] + 5) % SIZE * 2] = arr[i];
	}
	for (auto i = 0; i < SIZE*2; i++) {
		cout << hash[i] << " ";
	}
*/
	delete[] arr;
	cin.get();
	return 0;
}

int* create_set(const int size, const int max_val) {
	int* arr = new int[size];
	for (auto i = 0; i < size; i++) {
		arr[i] = rand() % max_val;
	}
	return arr;
}