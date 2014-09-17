#include<iostream>
#include<string>

template<class T>
class Entity
{
private:
	T data;

public:
	Entity(T data)
	{
		this->data = data;
	}

	~Entity()
	{}

	T getData() const
	{
		return this->data;
	}

	void setData(const T data)
	{
		this->data = data;
	}
};

int main()
{
	Entity<int> entity(5);

	std::cout << "data from entity : " << entity.getData() << std::endl;
	entity.setData(80);

	Entity<std::string> strEntity("Hello");
	strEntity.setData("Hello World !!!");
	std::cout << "data from strEntity : " << strEntity.getData() << std::endl;

	system("pause");

	return 0;
}