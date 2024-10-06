//Урок 4. Словари std::map

//Задание 1. Телефонный справочник

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::cout << "Select an operation:\n";
    std::cout << "1 - Add phone number and surname to phone directory;" << '\n';
    std::cout << "2 - Find name by phone number;" << '\n';
    std::cout << "3 - find phone by name: " << '\n';
    int operation;
    std::cin >> operation;

    std::map<std::string, std::string> numberSurname;

    numberSurname["8-945-135-10-74"] = "Ivanov";
    numberSurname["8-906-156-97-00"] = "Petrov";
    numberSurname["8-945-237-82-15"] = "Popov";

    std::map<std::string, std::vector<std::string>> surnameNumber
    {
            {"Ivanov", {"8-945-135-10-74", "8-906-547-35-36"}},
            {"Petrov", {"8-906-156-97-00"}},
            {"Popov", {"8-945-237-82-15"}}
    };

    std::string phoneNumber;
    std::string surname;

    if (operation == 1)
    {
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        std::cout << "Enter surname: ";
        std::cin >> surname;

        numberSurname.insert(std::pair<std::string, std::string>(phoneNumber, surname));
        surnameNumber[surname].push_back(phoneNumber);
    }

    if (operation == 2)
    {
        std::cout << "Enter phone number:";
        std::cin >> phoneNumber;

        std::map<std::string, std::string>::iterator it = numberSurname.find(phoneNumber);
        if 
            (it == numberSurname.end()) std::cout << "Not found" << '\n';
        else 
            std::cout << "Phone number belongs to: " << it->second << '\n';
    }

    if (operation == 3)
    {
        std::cout << "Enter surname: ";
        std::cin >> surname;

        std::map<std::string, std::vector<std::string>>::iterator it = surnameNumber.find(surname);
        if (it == surnameNumber.end()) 
            std::cout << "Not found" << '\n';
        else 
        {
            for (std::vector<std::string>::iterator itf = it->second.begin();
                itf != it->second.end(); ++itf)
            {
                std::cout << *itf << " ";
            }
        }
    }
    return 0;
}










//Задание 2. Регистратура

#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> queue;
	int number = 0;

	std::string enquiry;
	while (enquiry != "-1")
	{
		"Enter enquiry: ";
		std::cin >> enquiry;

		if (enquiry != "Next")
		{
			++number;
			queue.insert(std::pair<std::string, int>(enquiry, number));
		}
		else
		{
			if (number > 0)
			{
				std::cout << queue.begin()->first << '\n';
				queue.erase(queue.begin()->first);
				--number;
			}
			else
				std::cout << "Queue is empty.\n";
		}
	
	}
	return 0;
}










//Задание 3. Анаграммы

#include <iostream>
#include <map>
#include <string>


bool isAnagram(std::string word_1, std::string word_2) {
	std::map<char, int> firstWord;
	std::map<char, int> secondWord;

	if (word_1.length() != word_2.length()) return false;

	for (int i = 0; i < word_1.length(); i++) 
	{
		if (firstWord.find(word_1[i]) != firstWord.end()) 
		{
			firstWord[word_1[i]]++;
		}
		else 
		{
			firstWord.insert(std::make_pair(word_1[i], 1));
		}
	}

	for (int i = 0; i < word_2.length(); i++) 
	{
		if (secondWord.find(word_2[i]) != secondWord.end()) 
		{
			secondWord[word_2[i]]++;
		}
		else 
		{
			secondWord.insert(std::make_pair(word_2[i], 1));
		}
	}
	if (firstWord == secondWord) 
		return true;
	else 
		return false;

}

int main() {
	std::string word_1;
	std::string word_2;

	std::cout << "Enter two words\n";
	std::cin >> word_1 >> word_2;

	if (isAnagram(word_1, word_2))
		std::cout << word_1 << " and " << word_2 << " are anagrams.\n";
	else
		std::cout << word_1 << " and " << word_2 << " are not anagrams.\n";

    return 0;
}