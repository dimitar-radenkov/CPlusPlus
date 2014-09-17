#include <iostream>

template<class T>
void print(T data)
{
	std::cout << data << std::endl;
}

template<class T>
T getMax(T data1, T data2)
{
	return data1 > data2 ? data1 : data2;
}

int main()
{
	std::cout << "------- Print -------" << std::endl;
	print("Hello");
	print(1233);
	print(3.14);
	std::cout << std::endl << std::endl;

	std::cout << "------- Get max -------" << std::endl;
	std::cout << getMax(5.6, 9.9) << std::endl;
	std::cout << getMax(100, 200) << std::endl;
	std::cout << getMax('a', 'A') << std::endl;
	std::cout << std::endl << std::endl;

	system("pause");
	//this is valid too
	//getMax<int>(1, 2);

	return 0;
}