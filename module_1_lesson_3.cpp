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
  std::cout << "Enter login: ";
  std::string login;
  std::cin >> login;

  std::cout << "Enter password: ";
  std::string password;
  std::cin >> password;

  std::cout << login << ", you have successfully logged in!";

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
  std::string busStop1 = "\"Programmers Street\"";
  std::string busStop2 = "\"Algorithms Avenue\"";
  std::string busStop3 = "\"Stroustrup Street\"";
  std::string busStop4 = "\"Torvalds Street\"";
  int revenue = 0;
  int fare = 20;

  std::cout << "We are arriving at the " << busStop1 << "bus stop. Passengers in the bus: " << passengers << '\n';
  std::cout << "How many passengers got off at the bus stop? ";
  std::cin >> passengersOff;
  std::cout << "How many passengers got on?  ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "We are leaving " << busStop1 << "bus stop. Passengers in the bus: " << passengers << '\n';

  std::cout << "We are arriving at the " << busStop2 << "bus stop. Passengers in the bus: " << passengers << '\n';
  std::cout << "How many passengers got off at the bus stop? ";
  std::cin >> passengersOff;
  std::cout << "How many passengers got on?  ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "We are leaving " << busStop2 << "bus stop. Passengers in the bus: " << passengers << '\n';

  std::cout << "We are arriving at the " << busStop3 << "bus stop. Passengers in the bus: " << passengers << '\n';
  std::cout << "How many passengers got off at the bus stop? ";
  std::cin >> passengersOff;
  std::cout << "How many passengers got on?  ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "We are leaving " << busStop3 << "bus stop. Passengers in the bus: " << passengers << '\n';

  std::cout << "We are arriving at the " << busStop4 << "bus stop. Passengers in the bus: " << passengers << '\n';
  std::cout << "How many passengers got off at the bus stop? ";
  std::cin >> passengersOff;
  std::cout << "How many passengers got on?  ";
  std::cin >> passengersOn;
  passengers = passengers + passengersOn - passengersOff;
  revenue = revenue + (passengersOn * fare);
  std::cout << "We are leaving " << busStop4 << "bus stop. Passengers in the bus: " << passengers << '\n';

  int driverWage = revenue / 4;
  int fuel = revenue / 5;
  int tax = revenue / 5;
  int carMaintenance = revenue / 5;
  int income = revenue - driverWage - fuel - tax - carMaintenance;

  std::cout << "-------------------------\n";
  std::cout << "Revenue: " << revenue << '\n';
  std::cout << "Driver's wage: " << driverWage << '\n';
  std::cout << "Fuel costs: " << fuel << '\n';
  std::cout << "Taxes: " << tax << '\n';
  std::cout << "Car Maintenance costs: " << carMaintenance << '\n';
  std::cout << "Income: " << income << '\n';

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
  std::cout << "Swapping variables" << '\n';
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

  std::cout << "The height of the bamboo by the middle of what day are you interested in? ";
  int dayNumber;
  std::cin >> dayNumber;

  int currentHeight = initialHeight + (dailyGrowth - nightlyLoss) * (dayNumber - 1) + dailyGrowth / 2;

  std::cout << "The height of the bamboo by the middle of day " << dayNumber << " will be " << currentHeight << " cm.\n";

  return 0; 
}


