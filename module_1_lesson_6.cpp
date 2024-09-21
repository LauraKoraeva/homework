/*Основы программирования на C++
  Урок 6. Введение в циклы: while, do while, break
*/

//Циклы while, do while
//Задача 1. Начальник.
#include <iostream>
#include <string>

int main()
{
  std::string answer;

  do {
    std::cout << "Ты сделал задание? ";
    std::getline(std::cin, answer);
  } while (answer != "Да, конечно, сделал");

  return 0;
}

//Задача 2. Купи слона.

#include <iostream>

int main()
{
    std::cout << "Как тебя зовут? \n";
    std::string name;
    std::getline(std::cin, name);
    std::cout << name << ", купи слона!\n";
    std::string answer;
    std::getline(std::cin, answer);
    
  while (1 > 0)
    {
    std::cout << "Все говорят \"" << answer << "\", а ты купи слона!\n";
      std::getline(std::cin, answer);
    }

    return 0;
}

//Задача 3. Таблица степеней.
#include <iostream>

int main()
{
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    std::cout << "Сколько раз умножить? ";
    int resultCount;
    std::cin >> resultCount;
    
    int result = number;
    std::cout << result * 1 << ", ";
    
    int count = 0;
    while (count < resultCount)
    {
       result = result * number;
        std::cout << result<< ", ";
        ++count;
    }

    return 0;
}

//Задача 4. Напоминалка.
#include <iostream>
#include <string>

int main()
{
    std::cout << "Введите текст напоминания: ";
    std::string reminderText;
    std::getline(std::cin, reminderText);

    std::cout << "Введите количество напоминаний: ";
    int reminderCount;
    std::cin >> reminderCount;

    int count = 1;
    while (count <= reminderCount)
    {
        std::cout << count << ". " << reminderText << '\n';
        ++count;
    }

    return 0;
}

//Задача 5. Банкомат 3.0.
#include <iostream>

int main()
{
    std::cout << "Введите четыре числа: \n";
    int number1, number2, number3, number4;
    std::cin >> number1 >> number2 >> number3 >> number4;

    while (number1 + number2 + number3 + number4 != 42)
    {
        std::cout << "Ввод некорректный, попробуйте еще раз.\n";
        std::cin >> number1 >> number2 >> number3 >> number4;
    }

    std::cout << "Ввод корректный.\n";
    return 0;
}

//Задача 6. Сумма чисел.
#include <iostream>

int main()
{
    std::cout << "Сколько чисел вы хотите сложить: ";
    int numbersCount;
    std::cin >> numbersCount;
    int inputCounts = 1;
    int sum = 0;
    while (inputCounts <= numbersCount)
    {
        std::cout << "Введите число " << inputCounts << ": ";
        int number;
        std::cin >> number;
        sum += number;
        ++inputCounts;
    }
    std::cout << "Сумма введенных чисел: " << sum << '\n';

    return 0;
}

//Применение цикла while. Инструкция break
//Задача 1. Банкомат 4.0.
#include <iostream>

int main()
{
    std::cout << "Введите пин-код: ";
    int pinCode;
    std::cin >> pinCode;
    int sum = 0;
    int lastDigit;

    while (pinCode != 0)
    {
        lastDigit = pinCode % 10;
        sum += lastDigit;
        pinCode /= 10;
    }

    if (sum == 42)
        std::cout << "Ввод корректный.\n";
    else
        std::cout << "Ввод некорректный.\n";

    return 0;
}








//Задача 3. Кожаный мешок.
#include <iostream>

int main()
{
    std::cout << "Введите число: ";
    int number;
    std::cin >> number;
    
    int count = 0;
    while (number != 0)
    {
        int digit = number % 10;
        
        if (digit != 0 && digit != 1)
        {
            ++count;
            break;
        }
        
        number /= 10;
    }

    if (count > 0)
        std::cout << "Число состоит не только из 0 и 1.\n";
    else
        std::cout << "Число состоит только из 0 и 1.\n";
    return 0;
}








//Практическая работа
//Задание 1. Кукушка
#include <iostream>

int main()
{
    std::cout << "Введите, который час: ";
    int hour;
    std::cin >> hour;

    while (hour <= 0 || hour > 12)
    {
        std::cout << "Время должно быть в диапазоне от 1 до 12. Введите, который час: ";
        std::cin >> hour;
    }

    int count = 0;
    while (count < hour)
    {
        std::cout << "Ку-ку!\n";
        ++count;
    }

    return 0;
}


//Практическая работа
//Задание 2. Слишком большие числа
#include <iostream>

int main()
{
    std::cout << "Введите число: ";
    int number;
    std::cin >> number;
    int count = 0;
    if (number != 0)
    {
        while (number != 0)
        {
            number /= 10;
            ++count;
        }
    }
    else
        count = 1;
    std::cout << "Цифр в числе: " << count << '\n';

    return 0;
}

//Практическая работа
//Задание 3. Коллекторы
#include <iostream>
#include <string>

int main()
{
    std::cout << "Введите имя: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Введите сумму долга: ";
    int debt;
    std::cin >> debt;
    
    if (debt < 0)  
        std::cout << "Сумма долга не может быть отрицательной! \n";
    else 
    {
        while (debt > 0)
        {
            std::cout << "Введите сумму платежа: ";
            int payment;
            std::cin >> payment;
            debt -= payment;
            if (debt > 0)
                std::cout << "Сумма долга: " << debt << '\n';
        }

        std::cout << "Долг полностью погашен.\n";
        if (debt != 0)
        {
            int balance = -debt;
            std::cout << "Остаток на счету: " << balance << '\n';
        }
    }
    return 0;
}

//Практическая работа
//Задание 4. Счастливый билетик
#include <iostream>

int main()
{
    std::cout << "Введите номер билета: ";
    int ticketNumber;
    std::cin >> ticketNumber;
    
    int tempTicketNumber = ticketNumber;
    int digitCount = 0;
    while (tempTicketNumber != 0)
    {
        tempTicketNumber /= 10;
        ++digitCount;
    }
    if (digitCount % 2 != 0 || tempTicketNumber == 0)
        std::cout << "Количество цифр в номере билета должно быть четным.";
    else
    {
    int iterationCount = digitCount / 2;    
    int sumRight = 0;
    int sumLeft = 0;
    int countRight = 0;
    int countLeft = 0;
    while (countRight < iterationCount)
    {
        int digit = ticketNumber % 10;
        sumRight = sumRight + digit;
        ticketNumber /= 10;
        ++countRight;
    }
    while (countLeft < iterationCount)
    {
        int digit = ticketNumber % 10;
        sumLeft += digit;
        ticketNumber /= 10;
        ++countLeft;
    }
    if (sumRight == sumLeft)
        std::cout << "Билет счастливый!\n";
    else
        std::cout << "Повезёт в следующий раз!!\n";
    }
    return 0;
}
