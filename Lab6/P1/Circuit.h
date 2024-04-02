#pragma once
#include <iostream>
#include "Car.h"
#include "Weather.h" 
#include <vector>
class Circuit
{
private:
	Weather w;
	int l;
	std::vector<Car*> masini;
	std::vector<Car*> masini_terminat;
	std::vector<Car*> masini_neterminat;
public:
	void SetLength(int l);
	void SetWeather(Weather w);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks(); 
	void ShowWhoDidNotFinish();
};

