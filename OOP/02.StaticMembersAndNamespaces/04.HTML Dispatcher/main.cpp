#include <iostream>
#include "ElementBuilder.h"
#include "HTMLDispatcher.h"

int main()
{
	ElementBuilder builder("div");

	builder.AddAttribute("id", "page");
	builder.AddAttribute("class", "big");
	builder.AddContent("<p>Hello</p>");

	auto image = HTMLDispatcher::CreateImage("www.dir.bg", "smiley", "happy");
	auto url = HTMLDispatcher::CreateURL("www.dnes.bg", "url test", "happy");
	auto input = HTMLDispatcher::CreateInput("search", "input test", "get");

	std::cout << image.toString() << std::endl;
	std::cout << url.toString() << std::endl;
	std::cout << input.toString() << std::endl;

	system("pause");

	return 0;
}