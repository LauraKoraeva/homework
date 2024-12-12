/*Массивы и Указатели в C++
Урок 3. Двумерные массивы и алгоритмы над ними*/

//Задание 2. Крестики-нолики

#include <iostream>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
	if (std::cin.fail() || std::cin.peek() != '\n' || input < 0 || input >= 3)
	{
		std::cout << "Coordinates are wrong. Try again!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return false;
	}
	else
		return true;
}

void makeMove(std::string name, char symbol, char(*grid)[3], bool(*moves)[3])
{
	int i, j;
	do
	{
		std::cout << name << ", enter coordinates : \n";

		do
		{
			std::cout << "y - ";
			std::cin >> i;
		} while (!correctInput(i));

		do
		{
			std::cout << "x - ";
			std::cin >> j;
		} while (!correctInput(j));

		if (moves[i][j])
			std::cout << "Coordinates are taken. Try again!\n";
	} while (moves[i][j] == true);

	moves[i][j] = true;
	grid[i][j] = symbol;
}

bool hasWinner(const char(*grid)[3], char symbol)
{
	bool hasWinner = false;
	int countH = 0;
	int countV = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (grid[i][j] == symbol)
				++countH;

			if (i == 0)
			{
				for (int k = 0; k < 3; ++k)
				{
					if (grid[k][j] == symbol)
						++countV;
				}

				if (countV == 3)
				{
					hasWinner = true;
					return hasWinner;
				}
				else
					countV = 0;
			}
		}
		if (countH == 3)
		{
			hasWinner = true;
			return hasWinner;
		}
		else
			countH = 0;
	}

	return hasWinner;
}

bool hasWinnerD(const char(*grid)[3], char symbol)
{
	bool hasWinnerD = false;
	int count1 = 0;
	int count2 = 0;

	int i1 = 0;
	int j1 = 0;
	while (i1 != 3)
	{
		if (grid[i1][j1] == symbol)
			++count1;

		if (count1 == 3)
		{
			hasWinnerD = true;
			return hasWinnerD;
		}
		++i1;
		++j1;
	}

	int i2 = 0;
	int j2 = 2;
	while (i2 != 3)
	{
		if (grid[i2][j2] == symbol)
			++count2;

		if (count2 == 3)
		{
			hasWinnerD = true;
			return hasWinnerD;
		}
		++i2;
		--j2;
	}

	return hasWinnerD;
}

void printGrid(const char(*grid)[3])
{
	

	std::cout << "_________________________________\n";
	std::cout << " ----------- \n";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "| ";
		for (int j = 0; j < 3; ++j)
		{
			std::cout << grid[i][j] << " | ";
		}
		if (i == 0)
			std::cout << "     |00|01|02|";
		if (i == 1)
			std::cout << "     |10|11|12|";
		if (i == 2)
			std::cout << "     |20|21|22|";
		std::cout << "\n";
		if (i < 2)
			std::cout << "|---|---|---|\n";
	}
	std::cout << " ----------- \n";
	std::cout << "_________________________________\n";

}

int main()
{
	char grid[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
	bool moves[3][3] = { false };

	std::cout << "Player 1, enter your name: ";
	std::string playerOne;
	std::cin >> playerOne;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Player 2, enter your name: ";
	std::string playerTwo;
	std::cin >> playerTwo;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	char symbolX = 'X';
	char symbolO = 'O';

	bool isDraw = true;

	int movesCount = 9;
	int count = 0;
	while (count < movesCount)
	{
		if (count % 2 == 0)
		{
			makeMove(playerOne, symbolX, grid, moves);
			printGrid(grid);
			if (hasWinner(grid, symbolX) || hasWinnerD(grid, symbolX))
			{
				std::cout << playerOne << ", you have won! Congratulations!\n";
				isDraw = false;
				break;
			}
		}
		else
		{
			makeMove(playerTwo, symbolO, grid, moves);
			printGrid(grid);
			if (hasWinner(grid, symbolO) || hasWinnerD(grid, symbolO))
			{
				std::cout << playerTwo << ", you have won! Congratulations!\n";
				isDraw = false;
				break;
			}
		}

		++count;
	}
	if (isDraw)
		std::cout << "It's a draw!\n";

	return 0;
}