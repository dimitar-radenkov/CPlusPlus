#include "HTMLDispatcher.h"

HTMLDispatcher::HTMLDispatcher()
{
}

HTMLDispatcher::~HTMLDispatcher()
{
}

ElementBuilder
HTMLDispatcher::CreateImage(const std::string& source,
							const std::string& alt,
							const std::string& title)
{
	ElementBuilder element("image");
	element.AddAttribute("src", source);
	element.AddAttribute("alt", alt);
	element.AddAttribute("title", title);

	return element;
}

ElementBuilder
HTMLDispatcher::CreateURL(const std::string& url,
						  const std::string& title,
						  const std::string& text)
{
	ElementBuilder element("a");
	element.AddAttribute("href", url);
	element.AddAttribute("title", title);
	element.AddContent(text);

	return element;
}

ElementBuilder
HTMLDispatcher::CreateInput(const std::string& type,
						    const std::string& name,
						    const std::string& value)
{
	ElementBuilder element("input");
	element.AddAttribute("type", type);
	element.AddAttribute("name", name);
	element.AddContent(value);

	return element;
}
