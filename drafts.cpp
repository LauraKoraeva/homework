//Массивы и Указатели в C++

//Урок 3. Двумерные массивы и алгоритмы над ними

//Задание 2. Крестики-нолики

#include <iostream> //НЕТ ПРОВЕРКИ ПОБЕДИТЕЛЯ

int main()
{
	char grid[3][3];
	bool moves[3][3];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			grid[i][j] = ' ';
		}
		std::cout << '\n';
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			moves[i][j] = false;
		}
		std::cout << '\n';
	}

	int movesCount = 9;
	int count = 0;
	while (count < movesCount)
	{
		if (count % 2 == 0)
		{
			int i, j;
			do
			{
				std::cout << "Player 1, enter coordinates: \n";
				std::cin >> i >> j;

				if (i >= 3 || j >= 3)
					std::cout << "Coordinates are wrong. Try again!\n";
				else
				{
					if (moves[i][j])
						std::cout << "Coordinates are taken. Try again!\n";
				}
			} while (i >= 3 || j >= 3 || moves[i][j] == true);
			
			char symbol;
			do
			{
				std::cout << "Enter symbol: \n";
				std::cin >> symbol;
			} while (symbol != 'X');

			moves[i][j] = true;
			grid[i][j] = symbol;
		}

		else
		{
			int i, j;
			do
			{
				std::cout << "Player 2, enter coordinates: \n";
				std::cin >> i >> j;

				if (i >= 3 || j >= 3)
					std::cout << "Coordinates are wrong. Try again!\n";
				else
				{
					if (moves[i][j])
						std::cout << "Coordinates are taken. Try again!\n";
				}
			} while (i >= 3 || j >= 3 || moves[i][j] == true);
			
			char symbol;
			do
			{
				std::cout << "Enter symbol: \n";
				std::cin >> symbol;
			} while (symbol != 'O');

			moves[i][j] = true;
			grid[i][j] = symbol;
		}
		
		++count;

		std::cout << "***************\n";
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				std::cout << grid[i][j];
			}
			std::cout << '\n';
		}
		std::cout << "***************\n";

	}

	return 0;
}

