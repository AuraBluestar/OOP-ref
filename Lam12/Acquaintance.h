#pragma once
#include"Contact.h"

class Acquaintance: public Contact
{
public:
	std::string nr_telefon;
	std::string GetNrTelefon() { return nr_telefon; };
	std::string GetTip()
	{
		return "Acquaintance";
	};

};

