//Урок 2. Запись в файлы

//Задание 1. Реализация записи в ведомость учёта

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream database("C:\\Users\\Acer\\Desktop\\textbook\\ConsoleApplication1\\ConsoleApplication1\\database.txt", std::ios::app);

	database.setf(std::ios::showpoint);
	database.setf(std::ios::fixed);
	database.precision(2);

	std::string name;
	std::string surname;
	std::string date;
	double cash;
	std::string currency = "RUB";

	std::cout << "Enter the data:\n";
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Surname: ";
	std::cin >> surname;
	
	bool invalidDate = false;
	do
	{
		std::cout << "Date: ";
		std::cin >> date;

		int day = std::stoi(date.substr(0, 2));
		int month = std::stoi(date.substr(3, 2));
		std::cout << day << " " << month << "\n";

		if (month > 12)
		{
			std::cout << "Invalid date.Try again\n";
			invalidDate = true;
		}
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		{
			std::cout << "Invalid date.Try again\n";
			invalidDate = true;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		{
			std::cout << "Invalid date.Try again\n";
			invalidDate = true;
		}
		else if (month == 2 && day > 29)
		{
			std::cout << "Invalid date.Try again\n";
			invalidDate = true;
		}
		else
			invalidDate = false;

	} while (invalidDate);

	std::cout << "Cash: ";
	std::cin >> cash;

	database << name << " " << surname << " " << date << " " << cash << " " << currency << std::endl;

	database.close();

	return 0;

}










//Задание 2. Реализация рисования случайных картин

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main()
{
	std::ofstream picture("C:\\Users\\Acer\\Desktop\\pic.txt");

	int length;
	int height;
	std::cout << "Enter the length: ";
	std::cin >> length;
	std::cout << "Enter the height: ";
	std::cin >> height;

	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			int number = rand() % 2;
			picture << number;
		}
		picture << std::endl;
	}

	picture.close();

	return 0;
}










//Задание 3. Реализация симуляции игры «Рыбалка»

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream river;
	river.open("C:\\Users\\Acer\\Desktop\\river.txt");

	std::ofstream basket("C:\\Users\\Acer\\Desktop\\basket.txt", std::ios::app);

	std::cout << "Which fish do you want to catch today? ";
	std::string fish;
	std::cin >> fish;
	if (fish != "sunfish" && fish != "shad" && fish != "carp" && fish != "bass" && fish != "bullhead" && fish != "catfish" && fish != "walleye")
		std::cout << "Sorry! No such fish in this lake!";
	else
	{
		int countFish = 0;
		std::string fishCaught;
		while (!river.eof())
		{
			river >> fishCaught;
			if (fish == fishCaught)
			{
				basket << fish << std::endl;
				++countFish;
			}
		}
		std::cout << "Congratulations! You've caught " << countFish << " " << fish << " today.";
	}

	
	river.close();
	basket.close();

	return 0;
}










//

#include <iostream>
#include <fstream>

int main()
{
	int bills[5] = { 100, 200, 500, 1000, 5000 };
	int money[1000];

	std::cout << "Operation:";
	std::string operation;
	std::cin >> operation;

	std::ifstream in("C:\\Users\\Acer\\Desktop\\money.bin", std::ios::binary);
	if (in.is_open())
	{
		in.read((char*)money, sizeof(money));
		in.close();
	}
	else
	{
		for (int i = 0; i < 1000; ++i)
		{
			money[i] = 0;
		}
	}

	if (operation == "+")
	{
		for (int i = 0; i < 1000; ++i)
		{
			if (money[i] == 0)
			{
				money[i] = bills[std::rand() % 5];
			}
		}
		std::ofstream out("C:\\Users\\Acer\\Desktop\\money.bin", std::ios::binary);
		out.write((char*)money, sizeof(money));
		return 0;
	}
	else if (operation == "-")
	{
		std::cout << "Amount:";
		int amount;
		std::cin >> amount;
		if ((amount % 100) != 0)
		{
			std::cerr << "Invalid amount:" << amount << std::endl;
			return 1;
		}

		int amount_to_collect = amount;
		for (int i = 4; i >= 0; --i) {
			int bill = bills[i];
			for (int j = 0; j < 1000; ++j) {
				if (money[j] == bill) {
					if (amount_to_collect >= bill) {
						money[j] = 0;
						amount_to_collect -= bill;
						if (amount_to_collect == 0)
						{
							std::cout << "Amount taken:" << amount << std::endl;
							std::ofstream out("C:\\Users\\Acer\\Desktop\\money.bin", std::ios::binary);
							out.write((char*)money, sizeof(money));
							return 0;
						}
					}
				}
			}
		}
		std::cerr << "Not enough compatible bills!" << std::endl;
		return 1;

	}
}

























































void list()
 {


    while(!recipients.eof())
     {
        recipients >> person.name >> person.surname >> person.date >> person.cash;
        if (person.name.empty()) 
        {
            break;
        } 
        else 
        {
            std::cout << person.name << " " << person.surname << " "  << person.date << " " << person.cash
                 << " " << std::endl;
            person.name = "";
        }
    }
}





























