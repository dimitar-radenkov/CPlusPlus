#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "Models\Rectangle.h"
#include "Models\Triangle.h"
#include "Models\Circle.h"

int main()
{
	std::shared_ptr<IShape> circle(new Circle(10));
	std::shared_ptr<IShape> rectangle(new Rectangle(5, 10));
	std::shared_ptr<IShape> triangle(new Triangle(11, 6));

	std::vector<std::shared_ptr<IShape>> shapesList{ circle, rectangle, triangle };

	std::for_each(shapesList.begin(), shapesList.end(),
		[](std::shared_ptr<IShape> shape)
	{
		std::cout << "Perimeter " << shape->CalculatePerimeter() << std::endl;
		std::cout << "Area " << shape->CalculateArea() << std::endl << std::endl;
	});

	system("pause");
	return 0;
}