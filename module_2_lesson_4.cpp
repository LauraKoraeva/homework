//Урок 4. Алгоритмы на массивах

//Задача 2

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = { 2, 7, 11, 15 };
	int result = 9;

	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[i] + vec[j] == result)
				std::cout << vec[i] << " + " << vec[j] << " = " << result;
		}
	}
	
	return 0;
}










//Задача 3

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;
	std::cout << "Enter numbers: ";
	
	int number;
	std::cin >> number;

	while (number != -2)
	{
		if (number != -1)
		{
			vec.push_back(number);
		}
		else
		{
			for (int i = 0; i < vec.size(); ++i)
			{
				for (int j = i + 1; j < vec.size(); ++j)
				{
					if (vec[j] < vec[i])
					{
						std::swap(vec[i], vec[j]);
					}
				}
			}

			std::cout << "The fifth element: " << vec[4] << '\n';
		}

		std::cin >> number;
	}

	return 0;
}










//Задача 4

#include <iostream>
#include <vector>

int main() 
{
	std::vector<int> a = { -100,-50, -5, 1, 10, 15 };

	for (int i = 0; i < a.size(); ++i) 
	{
		for (int j = 0; j < a.size() - i - 1; ++j) 
		{
			int abs_1 = abs(a[j]);
			int abs_2 = abs(a[j + 1]);

			if (abs_1 > abs_2) 
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}

	for (int i = 0; i < a.size(); ++i) 
	{
		std::cout << a[i] << " ";
	}

	return 0;
}