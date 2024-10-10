//Задание 1. Шифр Цезаря

#include <iostream>
#include <string>

void encrypt_ceasar(std::string &text, int key)
{
    if (key < 0)
        {
            key = 26 - (-key);
        }
    
    for (int i = 0; i < text.length(); ++i)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int newIndex = (text[i] - 'A' + key) % 26 + 'A';
            char symbol(newIndex);
            text[i] = symbol;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            int newIndex = (text[i] - 'a' + key) % 26 + 'a';
            char symbol(newIndex);
            text[i] = symbol;
        }
    }
}

void decrypt_ceasar(std::string &text, int key)
{
    encrypt_ceasar(text, (-key));
}

int main()
{
    std::cout << "Input the text: \n";
    std::string text;
    std::getline(std::cin, text);

    std::cout << "Input the key: \n";
    int key;
    std::cin >> key;

    encrypt_ceasar(text, key);
    std::cout << "\nencrypted: " << text << '\n';
    decrypt_ceasar(text, key);
    std::cout << "\ndecrypted: " << text << '\n';

    return 0;
}










//Задание 4. Оценка результатов игры в крестики-нолики

#include <iostream>

void checkRows(std::string grid[3], char& symbol, int& countWinners)
{
    for (int i = 0; i < 3; ++i)
    {
        int j = 0;
        if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2])
        {
            if (grid[i][j] != '.')
            {
                symbol = grid[i][j];
                ++countWinners;
            }
        }
    }
}

void checkColumns(std::string grid[3], char& symbol, int& countWinners)
{
    for (int j = 0; j < 3; ++j)
    {
        int i = 0;
        if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j])
        {
            if (grid[i][j] != '.')
            {
                symbol = grid[i][j];
                ++countWinners;
            }
        }
    }
}

void checkDiagonals(std::string grid[3], char& symbol, int& countWinners)
{
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]))
    {
        if (grid[1][1] != '.')
        {
            symbol = grid[1][1];
            ++countWinners;
        }
    }
}

bool checkValidity(std::string grid[3], int& count_X, int& count_O)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == 'X')
                ++count_X;
            else if (grid[i][j] == 'O')
                ++count_O;
            else if (grid[i][j] != 'X' && grid[i][j] != 'O' && grid[i][j] != '.')
                return false;
        }
    }

    if (count_O > count_X)
        return false;
}

void getResult(std::string grid[3], int& count_X, int& count_O, int& countWinners, char& symbol)
{
    checkRows(grid, symbol, countWinners);
    checkColumns(grid, symbol, countWinners);
    checkDiagonals(grid, symbol, countWinners);
    if (countWinners > 0)
    {
        if (countWinners > 1)
            std::cout << "Incorrect";
        else if (countWinners == 1 && symbol == 'X')
        {
            if (count_O >= count_X)
                std::cout << "Incorrect.\n";
            else
                std::cout << "Petya won!\n";
        }
        else if (countWinners == 1 && symbol == 'O')
        {
            if (count_X != count_O)
                std::cout << "Incorrect.\n";
            else
                std::cout << "Vanya won!\n";
        }
    }
    else if (count_X < 5 && count_O < 4)
        std::cout << "Nobody.\n";
    else
        std::cout << "Nobody.\n";
}

int main()
{
    std::cout << "Input the game grid\n";
    std::string grid[3];
    char symbol;
    for (int i = 0; i < 3; ++i)
    {
        std::cin >> grid[i];
    }

    int count_X = 0;
    int count_O = 0;
    int countWinners = 0;

   if (!checkValidity(grid, count_X, count_O))
       std::cout << "Incorrect.\n";
   else
       getResult(grid, count_X, count_O, countWinners, symbol);

    return 0;
}