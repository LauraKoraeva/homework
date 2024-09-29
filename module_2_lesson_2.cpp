//Урок 2. Знакомство с std::vector v2

//1. Введение в тип vector

//Задание 1

#include <iostream>
#include <vector>

int main()
{
	std::cout << "How many elements do you want: ";
	int length;
	std::cin >> length;

	std::cout << "Enter " << length << " numbers to find their arithmetic mean.\n";
	std::vector<int> vector(length);
	for (int i = 0; i < length; ++i)
	{
		std::cin >> vector[i];
	}

	int sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum += vector[i];
	}

	float mean = (float)sum / length;
	std::cout << "Mean = " << mean << '\n';

	return 0;
}










//Задание 2

#include <iostream>
#include <vector>

int main()
{
	std::cout << "How many elements do you want: ";
	int length;
	std::cin >> length;

	std::vector<float> vector(length);
	std::cout << "Enter " << length << " decimal numbers:\n";
	for (int i = 0; i < length; ++i)
	{
		std::cin >> vector[i];
	}

	std::cout << "These are the numbers your entered in the opposite order:\n";
	for (int i = length - 1; i >= 0; --i)
	{
		std::cout << vector[i] << " ";
	}
	
	return 0;
}










//Задание 3

#include <iostream>
#include <vector>

int main()
{
	std::cout << "How many elements do you want: ";
	int length;
	std::cin >> length;

	std::vector<int> vector(length);
	std::cout << "Enter " << length << " numbers:\n";
	for (int i = 0; i < length; ++i)
	{
		std::cin >> vector[i];
	}

	
	for (int outer = 0; outer < 2; ++outer)
	
	{
		int max = outer;
		for (int inner = outer; inner < length; ++inner)
		{
			if (vector[inner] > vector[max])
				max = inner;
		}
		std::swap(vector[outer], vector[max]);
	}

	std::cout << "The second max element you entered: " << vector[1];
	
	return 0;
}










//2. Добавление элемента в конец вектора

//Задание 1. Очередь из роботов

#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> queue, int number)
{
	std::vector<int> newQueue(queue.size() + 1);

	for (int index = 0; index < queue.size(); ++index)
		newQueue[index] = queue[index];
	newQueue[queue.size()] = number;

	return newQueue;
}

int main()
{
	std::vector<int> queue;

	int number = 0;
	while (number != -1)
	{
		std::cout << "Please enter your number: ";
		std::cin >> number;

		queue = add(queue, number);
	}

	for (int index = 0; index < queue.size(); ++index)
	{
		std::cout << queue[index] << " ";
	}

	return 0;
}










//Задание 2. Лечебница

#include <iostream>
#include <vector>

std::vector<int> add(std::vector<int> ageData, int number)
{
	std::vector<int> newAgeData(ageData.size() + 1);

	for (int index = 0; index < ageData.size(); ++index)
		newAgeData[index] = ageData[index];
	newAgeData[ageData.size()] = number;

	return newAgeData;
}

int main()
{
	std::vector<int> ageData;

	int patientsCount = 0;

	int number = 0;
	while (number != -1)
	{
		std::cout << "Please enter patient's age: ";
		std::cin >> number;
		if (number >= 0)
		{
			++patientsCount;
			ageData = add(ageData, number);
		}
	}

	float sum = 0;
	for (int index = 0; index < ageData.size(); ++index)
	{
		sum += ageData[index];
	}

	float meanAge = sum / patientsCount;

	std::cout << "Number of patients: " << patientsCount << '\n';
	std::cout << "Patients' average age: " << meanAge << '\n';

	return 0;
}










//Задание 3. Роботы и коррупция*

#include <iostream>
#include <vector>

std::vector<int> addToPosition(std::vector<int> queue, int number, int position)
{
	std::vector<int> newQueue(queue.size() + 1);

	if (position <= queue.size())
	{
		for (int index = 0; index <= queue.size(); ++index)
			if (index < position - 1)
				newQueue[index] = queue[index];
			else if (index > position - 1 && index > 0)
				newQueue[index] = queue[index - 1];
			else if (index == position - 1)
				newQueue[position - 1] = number;
	}
	else if (position > queue.size())
	{
		for (int index = 0; index < queue.size(); ++index)
			newQueue[index] = queue[index];
		newQueue[queue.size()] = number;
	}

	return newQueue;
}

int main()
{
	std::vector<int> queue;

	int number = 0;
	while (number != -1)
	{
		std::cout << "Please enter your number: ";
		std::cin >> number;
		std::cout << "Enter your position: ";
		int position;
		std::cin >> position;

		queue = addToPosition(queue, number, position);
	}

	for (int index = 0; index < queue.size(); ++index)
	{
		std::cout << queue[index] << " ";
	}

	return 0;
}










//3. Удаление элемента со сдвигом

//Задание 1

#include <iostream>
#include <vector>

std::vector<int> changeDisplay(std::vector<int> display, int robotRequired)
{
	std::vector<int> newDisplay(display.size() - 1);
	for (int index = 0; index < display.size(); ++index)
	{
		if (index < robotRequired)
			newDisplay[index] = display[index];
		else if (index > robotRequired)
			newDisplay[index - 1] = display[index];
	}
	display = newDisplay;

	return display;
}

int main()
{
	std::cout << "How many robots are there on the display: ";
	int robotsCount;
	std::cin >> robotsCount;
	std::vector<int> display(robotsCount);

	std::cout << "Enter robots' numbers:\n";
	for (int index = 0; index < robotsCount; ++index)
	{
		std::cin >> display[index];
	}
	
	int index = 0;
	while (index < display.size())
	{
		std::cout << "\nWhich robot is required? ";
		int robotRequired;
		std::cin >> robotRequired;

		if (robotRequired < 0 || robotRequired >= display.size())
			std::cout << "No such robot!\n";
		else
			display = changeDisplay(display, robotRequired);


		if (display.size() == 0)
			std::cout << "No robots left!\n";
		else
			std::cout << "Robots left: ";
			for (int index = 0; index < display.size(); ++index)
				std::cout << display[index] << " ";

	}

	return 0;
}










//Задание 2

#include <iostream>
#include <vector>

std::vector<int> changeDisplay(std::vector<int> display, int action, int number)
{
	if (action == 1)
	{
		display.resize(display.size() + 1);
		display[display.size() - 1] = number;
	}

	if (action == 2)
	{
		std::vector<int> newDisplay(display.size() - 1);
		for (int index = 0; index < display.size(); ++index)
		{
			if (index < number)
				newDisplay[index] = display[index];
			else if (index > number)
				newDisplay[index - 1] = display[index];
		}
		display = newDisplay;
	}
	
	return display;
}

int main()
{
	std::vector<int> display;
	
	std::cout << "Enter number of required actions: ";
	int actionsCount;
	std::cin >> actionsCount;
	
	int index = 0;
	while (index < actionsCount)
	{
		std::cout << "Enter required action: ";
		int action;
		int number;
		std::cin >> action >> number;
		
		if (action == 2 && number > display.size())
			std::cout << "No such item.\n";
		else
			display = changeDisplay(display, action, number);

		++index;
	}
	
	for (int index = 0; index < display.size(); ++index)
		std::cout << display[index] << " ";

	return 0;
}










//4. Использование push_back()

//Задание 1

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> queue;

	int number = 0;
	while (number != -1)
	{
		std::cout << "Enter your number: ";
		std::cin >> number;

		queue.push_back(number);
	}

	for (int index = 0; index < queue.size(); ++index)
		std::cout << queue[index] << " ";

	return 0;
}










//Задание 2

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> queue;

	int number = 0;
	while (number != -1)
	{
		std::cout << "Enter your number: ";
		std::cin >> number;

		while (queue.size() != 0 && queue[queue.size() - 1] < number)
		{
			queue.pop_back();
		}

		queue.push_back(number);
	}

	for (int index = 0; index < queue.size(); ++index)
		std::cout << queue[index] << " ";

	return 0;
}










//5. Практическая работа

//Задача 1

#include <iostream>
#include <vector>

int main()
{
	std::cout << "Input vector size: ";
	int size;
	std::cin >> size;
	std::vector<int> vec(size);
	
	std::cout << "Input " << size << " numbers: ";
	for (int index = 0; index < size; ++index)
		std::cin >> vec[index];

	std::cout << "Input number to delete: ";
	int numberToDelete;
	std::cin >> numberToDelete;
	
	for (int outerIndex = 0; outerIndex < vec.size(); ++outerIndex)
	{
		if (vec[outerIndex] == numberToDelete)
		{
			for (int innerIndex = outerIndex; innerIndex < vec.size() - 1; ++innerIndex)
			{
				std::swap(vec[innerIndex], vec[innerIndex + 1]);
			}
			vec.pop_back();
			--outerIndex;
		}
	}

	for (int index = 0; index < vec.size(); ++index)
		std::cout << vec[index] << " ";

	return 0;
}










//Задача 2

#include <iostream>
#include <vector>

int main()
{
	std::vector<float> prices = { 7.5, 8.25, 9.0, 5.25, 6.5, 10.0 };
	std::vector<int> items = { 1, 4, 2, 5, 5 };

	float sum = 0;
	for (int index = 0; index < items.size(); ++index)
	{
		sum += prices[items[index]];
	}

	std::cout << "Total sum: " << sum << '\n';

	return 0;
}










//Задача 3




