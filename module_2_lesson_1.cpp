//Задание 1. Многоквартирный дом

#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter owners' surnames:\n";
	std::string owner[10];
	for (int i = 0; i < 10; ++i)
	{
		std::cin >> owner[i];
	}

	for (int count = 0; count < 3; ++count)
	{
		std::cout << "Enter apartment number: ";
		int apartment;
		std::cin >> apartment;

		if (apartment >= 1 && apartment <= 10)
		{
			std::cout << owner[apartment - 1] << " lives in Apartment #" << apartment << '\n';
		}
		std::cout << "Error!\n";

		
	}

	return 0;
}










//Задание 2. Сортировка

#include <iostream>

void heapify(float array[], int length, int root)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < length && array[left] < array[smallest])
    {
        smallest = left;
    }
    
    if (right < length && array[right] < array[smallest])
    {
        smallest = right;
    }
    
    if (smallest != root)
    {
        std::swap(array[root], array[smallest]);
        heapify(array, length, smallest);
    }
}

void heapSort(float array[], int length)
{
    for (int root = length / 2 - 1; root >= 0; --root)
    {
        heapify(array, length, root);
    }

    for (int index = length - 1; index >= 0; --index)
    {
        std::swap(array[0], array[index]);
        heapify(array, index, 0);
    }
}

void printArray(float array[], int length)
{
    for (int count = 0; count < length; ++count)
    {
        std::cout << array[count] << " ";
    }
}

int main()
{
    const int length = 15;
    float array[length];
    std::cout << "Enter 15 decimal numbers:\n";
    for (int count = 0; count < 15; ++count)
    {
        std::cin >> array[count];
    }

    heapSort(array, length);

    printArray(array, length);
}










//Задание 3. Использование assert

#include <iostream>
#include <cassert>

float travelTime(float distance, float speed)
{
    assert(speed > 0);

    float time = distance / speed;
    return time;
}

int main()
{
    std::cout << "Enter distance: ";
    float distance;
    std::cin >> distance;

    std::cout << "Enter speed: ";
    float speed;
    std::cin >> speed;

    float time = travelTime(distance, speed);
    std::cout << "Travel time: " << time << '\n';

    return 0;
}