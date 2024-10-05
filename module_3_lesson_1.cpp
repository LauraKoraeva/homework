//Урок 1. Чтение из файлов

//Задание 1. Разработка программы поиска слов в файле

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream wordList;
	wordList.open("C:\\Users\\Acer\\Desktop\\textbook\\ConsoleApplication1\\ConsoleApplication1\\wordList.txt");
	
	std::string word[50];
	int count = 0;
	while (!wordList.eof())
	{
		wordList  >> word[count];
		++count;
	}

	std::cout << "Enter a word: ";
	std::string userWord;
	std::cin >> userWord;

	int userWordCount = 0;
	for (int i = 0; i < count; ++i)
	{
		if (word[i] == userWord)
			++userWordCount;
	}

	std::cout << "Matches found: " << userWordCount;

    wordList.close();

	return 0;
}










//Задание 2. Разработка просмотрщика текстовых файлов

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream file;
	std::string path;
	std::cout << "Enter path: ";
	std::getline(std::cin, path);
	file.open(path, std::ios::binary);

	if (file.is_open())
	{
		char buffer[20];
		while (!file.eof())
		{
			file.read(buffer, sizeof(buffer) - 1);
			buffer[file.gcount()] = 0;
			std::cout << buffer;
		}
	}
	else
		std::cout << "Path is not valid.\n";

	file.close();

	return 0;
}










//Задание 3. Реализация программы чтения ведомости

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream data;
	std::string path;
	std::cout << "Enter path: ";
	std::getline(std::cin, path);
	data.open(path, std::ios::binary);

	if (data.is_open())
	{
		std::string name;
		std::string surname;
		int cash;
		std::string date;
		int sum = 0;
		int maxCash = 0;
		std::string maxName;
		std::string maxSurname;
		std::string maxDate;

		while (!data.eof())
		{
			data >> name >> surname >> cash >> date;
			sum += cash;
			if (cash > maxCash)
			{
				maxCash = cash;
				maxName = name;
				maxSurname = surname;
				maxDate = date;
			}
		}
		std::cout << "Total cash: " << sum << '\n';
		std::cout << "Max cash " << "(" << maxCash << ") was paid to " << maxName << " " << maxSurname << " on " << maxDate << '\n';

        data.close();
	}
	else
		std::cout << "Path is not valid.\n";

	return 0;
}










//Задание 4. Разработка детектора PNG-файла

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream file;
	std::string path;
	std::cout << "Enter path: ";
	std::getline(std::cin, path);
	file.open(path, std::ios::binary);

	if (file.is_open())
	{
		char buffer[5];
		file.read(buffer, sizeof(buffer));
		if (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G' && path.substr(path.length() - 4, 4) == ".png")
			std::cout << "It's a png-file.\n";
		else
			std::cout << "It's not a png-file.\n";

		file.close();
	}
	else
		std::cout << "Path is not valid.\n";

	return 0;
}










//Задание 5. Реализация игры «Что? Где? Когда?»

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream questionsList;
	std::ifstream answersList;
	questionsList.open("C:\\Users\\Acer\\Desktop\\textbook\\ConsoleApplication1\\ConsoleApplication1\\questions.txt");
	answersList.open("C:\\Users\\Acer\\Desktop\\textbook\\ConsoleApplication1\\ConsoleApplication1\\answers.txt");

	std::vector<std::string> question;
	while (!questionsList.eof())
	{
		std::string line;
		std::getline(questionsList, line);
		question.push_back(line);
	}

	std::vector<std::string> answer;
	while (!answersList.eof())
	{
		std::string word;
		std::getline(answersList, word);
		answer.push_back(word);
	}

	bool sectors[13];
	for (int i = 0; i < 13; ++i)
		sectors[i] = true;

	std::cout << "Welcome to the game \"What? Where? When?\"!\n";
	int currentSector = 1;

	int playerScore = 0;
	int viewersScore = 0;
	int gameProgress = 0;
	while (playerScore != 6 && viewersScore != 6 && gameProgress != 13)
	{
		std::cout << "Enter the offset: ";
		int offset;
		std::cin >> offset;

		if (currentSector + offset <= 13)
			currentSector += offset;
		else
			currentSector = (currentSector + offset) % 13;

		while (!sectors[currentSector - 1])
		{
			if (currentSector == 13)
				currentSector = 1;
			++currentSector;
		}

		std::cout << "Question: " << question[currentSector - 1] << '\n';
		std::cout << "Enter your answer: ";
		std::string playerAnswer;
		std::cin >> playerAnswer;

		if (playerAnswer == answer[currentSector - 1])
		{
			playerScore += 1;
			std::cout << "correct answer";
		}
		else
		{
			viewersScore += 1;
			std::cout << "incorrect answer\n";
			std::cout << viewersScore << '\n';
		}

		sectors[currentSector - 1] = false;
		++gameProgress;
	}

	if (playerScore > viewersScore)
		std::cout << "Player won!\n";
	else
		std::cout << "Viewers won!\n";

	questionsList.close();
	answersList.close();

	return 0;
}
