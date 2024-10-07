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










//Задание 2. Реализация программы напоминания о днях рождения

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

struct BirthdayInfo
{
	std::string name;
	std::string surname;
	std::tm birthday;
};


int main()
{
	std::vector<BirthdayInfo> birthdays;
	while (true)
	{
		BirthdayInfo person;
		std::cout << "Enter the name: ";
		std::cin >> person.name;
		if (person.name == "end")
			break;
		std::cout << "Enter the surname: ";
		std::cin >> person.surname;
		std::cout << "Enter the birthday [YYYY / MM / DD]: ";
		std::time_t t = std::time(nullptr);
		std::tm local = *std::localtime(&t);
		person.birthday = local;
		std::cin >> std::get_time(&person.birthday, "%Y/%m/%d");
		birthdays.push_back(person);
	}

	std::time_t t = std::time(nullptr);
	std::tm* today = std::localtime(&t);

	int minIndex = 0;
	int minDays = 366;

	for (int i = 0; i < birthdays.size(); ++i)
	{
		if (birthdays[i].birthday.tm_mon >= today->tm_mon)
		{
			birthdays[i].birthday.tm_year = today->tm_year;
			std::time_t b = std::mktime(&birthdays[i].birthday);
			std::time_t t = std::mktime(today);

			double diff = std::difftime(b, t) / (60 * 60 * 24);
			if (birthdays[i].birthday.tm_mon == today->tm_mon && birthdays[i].birthday.tm_mday == today->tm_mday)
				std::cout << "Today is " << birthdays[i].name << " " << birthdays[i].surname << "'s birthday.\n";
			else if (diff < minDays && (birthdays[i].birthday.tm_mon != today->tm_mon || birthdays[i].birthday.tm_mday != today->tm_mday))
			{
				minDays = diff;
				minIndex = i;
			}
		}
	}
	std::cout << birthdays[minIndex].name << " " << birthdays[minIndex].surname << "\'s birthday is on " <<
		std::put_time(&birthdays[minIndex].birthday, "%m/%d") << " .Don't forget to buy a present.\n";

	return 0;
}










//Задание 3. Реализация программы таймера

#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
    std::cout << "Set the timer [MM:SS]: ";
   
    std::tm timer;
    std::cin >> std::get_time(&timer, "%M:%S");
   
    std::time_t currentTime = std::time(nullptr);
    std::time_t targetTime = currentTime + timer.tm_min * 60 + timer.tm_sec;

    while (currentTime != targetTime)
    {
        std::time_t diff = targetTime - currentTime;
        currentTime = std::time(nullptr);
        if (currentTime + diff != targetTime)
        {
            int newDiff = targetTime - currentTime;
            int minutes = newDiff / 60;
            int seconds = newDiff % 60;
            std::cout << minutes << ":" << seconds / 10 << seconds % 10 << '\n';
        }
    }

    std::cout << "DING! DING! DING!\n";
   
    return 0;
}