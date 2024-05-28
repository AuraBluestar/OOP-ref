#pragma once
#include<string>

class Contact
{
public:
	std::string nume;
	virtual std::string GetTip() { return "contact"; };
	std::string GetNume() 
	{
		return nume;
	};
};
