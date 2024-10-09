/*Основы программирования на C++
  Урок 5. Логические операторы и сложные условия
*/

//Вложенные конструкции if

//Задача 1. Координатная плоскость.

#include <iostream>


int main()
{
  int x, y;
  std::cout << "Введите координаты X и Y: ";
  std::cin >> x >> y;

  if (x > 0)
  {
    if (y > 0)
      std::cout << "Точка находится в первой четверти";
    else if (y < 0)
      std::cout << "Точка находится в четвертой четверти";
    if (y == 0)
      std::cout << "Точка находится на оси X";
  }
  else if (x < 0)
  {
    if (y > 0)
      std::cout << "Точка находится во второй четверти";
    else if (y < 0)
      std::cout << "Точка находится в третьей четверти";
    else if (y == 0)
      std::cout << "Точка находится на оси X";
  }
  else if (x == 0)
    std::cout << "Точка находится на оси Y";
  
  return 0;
}









//Задача 2. Банкомат.

#include <iostream>


int main()
{
  std::cout << "Введите сумму для снятия: ";
  int sum;
  std::cin >> sum;
  if (sum < 100000)
  {
    if (sum % 100 == 0)
      std::cout << "Сумма допустима для снятия.";
    else
      std::cout << "Сумма не допустима для снятия.";
  }
  else
    std::cout << "Сумма не допустима для снятия.";
  
  return 0;
}










//Логические операторы и сложные условия

//Задача 1.

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










//Задача 2. Мост и перегрузка.
#include <iostream>


int main()
{
  int car1, car2, car3, car4;
  std::cout << "Введите массу первой машины: ";
  std::cin >> car1;
  std::cout << "Введите массу второй машины: ";
  std::cin >> car2;
  std::cout << "Введите массу третьей машины: ";
  std::cin >> car3;
  std::cout << "Введите массу четвертой машины: ";
  std::cin >> car4;

  int maxWeight = 1200;

  if (car1 > maxWeight || car2 > maxWeight || car3 > maxWeight || car4 > maxWeight)
    std::cout << "Масса одной из машин превышает 1200 кг.\n";
  else
    std::cout << "Масса всех машин меньше 1200 кг.\n";
  
  return 0;
}










//Задача 3. Треугольник.

#include <iostream>


int main()
{
  std::cout << "Введите длины трех сторон треугольника: ";
  int a, b, c;
  std::cin >> a >> b >> c;

  if (a + b <= c || a + c <= b || b + c <= a)
    std::cout << "Треугольник не получится.";
  else
    std::cout << "Треугольник получится.";
  
  return 0;
}










//Упрощение логических выражений. Приоритеты операторов

//Задача 1. Военкомат.
#include <iostream>
#include <string>

int main()
{
  int height;
  int weight;
  int hands;
  int legs;
  int flightHours;
  std::string eyeColour;

  std::cout << "Введите рост: ";
  std::cin >> height;
  std::cout << "Введите вес: ";
  std::cin >> weight;
  std::cout << "Введите количество рук: ";
  std::cin >> hands;
  std::cout << "Введите количество ног: ";
  std::cin >> legs;
  std::cout << "Введите количество часов налета: ";
  std::cin >> flightHours;
  std::cout << "Введите цвет глаз: ";
  std::cin >> eyeColour;

  if ((height >= 145 && height < 165) && (weight >= 45 && weight < 65) && (legs == hands) && (flightHours > 100) && (eyeColour != "green"))
    std::cout << "Годен!" << '\n';
  else
    std::cout << "Не годен!" << '\n';

  return 0;
}










//Задача 2. — Входит... И выходит... И входит... Замечательно выходит! "Винни-Пух и день забот".
#include <iostream>

int main()
{
  int length;
  int width;
  int height;
  std::cout << "Введите размеры кирпича: \n";
  std::cin >> length >> width >> height;

  int x;
  int y;
  std::cout << "Введите размеры отверстия: \n";
  std::cin >> x >> y;

  if ((length <= x && width <= y || length <= y && width <= x) || (length <= x && height <= y || length <= y && height <= x) || (width <= x && height <= y || width <= y && height <= x))
    std::cout << "Ура!Можно дарить Иа!";
  else
    std::cout << "Нет, не получится подарить Иа!";
    

  return 0;
}









//Практическая работа

//Задание 1. Полёт нормальный!

#include <iostream>

int main()
{
  int speed;
  int altitude;
  
  std::cout << "Введите скорость самолёта: ";
  std::cin >> speed;
  std::cout << "Введите высоту полёта самолёта: ";
  std::cin >> altitude;

  if (speed >= 750 && speed <= 850 && altitude >= 9000 && altitude <= 9500)
    std::cout << "Самолёт летит правильным эшелоном";
  else
    std::cout << "Самолёт летит неправильным эшелоном";
    
  return 0;
}










//Задание 2. Майские

#include <iostream>

int main()
{
  std::cout << "Enter date: ";
  int date;
  std::cin >> date;

  if (date >= 1 && date <= 5 || date >= 8 && date <= 10)
    std::cout << "Weekend!";
  else
    if (date % 7 == 0 || (date + 1) % 7 == 0)
    {
      std::cout << "Weekend!";
    }
    else
      std::cout << "Working day!";
  return 0;
}










//Задание 3. Майские — усложнение

#include <iostream>

int main()
{
  std::cout << "Enter date: ";
  int date;
  std::cin >> date;

  std::cout << "Enter day of the week number: ";
  int weekDay;
  std::cin >> weekDay;

  int diff;
  if (weekDay == 1)
    diff = 0;
  else
    diff = weekDay - 1;

  if (date >= 1 && date <= 5 || date >= 8 && date <= 10)
    std::cout << "Weekend!";
  else
    if ((date + diff) % 7 == 0 || (date + diff + 1) % 7 == 0)
    {
      std::cout << "Weekend!";
    }
    else
      std::cout << "Working day!";
  return 0;
}










//Задание 4. Банкомат — 2

#include <iostream>

int main()
{
  int banknote_5000;
  int banknote_2000;
  int banknote_1000;
  int banknote_500;
  int banknote_200;
  int banknote_100;
  int sum;
  std::cout << "Enter sum: ";
  std::cin >> sum;

  if ((sum % 100 != 0) || (sum > 150000))
  {
    std::cout << "Error!";
  }
  else
  {
    if (sum >= 5000)
    {
      banknote_5000 = sum / 5000;
      std::cout << banknote_5000 << " - 5000, ";
      sum -= (5000 * banknote_5000);
    }
    if (sum >= 2000)
    {
      banknote_2000 = sum / 2000;
      std::cout << banknote_2000 << " - 2000, ";
      sum -= (2000 * banknote_2000);
    }
    if (sum >= 1000)
    {
      banknote_1000 = sum / 1000;
      std::cout << banknote_1000 << " - 1000, ";
      sum -= (1000 * banknote_1000);
    }
    if (sum >= 500)
    {
      banknote_500 = sum / 500;
      std::cout << banknote_500 << " - 500, ";
      sum -= (500 * banknote_500);
    }
    if (sum >= 200)
    {
      banknote_200 = sum / 200;
      std::cout << banknote_200 << " - 200, ";
      sum -= (200 * banknote_200);
    }
    if (sum >= 100)
    {
      banknote_100 = sum / 100;
      std::cout << banknote_100 << " - 100, ";
      sum -= (200 * banknote_100);
    }
  }
    return 0;
}










//Задание 5. Усложнение задачи про кирпич

#include <iostream>

int main()
{
    std::cout << "Find out whether the first box fits into the second one.\n";
    std::cout << "Enter length, width and height of the first box:\n";
    int l_1, w_1, h_1;
    std::cin >> l_1 >> w_1 >> h_1;

    std::cout << "Enter length, width and height of the second box:\n";
    int l_2, w_2, h_2;
    std::cin >> l_2 >> w_2 >> h_2;

    if (l_1 <= l_2 && l_1 <= w_2 && l_1 <= h_2 && w_1 <= l_2 && w_1 <= w_2 &&
        w_1 <= h_2 && h_1 <= l_2 && h_1 <= w_2 && h_1 <= h_2)
        std::cout << "The first box fits into the second box.\n";
    else
        std::cout << "The first box does not fit into the second box.\n";

    return 0;
}










//Задание 6. Грустное совершеннолетие

#include <iostream>

int main()
{
    int day;
    int month;
    int year;
    std::cout << "Enter today's date [dd mm yyyy]:\n";
    std::cin >> day;
    std::cin >> month;
    std::cin >> year;
   
    int birthDay;
    int birthMonth;
    int birthYear;
    std::cout << "Enter customer's birthday [dd mm yyyy]:\n";
    std::cin >> birthDay;
    std::cin >> birthMonth;
    std::cin >> birthYear;
   
    int age = year - birthYear;
   
    if ((age > 18) || (age == 18 && month > birthMonth) || (age == 18 && month == birthMonth && day > birthDay))
        std::cout << "You can sell beer to this customer.\n";
    else
        std::cout << "You can't sell beer to this customer.\n";
       
    return 0;
}







