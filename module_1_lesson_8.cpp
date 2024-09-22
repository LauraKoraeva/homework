//Задача 1. Орехи

#include <iostream>

int main()
{
    std::cout << "Введите цену товара за 100 грамм: ";
    float fixedPrice;
    std::cin >> fixedPrice;

    std::cout << "Введите вес покупки: ";
    float productAmount;
    std::cin >> productAmount;

    float finalCost = fixedPrice / 100 * productAmount;
    std::cout << "Стоимость покупки: " << finalCost;


    return 0;
}










//Задача 2. ЗОЖ
#include <iostream>

int main()
{
    std::cout << "Введите количество белков на 100 грамм продукта: ";
    float protein;
    std::cin >> protein;

    std::cout << "Введите количество углеводов на 100 грамм продукта: ";
    float carbs;
    std::cin >> carbs;

    std::cout << "Введите массу нетто продукта: ";
    float netWeight;
    std::cin >> netWeight;

    float proteinPerServing = netWeight / 100 * protein;
    float carbsPerServing = netWeight / 100 * carbs;

    std::cout << '\n';

    std::cout << "При неттовом весе " << netWeight << " г продукта, употребляется:\n";
    std::cout << "Белков\t\t" << proteinPerServing << " г.\n";
    std::cout << "Углеводов\t" << carbsPerServing << " г.\n";
    
    return 0;
}










//Задача 3. Постоянный покупатель

#include <iostream>

int main()
{
    std::cout << "Введите цену товара за 100 грамм: ";
    float fixedPrice;
    std::cin >> fixedPrice;

    std::cout << "Введите вес покупки: ";
    float productAmount;
    std::cin >> productAmount;

    std::cout << "Введите размер скидки: ";
    int discount;
    std::cin >> discount;

    float finalCost;
    if (discount == 0)
    {
        finalCost = fixedPrice / 100 * productAmount;
    }
    else
    {
        float productCost = fixedPrice / 100 * productAmount;
        finalCost = productCost - productCost * discount / 100;
    }

    std::cout << "Стоимость покупки: " << finalCost;

    return 0;
}










//Задача 1. Ку!

#include <iostream>

int main()
{
    float kts = 4400.0f; 
    float gravitsapa = kts / 2;

    std::cout << "Введите количество чатлов: ";
    int chatlNumber;
    std::cin >> chatlNumber;
    
    float ktsNumber = (float) chatlNumber / kts;
    
    int gravitsapaCount = (float) chatlNumber / gravitsapa;
   
    std::cout << chatlNumber << " ч = " << ktsNumber << " КЦ\n";
    std::cout << "Количество гравицап, которое можно купить: " << gravitsapaCount;



    return 0;
}










//Задача 2. Компьютерное зрение

#include <iostream>

int main()
{
    float x, y;
    bool correctInput = false;
    do
    {
        std::cout << "Введите местоположение фигуры: \n";
        std::cin >> x >> y;

        if (x > 0.799 || x < 0 || y > 0.799 || y < 0)
            std::cout << "Местоположение неверное.";
        else
            correctInput = true;
    } while (!correctInput);

    x *= 10;
    y *= 10;

    std::cout << "Фигура находится в клетке (" << (int) x << ", " << (int) y << ").\n";
    
    return 0;
}










//Задача 3. Метеостанция

#include <iostream>

int main()
{
    float lowTemp;
    std::cout << "Нижняя граница: ";
    std::cin >> lowTemp;

    float highTemp;
    do 
    {
        std::cout << "Верхняя граница: ";
        std::cin >> highTemp;
        if (highTemp <= lowTemp)
            std::cout << "Верхняя граница не может быть меньше нижней границы или равной ей.\n";
    } while (highTemp <= lowTemp);

    float increment;
    std::cout << "Шаг: ";
    std::cin >> increment;

    std::cout << "C\tF\n";

    int currentTemp = lowTemp;
    for (; currentTemp <= highTemp; currentTemp += increment)
    {
        int tempFahr = currentTemp * 1.8 + 32;
        std::cout << currentTemp << "\t" << tempFahr << '\n';
    }
    if (currentTemp != highTemp)
    {
        std::cout << highTemp << "\t" << highTemp * 1.8 + 32 << '\n';
    }
    return 0;
}











