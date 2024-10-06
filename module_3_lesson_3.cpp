//Урок 3. Структуры данных

//1. Ведомость учёта

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


struct Recipient
{
	std::string name;
	std::string surname;
	std::string date;
	int cash;
};

void add()
{
	std::ofstream recipients("C:\\Users\\Acer\\Desktop\\Recipients.txt", std::ios::app);
	Recipient person;
	std::cout << "Enter the data:\n";
	std::cout << "Name: ";
	std::cin >> person.name;
	std::cout << "Surname: ";
	std::cin >> person.surname;
	std::cout << "Date: ";
	std::cin >> person.date;
	std::cout << "Cash: ";
	std::cin >> person.cash;
	recipients << person.name << " " << person.surname << " " << person.date << " " << person.cash << std::endl;
	recipients.close();
}

void list()
{
	std::ifstream recipients;
	recipients.open("C:\\Users\\Acer\\Desktop\\Recipients.txt", std::ios::app);
	Recipient person;
	
	while (!recipients.eof())
	{
		recipients >> person.name >> person.surname >> person.date >> person.cash;
		if (person.name.empty())
		{
			break;
		}
		else
		{
			std::cout << person.name << " " << person.surname << " " << person.date << " " << person.cash
				<< " " << std::endl;
			person.name = "";
		}
	}
	recipients.close();
}

enum Operation
{
	ADD = 1,
	LIST,
};

int main()
{
	std::cout << "Enter number of an operation:\n";
	std::cout << "1 - add\n";
	std::cout << "2 - list\n";
	int operation;
	std::cin >> operation;

	if (operation == ADD)
		add();
	else
		list();

	return 0;
}










//2. Модель данных для посёлка

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum BuildingType
{
	HOUSE = 1,
	GARAGE,
	BARN,
	BATHHOUSE,
};

enum RoomType
{
	BEDROOM = 1,
	BATHROOM,
	NURSERY,
	LIVINGROOM,
	KITCHEN,
};

struct Room
{
	RoomType type;
	int roomSquare;
};

struct Floor
{
	int ceilingHeights;
	//std::vector<Room> rooms;
};

struct House
{
	int houseSquare;
	//std::vector<Floor> floors;
};

struct Garage
{
	int garageSquare;
};

struct Barn
{
	int barnSquare;
};

struct Bathhouse
{
	int bathhouseSquare;
	bool hasStove = false;
};

struct LandArea
{
	int landAreaID;
	//std::vector<House> houses;
	//std::vector<Garage> garages;
	//std::vector<Barn> barns;
	//std::vector<Bathhouse> baths;
};

int main()
{
	std::ofstream villageInfo("C:\\Users\\Acer\\Desktop\\villageInfo.txt", std::ios::app);
	std::cout << "Enter village name: ";
	std::string villageName;
	std::cin >> villageName;
	villageInfo << villageName << std::endl;
	std::cout << "Enter the number of plots in the village: ";
	int landAreaCount;
	std::cin >> landAreaCount;
	villageInfo << "Number of plots: " << landAreaCount << std::endl;
	//std::vector<LandArea> area;

	for (int i = 1; i <= landAreaCount; ++i)
	{
		LandArea area;
		area.landAreaID = i;
		std::cout << "Plot #" << area.landAreaID << std::endl;
		villageInfo << "Plot # " << area.landAreaID << std::endl;
		std::cout << "Enter the number of buildings: " << std::endl;
		int buildingsCount;
		std::cin >> buildingsCount;
		villageInfo << "Number of buildings: " << buildingsCount << std::endl;
		for (int i = 0; i < buildingsCount; ++i)
		{
			std::cout << "Select the type of a building:" << std::endl;
			std::cout << "1 - house\n";
			std::cout << "2 - garage\n";
			std::cout << "3 - barn\n";
			std::cout << "4 - bathhouse\n";
			int buildingType;
			std::cin >> buildingType;
			
			if (buildingType == 1)
			{
				House house;
				std::cout << "Enter house square:";
				std::cin >> house.houseSquare;
				villageInfo << "House square: " << house.houseSquare << " sq m" << std::endl;
				std::cout << "Enter number of floors: ";
				int floorsCount;
				std::cin >> floorsCount;
				villageInfo << "Number of floors: " << floorsCount << std::endl;
				for (int i = 1; i <= floorsCount; ++i)
				{
					Floor floor;
					std::cout << "Enter Floor " << i << " ceiling height:";
					std::cin >> floor.ceilingHeights;
					villageInfo << "Floor " << i << " ceiling height: " << floor.ceilingHeights << " m" << std::endl;
					int roomsCount;
					std::cout << "Enter number of rooms: ";
					std::cin >> roomsCount;
					villageInfo << "Floor " << i << " number of rooms: " << roomsCount << std::endl;
					villageInfo << "Rooms: " << std::endl;
					for (int i = 0; i < roomsCount; ++i)
					{
						Room room;
						std::cout << "Select the type of a room:" << std::endl;
						std::cout << "1 - bedroom\n";
						std::cout << "2 - bathroom\n";
						std::cout << "3 - nursery\n";
						std::cout << "4 - living room\n";
						int roomType;
						std::cin >> roomType;
						std::cout << "Enter square: ";
						std::cin >> room.roomSquare;
						std::string type;
						if (roomType == 1)
							type = "bedroom";
						else if (roomType == 2)
							type = "bathroom";
						else if (roomType == 3)
							type = "nursery";
						else if (roomType == 4)
							type = "living room";
						villageInfo << type << "(" << room.roomSquare << " sq m)" << std::endl;

					}

				}
			}
			else if (buildingType == 2)
			{
				Garage garage;
				std::cout << "Enter garage square: ";
				std::cin >> garage.garageSquare;
				villageInfo << "Garage square: " << garage.garageSquare << " sq m" << std::endl;
			}
			else if (buildingType == 3)
			{
				Barn barn;
				std::cout << "Enter barn square: ";
				std::cin >> barn.barnSquare;
				villageInfo << "Barn square: " << barn.barnSquare << " sq m" << std::endl;
			}
			else if (buildingType == 4)
			{
				Bathhouse bath;
				std::cout << "Enter bathhouse square: ";
				std::cin >> bath.bathhouseSquare;
				std::cout << "Is there a wood stove?\n";
				std::string answer;
				std::cin >> answer;
				if (answer == "yes")
					bath.hasStove = true;
				villageInfo << "Bathhouse square: " << bath.bathhouseSquare << " sq m" << std::endl;
				if (bath.hasStove)
					villageInfo << "Stove: +";
				else
					villageInfo << "Stove: -";

			}
			std::cout << std::endl;
		}
		
	}
	return 0;
}
