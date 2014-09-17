#include<iostream>
#include<string>

template<class T1, class T2>
class Pair
{
public:
	T1 key;
	T2 value;
};

int main()
{
	Pair<int, std::string> list;

	list.key = 1;
	list.value = "Mitko";

	return 0;
}