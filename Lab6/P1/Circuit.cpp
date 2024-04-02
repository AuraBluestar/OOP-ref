#include "Circuit.h"

void Circuit::SetLength(int l)
{
	this->l = l;
}

void Circuit::SetWeather(Weather w)
{
	this->w = w;
}

void Circuit::AddCar(Car* c)
{
	masini.push_back(c);
}

void Circuit::Race()
{
	for (auto& car : masini) 
	{
		int distanta = car->getCapacity() * (100/car->getConsumtion());
		if (distanta < l)
			masini_neterminat.push_back(car);
		else 
		{
			masini_terminat.push_back(car);
			car->setTime(l/car->getSpeed(w));
		}
	}
}

void Circuit::ShowFinalRanks()
{
	std::vector<Car*> ordonat;
	for(auto& car : masini)
	{
		// Găsiți locația corespunzătoare pentru inserare
		auto it = ordonat.begin();
		while (it != ordonat.end() && (*it)->getTime() < car->getTime()) {
			++it;
		}
		// Inserați elementul în locația corectă
		ordonat.insert(it, car);
	}

	std::cout << "Au terminat:" << std::endl;
	for (auto& car : ordonat)
	{
		std::cout << car->getName()<<"; ";
	}
	std::cout << std::endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	std::cout << "Nu au terminat:" << std::endl;
	for (auto& car : masini_neterminat)
	{
		std::cout << car->getName() << "; ";
	}
	std::cout << std::endl;
}
