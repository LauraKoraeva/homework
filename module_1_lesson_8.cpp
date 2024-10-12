//Задача 1. Орехи

#include <iostream>

int main()
{
    std::cout << "Enter the price of the product per 100 grams: ";
    float fixedPrice;
    std::cin >> fixedPrice;

    std::cout << "Enter the purchase weight: ";
    float productAmount;
    std::cin >> productAmount;

    float finalCost = fixedPrice / 100 * productAmount;
    std::cout << "Purchase price: " << finalCost;


    return 0;
}










//Задача 2. ЗОЖ
#include <iostream>

int main()
{
    std::cout << "Enter the amount of protein per 100 grams of product: ";
    float protein;
    std::cin >> protein;

    std::cout << "Enter the amount of carbohydrates per 100 grams of product: ";
    float carbs;
    std::cin >> carbs;

    std::cout << "Enter the net weight of the product: ";
    float netWeight;
    std::cin >> netWeight;

    float proteinPerServing = netWeight / 100 * protein;
    float carbsPerServing = netWeight / 100 * carbs;

    std::cout << '\n';

    std::cout << "With a net weight of " << netWeight << " g of the product, it is consumed:\n";
    std::cout << "Protein\t\t" << proteinPerServing << " g.\n";
    std::cout << "Carbohydrates\t" << carbsPerServing << " g.\n";
    
    return 0;
}










//Задача 3. Постоянный покупатель

#include <iostream>

int main()
{
    std::cout << "Enter the price of the product per 100 grams: ";
    float fixedPrice;
    std::cin >> fixedPrice;

    std::cout << "Enter the purchase weight: ";
    float productAmount;
    std::cin >> productAmount;

    std::cout << "Enter the discount amount: ";
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

    std::cout << "Purchase price: " << finalCost;

    return 0;
}










//Задача 1. Ку!

#include <iostream>

int main()
{
    float kts = 4400.0f;
    float gravitsapa = kts / 2;

    std::cout << "Enter the amount of chatls: ";
    float chatlNumber;
    std::cin >> chatlNumber;
   
    while ((int) chatlNumber - chatlNumber != 0 || chatlNumber < 0)
    {
        std::cout << "Incorrect input. Try again!\n";
        std::cin >> chatlNumber;
    }

    float ktsNumber = chatlNumber / kts;

    int gravitsapaCount = chatlNumber / gravitsapa;

    std::cout << chatlNumber << " ch = " << ktsNumber << " KTS\n";
    std::cout << "The number of gravitsapas you can buy: " << gravitsapaCount;

return 0;

}










//Задача 2. Компьютерное зрение

#include <iostream>

int main()
{
    double x, y;
    bool correctInput = false;
    do
    {
        std::cout << "Enter the coordinates of the chess piece: \n";
        std::cin >> x >> y;
        if (x > 0.799 || x < 0 || y > 0.799 || y < 0)
            std::cout << "Incorrect input. Try again!";
        else correctInput = true;
    } while (!correctInput);

    x *= 10;
    y *= 10;

    std::cout << "Chess piece is on square (" << (int) x << ", " << (int) y << ").\n";

    return 0;
}










//Задача 3. Метеостанция

#include <iostream>

int main()
{
    float lowTemp;
    std::cout << "Low temperature limit: ";
    std::cin >> lowTemp;

    float highTemp;
    do 
    {
        std::cout << "High temperature limit: ";
        std::cin >> highTemp;
        if (highTemp <= lowTemp)
            std::cout << "The high temperature limit cannot be less than or equal to the low temperature limit.\n";
    } while (highTemp <= lowTemp);

    float increment;
    std::cout << "Increment: ";
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










//Задача 4. Аккуратность

#include <iostream>

int main()
{
    double x, y;
    bool correctInput = false;
    do
    {
        std::cout << "Enter the coordinates of the chess piece: \n";
        std::cin >> x >> y;
        if (x > 0.799 || x < 0 || y > 0.799 || y < 0)
            std::cout << "Incorrect input. Try again!";
        else correctInput = true;
    } while (!correctInput);

    int position_x = x * 10;
    int position_y = y * 10;

    double adjust_x, adjust_y;
   
    adjust_x = 0.050 - (x - (double) position_x / 10);
    adjust_y = 0.050 - (y - (double) position_y / 10);
    
   std::cout << "Chess piece is on square (" << position_x << ", " << position_y << ").\n"; 
   std::cout << "Adjust the position of the piece by (" << adjust_x << ", " << adjust_y << ").\n";

    return 0;
}









//Практическая работа

//Задание 1. Космический симулятор

#include <iostream>
#include <cmath>

int main()
{
	float mass;
	do
	{
		std::cout << "Input mass: ";
		std::cin >> mass;
		if (mass <= 0)
			std::cout << "Mass cannot be equal to zero or less than zero.\n";
	} while (mass <= 0);

	std::cout << "Input force: ";
	float force;
	std::cin >> force;

	std::cout << "Input time: ";
	float time;
	std::cin >> time;

	float acceleration = force / mass;

	float distance = (acceleration * std::pow(time, 2.0)) / 2;

	std::cout << "In " << time << " seconds, the spacecraft will cover a distance of " << distance << " km.";

	return 0;
}










//Задание 2. Immolate Improved!

#include <iostream>

int main()
{
	float health = 1;
	
	float resistance;
	do
	{
		std::cout << "Enter orc's resistance power: ";
		std::cin >> resistance;

		if (resistance < 0 || resistance > 1)
			std::cout << "Error!\n";

	} while (resistance < 0 || resistance > 1);

	while (health > 0)
	{
		float impactPower;
		do
		{
			std::cout << "Enter fireball's impact power: ";
			std::cin >> impactPower;

			if (impactPower < 0 || impactPower > 1)
				std::cout << "Error!\n";
		} while (impactPower < 0 || impactPower > 1);

		float damage = impactPower - (impactPower * resistance);
		health -= damage;

		std::cout << "Health damage: " << damage << '\n';
		std::cout << "Life left: " << health << '\n';
	}

	std::cout << "Orc is dead!\n";

	return 0;
}










//Задание 3. Игрушечная история

#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Find out how many sets of cubes you can make.\n";
    std::cout << "Enter bar's length, width and height:\n";
   
    double length;
    std::cout << "Length: ";
    std::cin >> length;
   
    double width;
    std::cout << "Width: ";
    std::cin >> width;
   
    double height;
    std::cout << "Height: ";
    std::cin >> height;
   
    if (length < 5 || width < 5 || height < 5)
    {
std::cout << "The bar is too small to make a single cube.";
}
else
{
    int x = length / 5;
    int y = width / 5;
    int z = height / 5;
   
    int cubesCount = x * y * z;
    int setsCount = std::pow((int)std::pow(cubesCount, 1.0 / 3), 3);
   
    std::cout << "You can make " << setsCount << " sets out of " << cubesCount << " cubes.\n";
}

    return 0;
}










//Задание 4. Убийца Steam

#include <iostream>

int main()
{
	float fileSize;
	do
	{
		std::cout << "Enter file size: ";
		std::cin >> fileSize;

		if (fileSize <= 0)
			std::cout << "Error!\n";
	} while (fileSize <= 0);
	
	float downloadSpeed;
	do
	{
		std::cout << "Enter downloading speed: ";
		std::cin >> downloadSpeed;

		if (downloadSpeed <= 0)
			std::cout << "Error!\n";
	} while (downloadSpeed <= 0);

	int secondsCount = 0;
	float downloaded = 0;
	float fileLeft = fileSize;
	int percent = 0;

	while (fileLeft > 0)
	{
		if (fileLeft < downloadSpeed)
		{
			downloaded += fileLeft;
			fileLeft -= fileLeft;
			++secondsCount;
			percent = (100 / fileSize) * downloaded;
		}
		else
		{
			downloaded += downloadSpeed;
			fileLeft -= downloadSpeed;
			++secondsCount;
			percent = (100 / fileSize) * downloaded;
		}

		std::cout << "Time passed: " << secondsCount << " sec. Downloaded: " << downloaded << " MB out of " << fileSize << " (" << percent << "%).\n";
	}

	return 0;
}










//Задание 5. Кенийский бегун

#include <iostream>

int main()
{
	int kilometresCount;
	do
	{
		std::cout << "How many kilometres did you run today? ";
		std::cin >> kilometresCount;

		if (kilometresCount <= 0)
			std::cout << "Error!\n";
	} while (kilometresCount <= 0);

	float total = 0;

	int index = 1;
	while (index <= kilometresCount)
	{
		float pace;
		do
		{
			std::cout << "Enter your pace at kilometre " << index << ": ";
			std::cin >> pace;

			if (pace <= 0)
				std::cout << "Error!\n";
		} while (pace <= 0);

		total += pace;
		index++;
	}
	
	int minutes = total / kilometresCount / 60;
	int seconds = (int) std::round(total / kilometresCount) % 60;

	std::cout << "Your average pace: " << minutes << " minutes " << seconds << " sec.\n";

	return 0;
}










//Задание 6. Маятник

#include <iostream>

int main()
{
    float initialAmplitude;
    float finalAmplitude;
   
    do
    {
        std::cout << "Enter the initial amplitude: ";
        std::cin >> initialAmplitude;
        std::cout << "Enter the final amplitude: ";
        std::cin >> finalAmplitude;
       
        if (initialAmplitude < 0 || finalAmplitude < 0 || finalAmplitude > initialAmplitude)
            std::cout << "Error! Try again:\n";
    } while (initialAmplitude < 0 || finalAmplitude < 0 || finalAmplitude > initialAmplitude);
   
    int count = 0;
    while (initialAmplitude > finalAmplitude)
    {
        initialAmplitude *= 1 - 0.084f;
        ++count;
    }
   
    std::cout << "The pendulum will reach the final amplitude after " << count << " oscillations.\n";
   
    return 0;
       
}









