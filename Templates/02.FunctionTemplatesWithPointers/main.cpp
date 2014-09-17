#include <iostream>

template<class T>
T sum(T array[], int count)
{
	T sum = T(); //0
	for (size_t i = 0; i < count; i++)
	{
		sum += array[i];
	}

	return sum;
}

template<class T>
void incrementWith10(T& data)
{
	data += 10;
}

int main()
{
	const int elementCount = 8;
	int arrIntegers[]{1, 2, 3, 4, 5, 6, 7, 8};
	double arrDoubles[]{1.5, 2.2, 3.3, 4.3, 5.5, 6.1, 7.2, 8.1};
	
	std::cout << sum(arrIntegers, elementCount) << std::endl;
	std::cout << sum(arrDoubles, elementCount) << std::endl;

	int integerValue = 10;
	double PI = 3.14;

	incrementWith10(integerValue);
	incrementWith10(PI);

	std::cout << "integer value after : " << integerValue << std::endl;
	std::cout << "PI after : " << PI << std::endl;
	
	system("pause");

	return 0;
}