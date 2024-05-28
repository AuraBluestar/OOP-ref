#include "Agenda.h"
#include "Contact.h"
#include<vector>

Contact* AddressBook::Cauta(std::string nume)
{
	for (auto i : contacte)
		if (i->GetNume() == nume)
			return i;
	return nullptr;
}

std::vector<Contact*> AddressBook::GetPrieteni()
{
	std::vector<Contact*> prieteni;
	for (auto i : contacte)
		if (i->GetTip() == "Friend")
			prieteni.push_back(i);
	return prieteni;
}

void AddressBook::Sterge(std::string nume)
{
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetNume() == nume)
			contacte.erase(contacte.begin()+i);
}

void AddressBook::Adauga(Contact* c)
{
	contacte.push_back(c);
}
