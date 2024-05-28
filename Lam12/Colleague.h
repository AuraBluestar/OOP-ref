#pragma once
#include "Contact.h"
#include<string>

class Colleague: public Contact
{

public:
	std::string getAdresa()
	{
		return adresa;
	};
	std::string GetServiciu() {
		return serviciu;
	};
	std::string GetNrTelefon()
	{
		return nr_telefon;
	};
	std::string GetTip() {
		return "Colleague";
	};
	std::string nr_telefon;
	std::string adresa;
	std::string serviciu;
};

