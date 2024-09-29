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