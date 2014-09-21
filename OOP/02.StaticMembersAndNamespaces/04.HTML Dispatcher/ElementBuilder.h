#pragma once
#include <iostream>
#include <string>
#include <sstream>

class ElementBuilder
{
	const char openingSymbol = '<';
	const char closingSymbol = '>';
	std::string element;

public:
	ElementBuilder(const std::string& name);
	virtual ~ElementBuilder();

	void AddAttribute(const std::string& name, const std::string& value);

	void AddContent(const std::string& content);

	std::string toString() const;
};

