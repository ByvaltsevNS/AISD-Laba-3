#include <time.h>
#include "My_Set.h"
#include <Windows.h>
#include <winbase.h>
#include <fstream>
#include <chrono>

const int MAX = 1000;

void V30_sets();
void V30_seq();
void metering();

__int64 __cdecl get_tsc() {
	__asm {rdtsc};
};

double get_freq() {// frequency per second
	__int64 a, b;
	double c;
	do {
		a = get_tsc();
		Sleep(100);
		b = get_tsc();
		c = b - a;
	} while (c < 0);
	return c * 10;
}

int main() {
	srand(time(NULL));
	metering();

	system("pause");
	return 0;
}

void metering() {
	int max_size = 205, min_size = 5, step = 5, rep = 3;
	size_t middle_power = 0, set_count = 0;
	auto Used = [&](My_Set& t) { middle_power += t.get_power();
	++set_count; };
	std::ofstream file("in.txt");
	file << "123\n";
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
	double freq = get_freq();
	for (int size = min_size; size <= max_size; size += step) {
		for (int i = 0; i < rep; i++) {
			try {
				My_Set A('A', size);
				My_Set B('B', size);
				My_Set C('C', size);
				My_Set D('D', size);
				My_Set F('F', size);
				My_Set R('R');
				/*double freq = get_freq();*/
				double c;
					__int64 tsc_a = get_tsc();
					Used(A), Used(B);
					R = A & B;
					Used(R), Used(C);
					R = R | C;
					Used(R), Used(D);
					R = R / D;
					Used(R), Used(F);
					R = concat(R, F);
					__int64 tsc_b = get_tsc();
					c = tsc_b - tsc_a;
				file << middle_power / set_count << ' ' << c / freq << '\n';
			}
			catch (std::bad_alloc& ba) {
				std::cout << ba.what() << std::endl;
				std::cout << "(skipped!)\n";
			}
			middle_power = set_count = 0;
		}
	}
	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
	file.close();
}

void V30_sets() {
	std::cout << "\n..........................................";
	std::cout << "\nDemonstration of working with sets: ";
	My_Set A('A', 10, 30);
	A.print();
	My_Set B('B', 10, 30);
	B.print();
	My_Set R('R');
	R = A & B;
	std::cout << "\nIntersection of A and B: ";
	R.print();
	R = A | B;
	std::cout << "\nUnion of A and B: ";
	R.print();
	R = A / B;
	std::cout << "\nSymmetric difference of A and B: ";
	R.print();
	std::cout << "\n..........................................";
}

void V30_seq() {
	std::cout << "\n..........................................";
	std::cout << "\nDemonstration of working with sequences: ";
	My_Set A('A', 5, 30);
	A.print();
	My_Set B('B', 10, 30);
	B.print();
	My_Set R('R');
	R = merge(A, B);
	std::cout << "\nMerge (A, B): ";
	R.print();
	R = concat(A, B);
	std::cout << "\nConcat (A, B): ";
	R.print();
	R = mul(A, 3);
	std::cout << "\nMul (A, 3): ";
	R.print();
	std::cout << "\n..........................................";
}