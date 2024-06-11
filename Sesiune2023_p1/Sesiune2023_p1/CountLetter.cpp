#include "CountLetter.h"
#include <functional>
#include <iostream>

CountLetter::CountLetter(const std::string& name, std::function<bool(char)> predicate): predicate(predicate)
{
	this->name = name;
}

std::string CountLetter::GetName() const 
{
	return name;
}

void CountLetter::Compute(const std::string& text)
{
	int count = 0;
	for (char ch : text)
	{
		if (predicate(ch))
			count++;
	}
	std::cout << "Name:" << name << " => " << count << std::endl;
}
