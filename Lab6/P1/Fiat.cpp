#include "Fiat.h"

Fiat::Fiat()
{
	fuelCapacity = 50;
	fuelConsumtion = 5;
	rain_speed = 43;
	snow_speed = 23;
	sunny_speed = 80;
	timp = 0;
}

void Fiat::setCapacity(int capacity)
{
	fuelCapacity = capacity;
}

void Fiat::setComsumtion(int consumtion)
{
	fuelConsumtion = consumtion;
}

void Fiat::setSpeed(int speed, Weather w)
{
	if (w == Weather::Sunny)
		sunny_speed = speed;
	else if (w == Weather::Rain)
		rain_speed = speed;
	else if (w == Weather::Snow)
		snow_speed = speed;
}

int Fiat::getCapacity()
{
	return fuelCapacity;
}

int Fiat::getConsumtion()
{
	return fuelConsumtion;
}

int Fiat::getSpeed(Weather w)
{
	int speed = 0;
	if (w == Weather::Sunny)
		speed = sunny_speed;
	else if (w == Weather::Rain)
		speed = rain_speed;
	else if (w == Weather::Snow)
		speed = snow_speed;
	return speed;
}
std::string Fiat::getName()
{
	return "Fiat";
}
void Fiat::setTime(int time)
{
	this->timp = time;
}

int Fiat::getTime()
{
	return timp;
}