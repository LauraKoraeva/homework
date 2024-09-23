//Задача 1


#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::string word;
    std::cout << "Input the text and the word:\n";
    std::getline(std::cin, text);
    std::getline(std::cin, word);

    int matchesFound = 0;

    bool found = false;
    for (int startIndex = 0; startIndex + word.length() <= text.length(); ++startIndex)
    {
        bool match = true;
        for (int index = 0; index < word.length(); ++index)
        {
            if (word[index] != text[index + startIndex])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            found = true;
            matchesFound += 1;
        }
    }

    std::cout << "Matches found: " << matchesFound << '\n';

    return 0;
}










