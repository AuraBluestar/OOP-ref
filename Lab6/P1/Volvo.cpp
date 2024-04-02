#include "Volvo.h"

Volvo::Volvo()
{
	fuelCapacity = 60;
	fuelConsumtion = 10;
	rain_speed = 90;
	snow_speed = 70;
	sunny_speed = 120;
	timp = 0;
}

void Volvo::setCapacity(int capacity)
{
	fuelCapacity = capacity;
}

void Volvo::setComsumtion(int consumtion)
{
	fuelConsumtion = consumtion;
}

void Volvo::setSpeed(int speed, Weather w)
{
	if (w == Weather::Sunny)
		sunny_speed = speed;
	else if (w == Weather::Rain)
		rain_speed = speed;
	else if (w == Weather::Snow)
		snow_speed = speed;
}

int Volvo::getCapacity()
{
	return fuelCapacity;
}

int Volvo::getConsumtion()
{
	return fuelConsumtion;
}

int Volvo::getSpeed(Weather w)
{
	int speed=0;
	if (w == Weather::Sunny)
		speed=sunny_speed;
	else if (w == Weather::Rain)
		speed=rain_speed;
	else if (w == Weather::Snow)
		speed=snow_speed;
	return speed;
}
std::string Volvo::getName()
{
	return "Volvo";
}
void Volvo::setTime(int time)
{
	this->timp = time;
}

int Volvo::getTime()
{
	return timp;
}