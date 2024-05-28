#include <iostream>
#include "Agenda.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"

int main() {
    AddressBook agenda;

    // Adăugare contacte
    Friend* prieten1 = new Friend();
    prieten1->nume = "John";
    prieten1->data_nastere = "01/01/1990";
    prieten1->nr_telefon = "1234567890";
    prieten1->adresa = "Strada A, Nr. 1";
    agenda.Adauga(prieten1);
    
    Colleague* coleg1 = new Colleague();
    coleg1->nume = "Alice";
    coleg1->nr_telefon = "9876543210";
    coleg1->adresa = "Strada B, Nr. 2";
    coleg1->serviciu = "ABC Company";
    agenda.Adauga(coleg1);
    
    Acquaintance* cunoscut1 = new Acquaintance();
    cunoscut1->nume = "Bob";
    cunoscut1->nr_telefon = "5555555555";
    agenda.Adauga(cunoscut1);

    
    
    // Căutare contact
    std::string numeCautat = "Alice";
    Contact* contactCautat = agenda.Cauta(numeCautat);
    if (contactCautat != nullptr) {
        std::cout << "Contactul cu numele " << numeCautat << " a fost gasit." << std::endl;
    }
    else {
        std::cout << "Contactul cu numele " << numeCautat << " nu a fost gasit." << std::endl;
    }
    
    // Obținere lista de prieteni
    std::vector<Contact*> prieteni = agenda.GetPrieteni();
    std::cout << "Lista de prieteni:" << std::endl;
    for (const auto& prieten : prieteni) {
        std::cout << prieten->GetNume() << std::endl;
    }
    
    // Ștergere contact
    std::string numeDeSters = "Bob";
    agenda.Sterge(numeDeSters);
    
    
    // Eliberare memorie
    delete prieten1;
    delete coleg1;
    delete cunoscut1;
    
    return 0;
}
