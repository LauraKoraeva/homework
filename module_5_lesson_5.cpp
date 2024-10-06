//Урок 5. Макросы и препроцессор

//Задание 1. Реализация продвинутого ввода и вывода дней недели

#include <iostream>

#define WEEKDAY(n)  (((n) == 1) ? "Monday" : ((n) == 2) ? "Tuesday" : ((n) == 3) ? "Wednesday" : \
((n) == 4)  ?  "Thursday" : ((n) == 5) ?  "Friday" : ((n) == 6) ?  "Saturday" : ((n) == 7) ?  "Sunday" : "Error")

int main() 
{
	std::cout << "Enter the day of the week:\n";
	int day;
	std::cin >> day;
	std::cout << WEEKDAY(day);
}










//Задание 2. Вывод времени года

#include <iostream>

#define WINTER 0
#define SPRING 1
#define SUMMER 2
#define AUTUMN 3
#define CURRENT_SEASON SPRING

int main() 
{
#if CURRENT_SEASON == 0
	std::cout << "Winter";
#elif CURRENT_SEASON == 1
	std::cout << "Spring";
#elif CURRENT_SEASON == 2
	std::cout << "Summer";
#elif CURRENT_SEASON == 3
	std::cout << "Autumn";
#endif
}