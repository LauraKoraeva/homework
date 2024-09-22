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
std::string game = "Супер гонки";
int lap = 4;
std::string driver = "Шумахер";
int engine = 254;
int wheels = 93;
int steeringWheel = 49;
int wind = 21;
int rain = 17;
int speed = 358;

std::cout << "-------------------------\n";
std::cout << game << ". Круг " << lap << "\n";
std::cout << "-------------------------\n";
std::cout << driver << " (" << speed << ")" << '\n';
std::cout << "-------------------------\n";
std::cout << "Водитель: " << driver << '\n';
std::cout << "Скорость: " << speed << '\n';
std::cout << "---------------\n";
std::cout << "Оснащение\n";
std::cout << "Двигатель: +" << engine << '\n';
std::cout << "Колеса: +" << wheels << '\n';
std::cout << "Руль: +" << steeringWheel << '\n';
std::cout << "---------------\n";
std::cout << "Действия плохой погоды\n";
std::cout << "Ветер: -" << wind << '\n';
std::cout << "Дождь: -" << rain << '\n';
}










//Практическая работа

//Задание 1. Улучшаем гонщика
#include <iostream>

int main()
{
std::string game = "Супер гонки";
int lap = 4;
std::string driver = "Шумахер";

int engine = 254;
int wheels = 93;
int steeringWheel = 49;

int wind = 21;
int rain = 17;

int speed = engine + wheels + steeringWheel - wind - rain;

std::cout << "-------------------------\n";
std::cout << game << ". Круг " << lap << "\n";
std::cout << "-------------------------\n";
std::cout << driver << " (" << speed << ")" << '\n';
std::cout << "-------------------------\n";
std::cout << "Водитель: " << driver << '\n';
std::cout << "Скорость: " << speed << '\n';
std::cout << "---------------\n";
std::cout << "Оснащение\n";
std::cout << "Двигатель: +" << engine << '\n';
std::cout << "Колеса: +" << wheels << '\n';
std::cout << "Руль: +" << steeringWheel << '\n';
std::cout << "---------------\n";
std::cout << "Действия плохой погоды\n";
std::cout << "Ветер: -" << wind << '\n';
std::cout << "Дождь: -" << rain << '\n';

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
  std::cout << "Эта программа рассчитывает, сколько клиентов успеет обслужить кассир за смену.\n";
  
  std::cout << "Введите длительность смены в минутах: ";
  int shiftDuration;
  std::cin >> shiftDuration;

  std::cout << "Сколько минут клиент делает заказ? ";
  int orderDuration;
  std::cin >> orderDuration;
  
  std::cout << "Сколько минут кассир собирает заказ? ";
  int executionDuration;
  std::cin >> executionDuration;

  int serviceDuration = orderDuration + executionDuration;
  int customersCount = shiftDuration / serviceDuration;

  std::cout << "За смену длиной " << shiftDuration << " минут кассир успеет обслужить " << customersCount << " клиентов.\n";

return 0;
}










//Задание 4. Непонятная квитанция

#include <iostream>

int main()
{
  std::cout << "Приветствуем вас в калькуляторе квартплаты!\n";
  std::cout << "Введите сумму, указанную в квитанции: ";
  int totalSum;
  std::cin >> totalSum;

  std::cout << "Сколько подъездов в вашем доме? ";
  int blocksCount;
  std::cin >> blocksCount;
  
  std::cout << "Сколько квартир в каждом подъезде ? ";
  int flatsPerBlock;
  std::cin >> flatsPerBlock;

  int flatsCount = blocksCount * flatsPerBlock;
  int sumPerFlat = totalSum / flatsCount;

  std::cout << "Каждая квартира должна заплатить по " << sumPerFlat << " руб.\n";
  
  return 0;
}


