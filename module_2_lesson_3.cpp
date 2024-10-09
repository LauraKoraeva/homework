//Задание 1. Банкетный стол

#include <iostream>

int main()
{
	int cutlery[2][6] = {
		{ 4, 3, 3, 3, 3, 3 },
		{ 4, 3, 3, 3, 3, 3 }
	};

	int plates[2][6] = {
		{ 3, 2, 2, 2, 2, 2 },
		{ 3, 2, 2, 2, 2, 2 }
	};

	int chairs[2][6] = {
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 }
	};

	chairs[0][4] += 1;

	cutlery[1][2] -= 1;

	cutlery[1][0] -= 1;

	cutlery[1][2] += 1;

	plates[1][0] -= 1;

	return 0;
}










//Задание 2. Крестики-нолики

#include <iostream>

bool checkColumns(char grid[3][3], char symbol)
{
	bool hasWinner = true;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (grid[i][j] != symbol)
			{
				hasWinner = false;
				break;
			}
		}
		if (hasWinner)
			return true;
	}
	return false;
}

bool checkRows(char grid[3][3], char symbol)
{
	bool hasWinner = true;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (grid[j][i] != symbol)
			{
				hasWinner = false;
				break;
			}
		}
		if (hasWinner)
			return true;
	}
	return false;
}

bool hasWinner(char grid[3][3], char symbol)
{
	return checkColumns(grid, symbol) || checkRows(grid, symbol);
}

void printGrid(char grid[3][3])
{
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

	bool isDraw = true;
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
			
			moves[i][j] = true;
			grid[i][j] = 'X';
			printGrid(grid);
			if (hasWinner(grid, 'X'))
			{
				std::cout << "Player 1 has won! Congratulations!\n";
				isDraw = false;
				break;
			}
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
			
			moves[i][j] = true;
			grid[i][j] = 'O';
			printGrid(grid);
			if (hasWinner(grid, 'O'))
			{
				std::cout << "Player 2 has won! Congratulations!\n";
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








//Задание 3. Матрицы

#include <iostream>

bool isDifferent(int matrixA[][4], int matrixB[][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (matrixA[i][j] != matrixB[i][j])
				return true;
		}
	}
}

void makeDiagonal(int matrixA[][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i != j)
				matrixA[i][j] = 0;
		}
	}
}

int main()
{
	int matrixA[4][4];
	int matrixB[4][4];

	std::cout << "Enter matrix A:\n";
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cin >> matrixA[i][j];
		}
	}

	std::cout << "Enter matrix B:\n";
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cin >> matrixB[i][j];
		}
	}
	
	if (isDifferent(matrixA, matrixB) == true)
		std::cout << "MatrixA and MatrixB are different\n";
	else
	{
		std::cout << "MatrixA and MatrixB are equal\n";
		makeDiagonal(matrixA);

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				std::cout << matrixA[i][j] << " ";
			}
			std::cout << '\n';
		}
	}

	return 0;
}