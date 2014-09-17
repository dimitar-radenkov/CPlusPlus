#include<iostream>
#include<string>

template<typename T, typename... Args>
void printValues(const char *s, T value, Args... args)
{
	while (*s) 
	{
		if (*s == '%' && *(++s) != '%') 
		{
			std::cout << value;
			++s;
			printValues(s, args...);
			return;
		}
		std::cout << *(s++);
	}
}

int main()
{
	printValues("%d %d %d", 1, 2, 3); // value -> 1, args... -> 2,3
	printValues("%d %d", 2, 3); // value -> 2, args... -> 3
	printValues("%d", 3); // value -> 3, args... -> NULL
	//printValues(""); // value -> NULL, args... -> NULL
	
	return 0;
}