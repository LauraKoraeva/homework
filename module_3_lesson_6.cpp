//Урок 6. Работа с датами

//Задание 1. Реализация программы учёта времени

#include <iostream>
#include <ctime>
#include <map>
#include <string>

void end(int& finishTime, int& timeSpent, int& startTime, std::string& currentTask, std::map<std::string, int>& progress)
{
	if (currentTask != "break")
	{
		finishTime = std::time(nullptr);
		timeSpent = (finishTime - startTime) / 60;
		progress.insert(std::pair<std::string, int>(currentTask, timeSpent));
	}
	currentTask = "break";
}

void begin(int& finishTime, int& timeSpent, int& startTime, std::string& currentTask, std::map<std::string, int>& progress)
{
	if (currentTask != "break")
		end(finishTime, timeSpent, startTime, currentTask, progress);
	
	std::cout << "Enter task: ";
	std::string task;
	std::getline(std::cin, task);
	currentTask = task;
	startTime = std::time(nullptr);
}

void status(std::map<std::string, int>& progress, std::string& currentTask)
{
	std::cout << "****************\n";
	std::cout << "Completed tasks:\n";
	for (std::map<std::string, int>::iterator it = progress.begin();
		it != progress.end(); ++it)
		std::cout << it->first << " (" << it->second << " min)" << std::endl;
	if (currentTask != "break")
		std::cout << "\nStill in progress: " << currentTask << '\n';
	std::cout << "****************\n";
}

int main() 
{
	int startTime = 0;
	int finishTime = 0;
	std::string currentTask = "break";
	int timeSpent = 0;
	std::map<std::string, int> progress;
	
	int operation;
	do
	{
		std::cout << "Choose an operation:\n";
		std::cout << "1 - begin a new task\n";
		std::cout << "2 - end a current task\n";
		std::cout << "3 - show progress\n";
		
		std::cin >> operation;
		std::cin.ignore(32767, '\n');
		if (operation == 1)
		{
			begin(finishTime, timeSpent, startTime, currentTask, progress);
		}
		else if (operation == 2)
		{
			end(finishTime, timeSpent, startTime, currentTask, progress);
		}
		else if (operation == 3)
		{
			status(progress, currentTask);
		}
	} while (operation != -1);

	return 0;
}