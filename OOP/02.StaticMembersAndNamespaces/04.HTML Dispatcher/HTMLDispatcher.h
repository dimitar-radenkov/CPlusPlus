#pragma once
#include <string>
#include "ElementBuilder.h"

class HTMLDispatcher
{
private:
	HTMLDispatcher();

public:

	virtual ~HTMLDispatcher();

	static ElementBuilder
		CreateImage(const std::string& source,
					const std::string& alt,
					const std::string& title);

	static ElementBuilder
		CreateURL(const std::string& url,
				  const std::string& title,
				  const std::string& text);

	static ElementBuilder
		CreateInput(const std::string& type,
					const std::string& name,
					const std::string& value);


};

