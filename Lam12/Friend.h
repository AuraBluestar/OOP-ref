#pragma once
#include "Contact.h"
#include<string>

class Friend:public Contact
{
public: 
	std::string data_nastere;
	std::string nr_telefon;
	std::string adresa;
private:
	std::string GetDataNastere() 
	{
		return data_nastere;
	};
	std::string GetAdresa() 
	{
		return adresa;
	};
	std::string GetNrTelefon() 
	{
		return nr_telefon; 
	};
	std::string GetTip() 
	{ 
		return "Friend"; 
	};
};

