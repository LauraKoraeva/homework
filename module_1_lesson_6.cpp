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
    std::cout << "Enter reminder text: ";
    std::string reminderText;
    std::getline(std::cin, reminderText);

    std::cout << "Enter the number of reminders: ";
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
    std::cout << "Enter four numbers: \n";
    int number1, number2, number3, number4;
    std::cin >> number1 >> number2 >> number3 >> number4;

    while (number1 + number2 + number3 + number4 != 42)
    {
        std::cout << "The input is incorrect, please try again.\n";
        std::cin >> number1 >> number2 >> number3 >> number4;
    }

    std::cout << "The input is correct.\n";
    return 0;
}













//Задача 6. Сумма чисел.
#include <iostream>

int main()
{
    std::cout << "How many numbers do you want to add up: ";
    int numbersCount;
    std::cin >> numbersCount;
    int inputCounts = 1;
    int sum = 0;
    while (inputCounts <= numbersCount)
    {
        std::cout << "Enter number " << inputCounts << ": ";
        int number;
        std::cin >> number;
        sum += number;
        ++inputCounts;
    }
    std::cout << "The sum of the entered numbers: " << sum << '\n';

    return 0;
}












//Применение цикла while. Инструкция break

//Задача 1. Банкомат 4.0.
#include <iostream>

int main()
{
    std::cout << "Enter the PIN code: ";
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
        std::cout << "Correct input.\n";
    else
        std::cout << "Incorrect input.\n";

    return 0;
}









//Задача 2. Кадастровые проблемы.
#include <iostream>

int main()
{
    std::cout << "Enter the area of the plot: ";
    int square;
    std::cin >> square;

    int count = 1;
    while (count * count < square)
        ++count;
    
    if (count * count == square)
        std::cout << "The area is a perfect square.\n";
    else
        std::cout << "The area is not a perfect square.\n";

    return 0;
}











//Задача 3. Кожаный мешок.
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    bool found = false;
    while (number != 0 && !found)
    {
        found = number % 10 > 1;
        number /= 10;
    }

    if (found)
        std::cout << "The number does not consist only of 0 and 1.\n";
    else
        std::cout << "The number consists only of 0 and 1.\n";
    return 0;
}











//Задача 4. Военное время.

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    int result = 0;
    while (number != 0)
    {
        result = result * 10 + number % 10;
        number /= 10;
    }
    std::cout << result << '\n';

    return 0;
}











//Практическая работа

//Задание 1. Кукушка
#include <iostream>

int main()
{
    std::cout << "Enter the time: ";
    int hour;
    std::cin >> hour;

    while (hour <= 0 || hour > 12)
    {
        std::cout << "Time must be between 1 and 12. Enter the time: ";
        std::cin >> hour;
    }

    int count = 0;
    while (count < hour)
    {
        std::cout << "Peek-a-boo!\n";
        ++count;
    }

    return 0;
}










//Задание 2. Слишком большие числа
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
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
    std::cout << "Digits in the number: " << count << '\n';

    return 0;
}









//Задание 3. Коллекторы
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter the name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter the amount of debt: ";
    int debt;
    std::cin >> debt;
    
    if (debt < 0)  
        std::cout << "The amount of debt cannot be negative! \n";
    else 
    {
        while (debt > 0)
        {
            std::cout << "Enter the payment amount: ";
            int payment;
            std::cin >> payment;
            debt -= payment;
            if (debt > 0)
                std::cout << "The amount of debt: " << debt << '\n';
        }

        std::cout << "The debt has been fully repaid.\n";
        if (debt != 0)
        {
            int balance = -debt;
            std::cout << "Account balance: " << balance << '\n';
        }
    }
    return 0;
}








//Задание 4. Счастливый билетик
#include <iostream>

int main()
{
    std::cout << "Enter the ticket number: ";
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
        std::cout << "The number of digits in the ticket number must be even.";
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
        std::cout << "The ticket is a lucky one!\n";
    else
        std::cout << "Better luck next time!\n";
    }
    return 0;
}






//Задание 5. Числа Фибоначчи

#include <iostream>

int main()
{
    std::cout << "Enter the number of the number from the Fibonacci sequence: ";
    int number;
    std::cin >> number;

    int number_1 = 1;
    int number_2 = 1;
    int currentNumber = 0;

    if (number <= 0 || number > 46)
        std::cout << "The number cannot be negative, or equal to zero, or greater than 46.";
    else if (number == 1 || number == 2)
    {
        std::cout << number_1;
    }

    else
    {
        int count = 3;
        while (count <= number)
        {
            currentNumber = number_1 + number_2;

            number_1 = number_2;
            number_2 = currentNumber;
            ++count;
        }
        std::cout << currentNumber << '\n';
    }

    return 0;
}






//Задание 6. Вклады

#include <iostream>

int main()
{
    std::cout << "Enter the deposit amount: ";
    int deposit;
    std::cin >> deposit;

    std::cout << "Enter the interest rate: ";
    int rate;
    std::cin >> rate;

    std::cout << "Enter the desired amount: ";
    int desiredAmount;
    std::cin >> desiredAmount;

    int yearsCount = 0;

    while (deposit < desiredAmount)
    {
        deposit = deposit + ((rate * deposit) / 100);
        ++yearsCount;
    }

    std::cout << "You'll have to wait: " << yearsCount << " years\n";

    return 0;
}
