/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Задача 1. Калькулятор скидки

#include <iostream>

int main()
{
  double itemCost1;
  double itemCost2;
  double itemCost3;
  double discount = 0.0;
  double discountAmount = 0.0;
  std::cout << "Let's calculate the check amount.\n";
  std::cout << "Enter the cost of the first item: ";
  std::cin >> itemCost1;
  std::cout << "Enter the cost of the second item: ";
  std::cin >> itemCost2;
  std::cout << "Enter the cost of the third item: ";
  std::cin >> itemCost3;

  double totalCost = itemCost1 + itemCost2 + itemCost3;

  if (totalCost > 10000)
  {
    discount = 10.0;
    std::cout << "\nSince your check amount exceeds 10,000 rubles, you are given a 10% discount..\n";
    discountAmount = discount / 100 * totalCost;
    std::cout << "Discount: " << discountAmount << '\n';
  }

  double finalPrice = totalCost - discountAmount;
  std::cout << "\nTotal amount to be paid: " << finalPrice << '\n';

  return 0;
}










//Задача 2. Автомобиль.

#include <iostream>

int main()
{
  int speedKmph;
  std::cout << "Enter the vehicle speed: ";
  std::cin >> speedKmph;

  int targetDistanceKm = 200;
  int timeH = 2;
  int travelledDistanceKm = speedKmph * timeH;

  if (travelledDistanceKm >= targetDistanceKm)
  {
    std::cout << "You have arrived!" << '\n';
    std::cout << "Welcome to Ryazan!" << '\n';
  }
  else
  {
    int distanceLeftKm = targetDistanceKm - travelledDistanceKm;
    std::cout << distanceLeftKm << " km to Ryazan.\n";
  }

  return 0;
}










//Задача 3. Модуль числа.

#include <iostream>

int main()
{
  int x;
  std::cout << "Enter a number: ";
  std::cin >> x;

  if (x < 0)
  {
    x = -x;
  }
  std::cout << "The modulus of the number is: " << x << '\n';

  return 0;
}










//Задача 4. Барберы

#include <iostream>

int main()
{
  std::cout << "Let's find out if you have enough barbers in your city.\n";
  std::cout << "How many men live in the city? ";
  int men;
  std::cin >> men;
  std::cout << "How many barbers are already working in the city? ";
  int barbers;
  std::cin >> barbers;
  
  int term = 30;
  int cutsPerBarber = 8;
  
  int barbersRequired;
  if (men % (term * cutsPerBarber) == 0)
  {
    barbersRequired = men / (term * cutsPerBarber);
  }
  else
  {
    barbersRequired = men / (term * cutsPerBarber) + 1;
  }

  std::cout << "Number of barbers required: " << barbersRequired << '\n';
  
  if (barbers < barbersRequired)
  {
    std::cout << "There are not enough barbers!" << '\n';
    std::cout << "You need to hire " << barbersRequired - barbers << " barbers.\n";
  }
  else
  {
    std::cout << "There are enough barbers!" << '\n';
  }

  return 0;
}










//Практическая работа

//Задание 1. Минимум из двух чисел

#include <iostream>

int main()
{
  std::cout << "Let's compare two numbers.\n";
  std::cout << "Enter the first number: ";
  int number1;
  std::cin >> number1;

  std::cout << "Enter the second number: ";
  int number2;
  std::cin >> number2;

  if (number1 < number2)
  {
    std::cout << "The smallest number: " << number1 << "\n";
  }
  else if (number2 < number1)
  {
    std::cout << "The smallest number: " << number2 << "\n";
  }
  else
  {
    std::cout << "The numbers are equal!\n";
  }

  return 0;
}










//Задание 2. Складываем в уме

#include <iostream>

int main()
{
  std::cout << "Can you add numbers in your mind? Test yourself!\n";
  std::cout << "Enter the first number: ";
  int number1;
  std::cin >> number1;
  std::cout << "Enter the second number: ";
  int number2;
  std::cin >> number2;
  std::cout << "Enter the sum: ";
  int sum;
  std::cin >> sum;
  std::cout << "-----Checking-----\n";
  int correctAnswer = number1 + number2;
  if (sum == correctAnswer)
  {
    std::cout << "Correct!\n";
  }
  else
  {
    std::cout << "Error! Correct answer: " << correctAnswer << "\n";
  }

  return 0;
}










//Задание 3. Проверка на чётное число

#include <iostream>

int main()
{
  std::cout << "Find out if a number is even or odd?\n";
  std::cout << "Enter a number: ";
  int number;
  std::cin >> number;
  int remainder = number % 2;
  std::cout << "-----Checking-----\n";
  if (remainder == 0)
  {
    std::cout << "Number " << number << " is even";
  }
  else
  {
    std::cout << "Number " << number << " is odd";
  }

  return 0;
}










//Задание 4. Калькулятор опыта

#include <iostream>
#include <cassert>

int main()
{
  std::cout << "Find out the character level in the game!\n";
  int playerLevel = 1;
  int experiencePoints;
  std::cout << "Enter the number of experience points: ";
  std::cin >> experiencePoints;
  std::cout << "-----Calculating-----\n";
  assert(experiencePoints >= 0);
  if (experiencePoints < 1000)
  {
  }
  else if (experiencePoints >= 1000 && experiencePoints < 2500)
  {
    playerLevel = 2;
  }
  else if (experiencePoints >= 2500 && experiencePoints < 5000)
  {
    playerLevel = 3;
  }
  else if (experiencePoints >= 5000)
  {
    playerLevel = 4;
  }
  std::cout << "Your level: " << playerLevel << '\n';

  return 0;
}










//Задание 5. Кратность числа

#include <iostream>
#include <cassert>

int main()
{
  std::cout << "Find out if one number is divisible by another without a remainder.\n";
  std::cout << "Enter the first number: ";
  int dividend;
  std::cin >> dividend;
  std::cout << "Enter the second number: ";
  int divisor;
  std::cin >> divisor;
  assert(divisor != 0);
  std::cout << "-----Checking-----\n";
  int remainder = dividend % divisor;
  if (remainder == 0)
  {
    std::cout << "Yes, " << dividend << " is divisible by " << divisor << " without a remainder!\n";
  }
  else
  {
    std::cout << "No, " << dividend << " is not divisible by " << divisor << " without a remainder!\n";
  }

  return 0;
}











//Задание 6. Улучшим Барберов

#include <iostream>

int main()
{
  std::cout << "Let's find out if you have enough barbers in your city.\n";
  std::cout << "How many men live in the city? ";
  int men;
  std::cin >> men;
  std::cout << "How many barbers are already working in the city? ";
  int barbers;
  std::cin >> barbers;
  
  int term = 30;
  int cutsPerBarber = 8;
  
  int barbersRequired;
  if (men % (term * cutsPerBarber) == 0)
  {
    barbersRequired = men / (term * cutsPerBarber);
  }
  else
  {
    barbersRequired = men / (term * cutsPerBarber) + 1;
  }

  std::cout << "Number of barbers required: " << barbersRequired << '\n';
  
  if (barbers < barbersRequired)
  {
    std::cout << "There are not enough barbers!" << '\n';
    std::cout << "You need to hire " << barbersRequired - barbers << " barbers.\n";
  }
  else
  {
    std::cout << "There are enough barbers!" << '\n';
  }

  return 0;
}










//Задание 7. Меню ресторана

#include <iostream>
#include <string>

int main()
{
  std::cout << "*****Business-lunch*****\n";
  std::cout << "See the menu for today!\n";
  std::cout << "Enter the day of the week (from 1 to 7): ";
  int day;
  std::cin >> day;
  
  std::string drink = "Drink (tea, coffee, mors)";
  
  std::string firstDish1 = "Chicken noodle soup";
  std::string mainDish1 = "Turkey meatballs with vegetables";

  std::string firstDish2 = "Fish solyanka";
  std::string mainDish2 = "Pike perch in sour cream sauce with mashed potatoes";

  std::string firstDish3 = "Cabbage soup with beef";
  std::string mainDish3 = "Beef goulash and buckwheat with onions";

  std::string firstDish4 = "The Volga ukha";
  std::string mainDish4 = "Perch fillet with bulgur and zucchini";

  std::string firstDish5 = "Minestrone with chicken meatballs";
  std::string mainDish5 = "Chicken kebab with rice and white wine sauce";

  std::string firstDish6 = "Tom yam with rice";
  std::string mainDish6 = "Crab patties with mashed potatoes";

  std::string firstDish7 = "Sorrel soup with chicken and egg";
  std::string mainDish7 = "Beef cabbage roll with sour cream";

  if (day == 1)
  {
    std::cout << "Today's menu (Monday):\n";
    std::cout << firstDish1 << '\n';
    std::cout << mainDish1 << '\n';
  }

  if (day == 2)
    {
      std::cout << "Today's menu (Tuesday):\n";
      std::cout << firstDish2 << '\n';
      std::cout << mainDish2 << '\n';
    }

  if (day == 3)
    {
      std::cout << "Today's menu (Wednesday):\n";
      std::cout << firstDish3 << '\n';
      std::cout << mainDish3 << '\n';
    }

  if (day == 4)
    {
      std::cout << "Today's menu (Thursday):\n";
      std::cout << firstDish4 << '\n';
      std::cout << mainDish4 << '\n';
    }

  if (day == 5)
    {
      std::cout << "Today's menu (Friday):\n";
      std::cout << firstDish5 << '\n';
      std::cout << mainDish5 << '\n';
    }

  if (day == 6)
    {
      std::cout << "Today's menu (Saturday):\n";
      std::cout << firstDish6 << '\n';
      std::cout << mainDish6 << '\n';
    }

  if (day == 7)
    {
      std::cout << "Today's menu (Sunday):\n";
      std::cout << firstDish7 << '\n';
      std::cout << mainDish7 << '\n';
    }
    std::cout << drink << '\n';
  

  

  return 0;
}





