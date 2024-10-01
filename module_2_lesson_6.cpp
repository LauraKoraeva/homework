//Урок 6. Указатели

//Задача 1

#include <iostream>

void swapPointers (int *ptr_a, int *ptr_b)
{
    std::swap(*ptr_a, *ptr_b);
}
       
       
int main()
{
    int a = 10;
    int b = 20;
   
    int * ptr_a = &a;
    int * ptr_b = &b;
   
    swapPointers(ptr_a, ptr_b);
   
    std::cout << a << " " << b;
   
    return 0;
}










//Задача 2

#include <iostream>

void reverse(int *ptrArray, int length)
{
    for(int i = 0; i < length / 2; ++i)
    {
       std::swap(ptrArray[i], ptrArray[length - i - 1]);
    }
   
}
 
       
int main()
{
    int length = 10;
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   
   
   
    reverse(array, length);
   
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
    }
   
    return 0;
}










//Задача 3

#include <iostream>

bool substr(char* text, char* subText)
{
	bool found = false;
	for (int start = 0; start < *(text + start) != '\0'; ++start)
	{
		bool match = true;
		for (int i = 0; i < *(subText + i) != '\0'; ++i)
		{
			if (*(subText + i + start) == '\0' || *(subText + i) != *(text + i + start))
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			found = true;
			break;
		}
	}
	return found;
}

int main()
{
	char a[] = "Hello, world!";
	char b[] = "world";
	char c[] = "friend";

	std::cout << std::boolalpha;

	std::cout << substr(a, b) << " " << substr(a, c);
	
	return 0;
}