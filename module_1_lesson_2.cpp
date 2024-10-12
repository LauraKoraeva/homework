/*Основы программирования на C++
Урок 2. Целочисленные переменные. Данные и вычисления
*/

//Переменные и типы. Целочисленный тип

#include <iostream>

int main()
{
  int apartmentPrice = 750000;
  std::cout << "Apartment price: $" << apartmentPrice << '\n';
  
  int shoeSize = 38;
  std::cout << "Shoe size: " << shoeSize << '\n';
  
  int currentAnimalsCount = 115;
  std::cout << "Current number of animals: " << currentAnimalsCount << '\n';
  
  int newItemPrice = 545;
  std::cout << "New item price: $" << newItemPrice << '\n';

  return 0;
}











//Вывод значений переменных
#include <iostream>

int main()
{
std::string game = "Super Race";
int lap = 4;
std::string driver = "Schumacher";
int engine = 254;
int wheels = 93;
int steeringWheel = 49;
int wind = 21;
int rain = 17;
int speed = 358;

std::cout << "-------------------------\n";
std::cout << game << ". Lap " << lap << "\n";
std::cout << "-------------------------\n";
std::cout << driver << " (" << speed << ")" << '\n';
std::cout << "-------------------------\n";
std::cout << "Driver: " << driver << '\n';
std::cout << "Speed: " << speed << '\n';
std::cout << "---------------\n";
std::cout << "Equipment\n";
std::cout << "Engine: +" << engine << '\n';
std::cout << "Wheels: +" << wheels << '\n';
std::cout << "Steering wheel: +" << steeringWheel << '\n';
std::cout << "---------------\n";
std::cout << "Bad weather conditions\n";
std::cout << "Wind: -" << wind << '\n';
std::cout << "Rain: -" << rain << '\n';
}










//Практическая работа

//Задание 1. Улучшаем гонщика
#include <iostream>

int main()
{
std::string game = "Super Race";
int lap = 4;
std::string driver = "Schumacher";

int engine = 254;
int wheels = 93;
int steeringWheel = 49;

int wind = 21;
int rain = 17;

int speed = engine + wheels + steeringWheel - wind - rain;

std::cout << "-------------------------\n";
std::cout << game << ". Lap " << lap << "\n";
std::cout << "-------------------------\n";
std::cout << driver << " (" << speed << ")" << '\n';
std::cout << "-------------------------\n";
std::cout << "Driver: " << driver << '\n';
std::cout << "Speed: " << speed << '\n';
std::cout << "---------------\n";
std::cout << "Equipment\n";
std::cout << "Engine: +" << engine << '\n';
std::cout << "Wheels: +" << wheels << '\n';
std::cout << "Steering wheel: +" << steeringWheel << '\n';
std::cout << "---------------\n";
std::cout << "Bad weather conditions\n";
std::cout << "Wind: -" << wind << '\n';
std::cout << "Rain: -" << rain << '\n';

return 0;
}










//Задание 2. Калькулятор стоимости товара

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











//Задание 3. Время, время!

#include <iostream>

int main()
{
  std::cout << "This program calculates how many customers the cashier will have time to serve per shift.\n";
  
  std::cout << "Enter the shift duration in minutes: ";
  int shiftDuration;
  std::cin >> shiftDuration;

  std::cout << "How many minutes does the customer make an order? ";
  int orderDuration;
  std::cin >> orderDuration;
  
  std::cout << "How many minutes does it take the cashier to collect the order? ";
  int executionDuration;
  std::cin >> executionDuration;

  int serviceDuration = orderDuration + executionDuration;
  int customersCount = shiftDuration / serviceDuration;
  
  std::cout << "During a " << shiftDuration << "-minute shift the chashier will have time to serve " << customersCount << " clients.\n";

return 0;
}










//Задание 4. Непонятная квитанция

#include <iostream>

int main()
{
  std::cout << "Welcome to the property management calculator!\n";
  std::cout << "Enter the amount indicated on the receipt: ";
  int totalSum;
  std::cin >> totalSum;

  std::cout << "How many entrances are there in your block of flats? ";
  int blocksCount;
  std::cin >> blocksCount;
  
  std::cout << "How many apartments are there in each entrance? ";
  int flatsPerBlock;
  std::cin >> flatsPerBlock;

  int flatsCount = blocksCount * flatsPerBlock;
  int sumPerFlat = totalSum / flatsCount;

  std::cout << "Each apartment has to pay " << sumPerFlat << " rub.\n";
  
  return 0;
}


