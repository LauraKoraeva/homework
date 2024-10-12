//Задача 1. Кукушка (цикл for).

#include <iostream>

int main()
{
    std::cout << "Enter the time: ";
    int hour;
    std::cin >> hour;

    for (; hour <= 0 || hour > 12; )
    {
        std::cout << "Time must be between 1 and 12. Enter the time: ";
        std::cin >> hour;
    }

    for (int count = 0; count < hour; ++count)
        std::cout << "Peek-a-boo!\n";

    return 0;
}










//Задача 2. Сумма чисел (цикл for).
#include <iostream>

int main()
{
    std::cout << "How many numbers do you want to add up: ";
    int numbersCount;
    std::cin >> numbersCount;
    
    int sum = 0;
    for (int inputCounts = 1; inputCounts <= numbersCount; ++inputCounts)
    {
        std::cout << "Enter number " << inputCounts << ": ";
        int number;
        std::cin >> number;
        sum += number;
    }

    std::cout << "The sum of the entered numbers: " << sum << '\n';

    return 0;
}










//Задача 3. Таблица умножения.
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    for (int count = 1; count <= 10; ++count)
    {
        int result = number * count;
        std::cout << number << " * " << count << " = " << result << '\n';
    }

    return 0;
}










//Задача 4. Сумма нечётных.
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    int sum = 0;
    for (int count = 1; count <= number; ++count)
    {
        if (!(count % 2 == 0))
        sum += count;
    }

    std::cout << "The sum of odd numbers in the range from 1 to " << number << ": " << sum << '\n';

    return 0;
}










//Задача 5. Начальник (цикл for).

#include <iostream>
#include <string>

int main()
{
    std::string answer;
    int count = 0;

    for (; answer != "Yes, of course I have"; )
    {
        std::cout << "Have you completed the task?";
        std::getline(std::cin, answer);
        ++count;
    }

    std::cout << "Why do I have to ask " << count << " times?";

    return 0;
}










//Варианты цикла for

//Задача 1. Пароль (цикл for).
#include <iostream>

int main()
{
    bool result = false;
    for (; !result; )
    {
        std::cout << "Enter the password: ";
        int password;
        std::cin >> password;

        int sum = 0;
        for (; password != 0; password /= 10)
        {
            sum += password % 10;
        }

        if (sum == 42)
            result = true;           
        else
            std::cout << "The password is incorrect.\n";
    }
    std::cout << "The password is correct.";

    return 0;
}










//Задача 2. Кадастровые проблемы (цикл for).
#include <iostream>

int main()
{
    std::cout << "Enter the area of the plot: ";
    int square;
    std::cin >> square;

    int count = 1;
    for (; count * count < square; ++count)
    {

    }

    if (count * count == square)
        std::cout << "The area is a perfect square.\n";
    else
        std::cout << "The area is not a perfect square.\n";

    return 0;
}










//Задача 3. Крепкий орешек.
#include <iostream>
#include <string>

int main()
{
    std::string answer;
    int count = 10;
    for (; count >= 1; )
    {
        std::cout << "Do you want to cut the wire? ";
        std::getline(std::cin, answer);

        if (answer == "yes" || answer == "Yes")
        {
            --count;
            break;
        }
        else if (answer == "no" || answer == "No")
        {
            --count;
            if (count != 0)
                std::cout << count << " seconds before the explosion\n";
        }
        else
        { 
            --count;
            std::cout << "Did not get the answer. Repeat please\n";
            std::cout << count << " seconds before the explosion\n";
        }
           
    }
    if (count == 0)
        std::cout << "The bomb exploded.";
    else
        std::cout << "Bomb threat neutralized " << count << " seconds before the explosion.\n";

    return 0;
}










//Практическая работа

//Задание 1. Запасы продовольствия
#include <iostream>

int main()
{
    int buckwheat = 100;
    std::cout << "At the beginning you had " << buckwheat << " kg of buckwheat.\n";
    
    for (int count = 1; buckwheat > 0; ++count)
    {    
        buckwheat -= 4;
        if (buckwheat <= 0)
            std::cout << "After the " << count << " month you will have no buckwheat left.\n";
        else 
            std::cout << "After the " << count << " month you will have " << buckwheat << " kg of buckwheat left.\n";       
    }
    
    return 0;
}










//Задание 2. Кофемашина

#include <iostream>

int main()
{
    std::cout << "How much water: ";
    int water;
    std::cin >> water;

    std::cout << "How much milk: ";
    int milk;
    std::cin >> milk;

    int countAmericano = 0;
    int countLatte = 0;

    do
    {
        std::cout << "Choose drink (americano - 1, latte - 2): ";
        int choice;
        std::cin >> choice;

        if (choice < 0 || choice > 2)
            std::cout << "Try again!\n";

        else if (choice == 1)
        {
            if (water < 300)
                std::cout << "Not enough water\n";
            else
            {
                water -= 300;
                ++countAmericano;
                std::cout << "Your drink is ready!\n";
            }
        }

        
        else if (choice == 2)
        {
            if (water < 270)
                std::cout << "Not enough water\n";
            else if (milk < 30)
                std::cout << "Not enough milk\n";
            else
            {
                water -= 270;
                milk -= 30;
                ++countLatte;
                std::cout << "Your drink is ready!\n";
            }
        }
    } while (water >= 300 || water >= 270 && milk >= 30);


    std::cout << "\n*****Report*****\n";
    std::cout << "\nIngredients left:\n";
    std::cout << "Water: " << water << " ml\n";
    std::cout << "Milk: " << milk << " ml\n";
    std::cout << "\nAmericano made: " << countAmericano << '\n';
    std::cout << "Latte made: " << countLatte << '\n';

    return 0;
}










//Задание 3. Красный Марс

#include <iostream>
#include <string>

int main() 
{
    int y = 20;
    int x = 15;
    int currentY = 19;
    int currentX = 6;

    while(true)
    {
        std::cout << "The rover is in position " << currentX << ", " << currentY << ", enter the command:\n";
        std::string way;
        std::cin >> way;

        if (way == "A")
        {
            if (currentX > 1)
            {
                currentX -= 1;
            }
        }

        else if (way == "D")
        {
            if (currentX < x)
            {
                currentX += 1;
            }
        }

        else if (way == "S")
        {
            if (currentY > 1)
            {
                currentY -= 1;
            }
        }

        else if (way == "W")
        {
            if (currentY < y)
            {
                currentY += 1;
            }
        }

        else
            std::cout << "Input error. Repeat the direction.\n";


    }
    
    return 0;
}










//Задание 4. Рамка

#include <iostream>

int main() 
{
	std::cout << "Enter width and height: ";
	int width, height;
	std::cin >> width >> height;

	for (int heightStart = 1; heightStart <= height; ++heightStart)
	{
		for (int widthStart = 1; widthStart <= width; ++widthStart)
		{
			if (widthStart == 1 || widthStart == width)
			{
				std::cout << "|";
			}
			else if (heightStart == 1 || heightStart == height)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
	return 0;
}










//Задание 5. Координатные оси

#include <iostream>

int main() 
{
	for (int row = 0; row <= 20; ++row)
	{
		for (int col = 0; col <= 50; ++col)
		{
			if (row == 20 / 2 && col == 50 / 2)
				std::cout << "+";
			else if (row == 0 && col == 50 / 2)
				std::cout << "^";
			else if (row == 20 / 2 && col == 50)
				std::cout << ">";
			else if (row == 20 / 2 && col != 50 / 2 && col != 50)
				std::cout << "-";
			else if (col == 50 / 2 && row != 0)
				std::cout << "|";
			else
				std::cout << " ";
		}
		std::cout << '\n';
	}
	return 0;
}









//Задание 6. Важные объявления

#include <iostream>

int main() 
{
	std::cout << "Enter the total length of the header: ";
	int symbolCount;
	std::cin >> symbolCount;

	int exclamationCount;
	bool correctNumber = false;
	do
	{
		std::cout << "Enter the number of exclamation marks: ";
		
		std::cin >> exclamationCount;
		
		if (exclamationCount > symbolCount - 2)
			std::cout << "The number of exclamation marks must be at least two characters less than the length of the header.";
		else
			correctNumber = true;
	} while (!correctNumber);

	int edgeCount = (symbolCount - exclamationCount) / 2;
	

	for (int currentSymbol = 1; currentSymbol <= symbolCount; ++currentSymbol)
	{
		if (currentSymbol <= edgeCount)
			std::cout << "~";
		else if (currentSymbol <= edgeCount + exclamationCount)
			std::cout << "!";
		else
			std::cout << "~";
	}

	return 0;
}




































