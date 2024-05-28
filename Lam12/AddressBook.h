#pragma once
#include <vector>
#include<string>
#include "Contact.h"

class AddressBook:public Contact
{
private:
	std::vector<Contact*> contacte;
public:
	Contact* Cauta(std::string nume);
	std::vector <Contact*> GetPrieteni();
	void Sterge(std::string nume);
	void Adauga(Contact* c);

};

