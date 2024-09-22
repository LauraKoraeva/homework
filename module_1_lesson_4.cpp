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
  std::cout << "Давайте вычислим сумму чека.\n";
  std::cout << "Введите стоимость первого товара: ";
  std::cin >> itemCost1;
  std::cout << "Введите стоимость второго товара: ";
  std::cin >> itemCost2;
  std::cout << "Введите стоимость третьего товара: ";
  std::cin >> itemCost3;

  double totalCost = itemCost1 + itemCost2 + itemCost3;

  if (totalCost > 10000)
  {
    discount = 10.0;
    std::cout << "\nТак как сумма вашего чека превышает 10 000 руб, вам сделана скидка 10%.\n";
    discountAmount = discount / 100 * totalCost;
    std::cout << "Скидка: " << discountAmount << '\n';
  }

  double finalPrice = totalCost - discountAmount;
  std::cout << "\nИтого к оплате: " << finalPrice << '\n';

  return 0;
}










//Задача 2. Автомобиль.

#include <iostream>

int main()
{
  int speedKmph;
  std::cout << "Введите скорость движения автомобиля: ";
  std::cin >> speedKmph;

  int targetDistanceKm = 200;
  int timeH = 2;
  int travelledDistanceKm = speedKmph * timeH;

  if (travelledDistanceKm >= targetDistanceKm)
  {
    std::cout << "Вы приехали!" << '\n';
    std::cout << "Добро пожаловать в Рязань!" << '\n';
  }
  else
  {
    int distanceLeftKm = targetDistanceKm - travelledDistanceKm;
    std::cout << "До рязани " << distanceLeftKm << " км." << '\n';
  }

  return 0;
}










//Задача 3. Модуль числа.

#include <iostream>

int main()
{
  int x;
  std::cout << "Введите число: ";
  std::cin >> x;

  if (x < 0)
  {
    x = -x;
  }
  std::cout << "Модуль числа равен: " << x << '\n';

  return 0;
}










//Задача 4. Барберы

#include <iostream>

int main()
{
  std::cout << "Давай узнаем, достаточно ли у вас барберов в городе.\n";
  std::cout << "Сколько мужчин проживает в городе? ";
  int men;
  std::cin >> men;
  std::cout << "Сколько барберов уже работает в городе? ";
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

  std::cout << "Необходимое число барберов: " << barbersRequired << '\n';
  
  if (barbers < barbersRequired)
  {
    std::cout << "Барберов недостаточно!" << '\n';
    std::cout << "Необходимо нанять ещё " << barbersRequired - barbers << ".\n";
  }
  else
  {
    std::cout << "Барберов достаточно!" << '\n';
  }

  return 0;
}










//Практическая работа

//Задание 1. Минимум из двух чисел

#include <iostream>

int main()
{
  std::cout << "Сравним два числа.\n";
  std::cout << "Введите первое число: ";
  int number1;
  std::cin >> number1;

  std::cout << "Введите второе число: ";
  int number2;
  std::cin >> number2;

  if (number1 < number2)
  {
    std::cout << "Наименьшее число: " << number1 << "\n";
  }
  else if (number2 < number1)
  {
    std::cout << "Наименьшее число: " << number2 << "\n";
  }
  else
  {
    std::cout << "Числа равны!\n";
  }

  return 0;
}










//Задание 2. Складываем в уме

#include <iostream>

int main()
{
  std::cout << "Ты умеешь складывать числа в уме? Проверь себя!\n";
  std::cout << "Введи первое число: ";
  int number1;
  std::cin >> number1;
  std::cout << "Введи второе число: ";
  int number2;
  std::cin >> number2;
  std::cout << "Введи их сумму: ";
  int sum;
  std::cin >> sum;
  std::cout << "-----Проверяем-----\n";
  int correctAnswer = number1 + number2;
  if (sum == correctAnswer)
  {
    std::cout << "Верно!\n";
  }
  else
  {
    std::cout << "Ошибка! Верный результат: " << correctAnswer << "\n";
  }

  return 0;
}










//Задание 3. Проверка на чётное число

#include <iostream>

int main()
{
  std::cout << "Узнайте, чётное или нечётное число?\n";
  std::cout << "Введите число: ";
  int number;
  std::cin >> number;
  int remainder = number % 2;
  std::cout << "-----Проверяем-----\n";
  if (remainder == 0)
  {
    std::cout << "Число " << number << " - чётное";
  }
  else
  {
    std::cout << "Число " << number << " - нечётное";
  }

  return 0;
}










//Задание 4. Калькулятор опыта

#include <iostream>
#include <cassert>

int main()
{
  std::cout << "Узнайте уровень персонажа в игре!\n";
  int playerLevel = 1;
  int experiencePoints;
  std::cout << "Введите число очков опыта: ";
  std::cin >> experiencePoints;
  std::cout << "-----Считаем-----\n";
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
  std::cout << "Ваш уровень: " << playerLevel << '\n';

  return 0;
}










//Задание 5. Кратность числа

#include <iostream>
#include <cassert>

int main()
{
  std::cout << "Узнайте, делится ли одно число на другое без остатка.\n";
  std::cout << "Введите первое число: ";
  int dividend;
  std::cin >> dividend;
  std::cout << "Введите второе число: ";
  int divisor;
  std::cin >> divisor;
  assert(divisor != 0);
  std::cout << "-----Проверяем-----\n";
  int remainder = dividend % divisor;
  if (remainder == 0)
  {
    std::cout << "Да, " << dividend << " делится на " << divisor << " без остатка!\n";
  }
  else
  {
    std::cout << "Нет, " << dividend << " не делится на " << divisor << " без остатка!\n";
  }

  return 0;
}











//Задание 6. Улучшим Барберов

#include <iostream>

int main()
{
  std::cout << "Давай узнаем, достаточно ли у вас барберов в городе.\n";
  std::cout << "Сколько мужчин проживает в городе? ";
  int men;
  std::cin >> men;
  std::cout << "Сколько барберов уже работает в городе? ";
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

  std::cout << "Необходимое число барберов: " << barbersRequired << '\n';
  
  if (barbers < barbersRequired)
  {
    std::cout << "Барберов недостаточно!" << '\n';
    std::cout << "Необходимо нанять ещё " << barbersRequired - barbers << ".\n";
  }
  else
  {
    std::cout << "Барберов достаточно!" << '\n';
  }

  return 0;
}










//Задание 7. Меню ресторана

#include <iostream>
#include <string>

int main()
{
  std::cout << "*****Бизнес-ланч*****\n";
  std::cout << "Узнайте меню на сегодня!\n";
  std::cout << "Введите день недели (от 1 до 7): ";
  int day;
  std::cin >> day;
  
  std::string drink = "Напиток (чай, кофе, морс)";
  
  std::string firstDish1 = "Куриный суп лапша";
  std::string mainDish1 = "Котлеты из индейки с овощами";

  std::string firstDish2 = "Рыбная солянка";
  std::string mainDish2 = "Судак в сметанном соусе с пюре";

  std::string firstDish3 = "Щи из молодой капусты с говядиной";
  std::string mainDish3 = "Гуляш из говядины и гречка с луком";

  std::string firstDish4 = "Уха волжская";
  std::string mainDish4 = "Филе окуня с булгуром и кабачками";

  std::string firstDish5 = "Минестроне с куриными фрикадельками";
  std::string mainDish5 = "Шашлык из курицы с рисом и соусом белое вино";

  std::string firstDish6 = "Том ям с рисом";
  std::string mainDish6 = "Крабовые котлеты с пюре из картофеля";

  std::string firstDish7 = "Щавелевый суп с курицей и яйцом";
  std::string mainDish7 = "Голубцы из говядины со сметаной";

  if (day == 1)
  {
    std::cout << "Меню сегодня (понедельник):\n";
    std::cout << firstDish1 << '\n';
    std::cout << mainDish1 << '\n';
  }

  if (day == 2)
    {
      std::cout << "Меню сегодня (вторник):\n";
      std::cout << firstDish2 << '\n';
      std::cout << mainDish2 << '\n';
    }

  if (day == 3)
    {
      std::cout << "Меню сегодня (среда):\n";
      std::cout << firstDish3 << '\n';
      std::cout << mainDish3 << '\n';
    }

  if (day == 4)
    {
      std::cout << "Меню сегодня (четверг):\n";
      std::cout << firstDish4 << '\n';
      std::cout << mainDish4 << '\n';
    }

  if (day == 5)
    {
      std::cout << "Меню сегодня (пятница):\n";
      std::cout << firstDish5 << '\n';
      std::cout << mainDish5 << '\n';
    }

  if (day == 6)
    {
      std::cout << "Меню сегодня (суббота):\n";
      std::cout << firstDish6 << '\n';
      std::cout << mainDish6 << '\n';
    }

  if (day == 7)
    {
      std::cout << "Меню сегодня (воскресенье):\n";
      std::cout << firstDish7 << '\n';
      std::cout << mainDish7 << '\n';
    }
    std::cout << drink << '\n';
  

  

  return 0;
}





