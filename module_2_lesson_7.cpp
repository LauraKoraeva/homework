//Урок 7. Расширенная работа с функциями

//Задача 1

#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int* array, int arrayLength)
{
	if (vec.size() == arrayLength)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			std::swap(vec[i], *(array + i));
		}
	}
}

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	int array[] = { 6, 7, 8, 9, 10 };
	int arrayLength = sizeof(array) / sizeof(array[0]);
	
	swapvec(vec, array, arrayLength);

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	
	std::cout << std::endl;
	
	for (int i = 0; i < arrayLength; ++i)
	{
		std::cout << array[i] << " ";
	}

	return 0;
}










//Задача 2

#include <iostream>

void countWays(int place, int &count, int stairs, int pace = 2)
{
	if ((place < 0) || (place > stairs))
		return;
	
	if (place == stairs)
		count = count + 1;

	for (int i = 1; i <= pace; i++)
		countWays(place + i, count, stairs, pace = 2);
}

int main()
{
	std::cout << "How many stairs does the rabbit have to climb? ";
	int stairs;
	std::cin >> stairs;

	int count = 0;
	int place = 0;
	countWays(place, count, stairs);

	std::cout << "The rabbit has " << count << " ways to climb " << stairs << " stairs.";

	return 0;
}










//Задача 3

#include <iostream>

void evenDigits(long long number, int& ans)
{
	if (number == 0)
		return;

	int digit = number % 10;

	if (digit % 2 == 0)
		++ans;

	number /= 10;

	evenDigits(number, ans);
}

int main()
{
	std::cout << "Enter a number: ";
	long long number;
	std::cin >> number;

	int ans = 0;

	evenDigits(number, ans);

	std::cout << "Even digits: " << ans;

	return 0;
}