/*Основы программирования на C++
Урок 3. Ввод данных пользователя. Строки
*/

//Пользовательский ввод
//Задание 1
#include <iostream>

int main()
{
  std::cout << "Enter an integer to calculate its square: ";
  int a;
  std::cin >> a;

  int square = a * a;

  std::cout << "The square of " << a << " is " << square << '\n';

  return 0;
}










//Задание 2
#include <iostream>

int main()
{
std::cout << "Enter price: ";
int itemPrice;
std::cin >> itemPrice;

std::cout << "Enter delivery price: ";
int deliveryPrice;
std::cin >> deliveryPrice;

std::cout << "Enter discount: ";
int discount;
std::cin >> discount;

int totalPrice = itemPrice + deliveryPrice - discount;
std::cout << "\nTotal price: $" << totalPrice << '\n';

return 0;
}











//Строковый тип данных

//Задание 1

#include <iostream>
#include <string>

int main()
{
  std::string playerName;
  std::cout << "Введите имя: ";
  std::cin >> playerName;

  std::string playerRace;
  std::cout << "Введите расу: ";
  std::cin >> playerRace;

  std::cout << "Родился новый " << playerRace << ", его зовут " << playerName << ". Добро пожаловать в этот суровый мир!\n";

  return 0;
}

//Задание 2
#include <iostream>
#include <string>

int main()
{
  std::cout << "Введите логин: ";
  std::string login;
  std::cin >> login;

  std::cout << "Введите пароль: ";
  std::string password;
  std::cin >> password;

  std::cout << login << ", вы успешно зашли!";

  return 0;
}











//Практическая работа

//Задача 1. Симулятор маршрутки

#include <iostream>
#include <string>

int main()
{
  int passengers = 0;
  int passengersOn;
  int passengersOff;
  std::string busStop1 = "\"Улица Программистов\"";
  std::string busStop2 = "\"Проспект Алгоритмов\"";
  std::string busStop3 = "\"Улица Страуструпа\"";
  std::string busStop4 = "\"Улица Торвальдса\"";
  int revenue = 0;
  int fare = 20;

  std::cout << "Прибываем на остановку " << busStop1 << ". В салоне пассажиров: " << passengers << '\n';
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengersOff;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "Отправляемся с остановки " << busStop1 << ". В салоне пассажиров: " << passengers << '\n';

  std::cout << "Прибываем на остановку " << busStop2 << ". В салоне пассажиров: " << passengers << '\n';
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengersOff;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "Отправляемся с остановки " << busStop2 << ". В салоне пассажиров: " << passengers << '\n';

  std::cout << "Прибываем на остановку " << busStop3 << ". В салоне пассажиров: " << passengers << '\n';
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengersOff;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "Отправляемся с остановки " << busStop3 << ". В салоне пассажиров: " << passengers << '\n';

  std::cout << "Прибываем на остановку " << busStop4 << ". В салоне пассажиров: " << passengers << '\n';
  std::cout << "Сколько пассажиров вышло на остановке? ";
  std::cin >> passengersOff;
  std::cout << "Сколько пассажиров зашло на остановке? ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "Отправляемся с остановки " << busStop4 << ". В салоне пассажиров: " << passengers << '\n';

  int driverWage = revenue / 4;
  int fuel = revenue / 5;
  int tax = revenue / 5;
  int carMaintenance = revenue / 5;
  int income = revenue - driverWage - fuel - tax - carMaintenance;

  std::cout << "-------------------------\n";
  std::cout << "Всего заработали: " << revenue << '\n';
  std::cout << "Зарплата водителя: " << driverWage << '\n';
  std::cout << "Расходы на топливо: " << fuel << '\n';
  std::cout << "Налоги: " << tax << '\n';
  std::cout << "Расходы на ремонт машины: " << carMaintenance << '\n';
  std::cout << "Итого доход: " << income << '\n';

  return 0;

}










//Задание 2. Обмен местами

#include <iostream>

int main()
{
  int a = 5;
  int b = 7;
  std::cout << "a: " << a << '\n';
  std::cout << "b: " << b << '\n';
  int temp = a;
  a = b;
  b = temp;
  std::cout << "Меняем переменные местами" << '\n';
  std::cout << "a: " << a << '\n';
  std::cout << "b: " << b << '\n';

  return 0; 
}










//Задание 3. Злостные вредители

#include <iostream>

int main()
{
  int initialHeight = 100;
  int dailyGrowth = 50;
  int nightlyLoss = 20;

  std::cout << "Высота бамбука к середине какого дня Вас интересует? ";
  int dayNumber;
  std::cin >> dayNumber;

  int currentHeight = initialHeight + (dailyGrowth - nightlyLoss) * (dayNumber - 1) + dailyGrowth / 2;

  std::cout << "Высота бамбука к середине " << dayNumber << " дня составит " << currentHeight << " см.\n";

  return 0; 
}


