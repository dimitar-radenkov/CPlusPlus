#include "ElementBuilder.h"

ElementBuilder::ElementBuilder(const std::string& name)
{
	this->element.append("<" + name + ">");
	this->element.append("</" + name + ">");
}

ElementBuilder::~ElementBuilder()
{
}

void ElementBuilder::AddAttribute(const std::string& name, const std::string& value)
{
	int index = this->element.find(this->closingSymbol);

	std::string stringToInsert = " " + name + "=" + "\"" + value + "\"";
	this->element.insert(index, stringToInsert);
}

void ElementBuilder::AddContent(const std::string& content)
{
	int index = this->element.find(this->closingSymbol);
	this->element.insert(index + 1, content);
}

std::string ElementBuilder::toString() const
{
	return this->element;
}
