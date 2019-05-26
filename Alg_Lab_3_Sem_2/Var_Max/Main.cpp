#include <iostream>

#include <time.h>

#include <stdlib.h>

#include <vector>

#include <algorithm>

#include <set>

#include <fstream>

#include <iterator>

using namespace std;

class my_sequence

{

public:

	set<int> data;

	vector<int> numbers;

	//int amount = 0;

	void insert(int el)

	{

		data.insert(el);

		numbers.push_back(el);

	}

	void remove(int el)

	{

		data.erase(el);

		while (count(numbers.begin(), numbers.end(), el) > 0)

		{

			auto i = find(numbers.begin(), numbers.end(), el);

			numbers.erase(i);

		}

	}

	void minus(my_sequence c) // удаляет целиком

	{

		set<int> ans;

		set<int>::iterator out_itr(ans.begin());

		set_difference(data.begin(), data.end(), c.data.begin(), c.data.end(), inserter(ans, out_itr), data.value_comp());

		numbers.empty();

		for (auto i = data.begin(); i != data.end(); i++)

			numbers.push_back(*i);

	}

	void x_or(my_sequence c)

	{

		set<int> ans;

		set<int>::iterator out_itr(ans.begin());

		set_symmetric_difference(data.begin(), data.end(), c.data.begin(), c.data.end(), inserter(ans, out_itr), data.value_comp());

		numbers.empty();

		for (auto i = data.begin(); i != data.end(); i++)

			numbers.push_back(*i);

	}

	void print()

	{

		cout << "in set: ";

		for (auto i = data.begin(); i != data.end(); i++)

		{

			cout << *i << " ";

		}

		cout << endl;

		cout << "in sec: ";

		for (auto i = numbers.begin(); i != numbers.end(); i++)

		{

			cout << *i << " ";

		}

		cout << endl;

	}

	void erase(int p1, int p2)

	{

		vector<int> new_numbers;

		for (int i = p1; i < p2; i++)

		{

			new_numbers.push_back(*(numbers.begin() + p1));

			numbers.erase(numbers.begin() + p1);

		}

		for (int i = 0; i < new_numbers.size(); i++)

		{

			if (count(numbers.begin(), numbers.end(), new_numbers[i]) == 0)

				data.erase(new_numbers[i]);

		}

	}

	void excl(my_sequence c)

	{

		auto i = search(numbers.begin(), numbers.end(), c.numbers.begin(), c.numbers.end());

		if (i == numbers.end())

			return;

		numbers.erase(i, i + c.numbers.size());

		for (int i = 0; i < c.numbers.size(); i++)

		{

			if (count(numbers.begin(), numbers.end(), c.numbers[i]) == 0)

				data.erase(c.numbers[i]);

		}

	}

	void change(my_sequence c, int p)

	{

		int temp_size = numbers.size();

		vector<int> new_numbers;

		for (int i = 0; i < p; i++)

			new_numbers.push_back(numbers[i]);

		for (int i = 0; i < c.numbers.size(); i++)

		{

			if (i + p < temp_size)

			{

				if (count(new_numbers.begin(), new_numbers.end(), numbers[i + p]) == 0)

					data.erase(numbers[i + p]);

				numbers[i + p] = c.numbers[i];

			}

			else

				numbers.push_back(c.numbers[i]);

		}

		for (int i = 0; i < c.numbers.size(); i++)

		{

			data.insert(c.numbers[i]);

		}

	}

};

int main()

{

	srand(time(0));

	//std::string s = "out.txt";

	fstream f("in.txt", ios::out);

	f << "190" << endl;

	for (int i = 10; i < 200; i++)

	{

		my_sequence m1, m2, m4, m5, m3;

		for (int j = 0; j < 200; j++)

			m1.insert(rand() % i);

		for (int j = 0; j < 200; j++)

			m2.insert(rand() % i);

		for (int j = 0; j < 200; j++)

			m3.insert(rand() % i);

		for (int j = 0; j < 200; j++)

			m4.insert(rand() % i);

		for (int j = 0; j < 200; j++)

			m5.insert(rand() % i);

		//-------------------

		unsigned t1 = clock();

		m3.x_or(m4);

		m1.minus(m2);

		m1.minus(m3);

		m1.minus(m5);

		unsigned t2 = clock();

		unsigned t_d = t2 - t1;

		f << i << " " << t_d << endl;

	}

	f.close();

}