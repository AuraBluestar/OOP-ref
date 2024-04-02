#include "Seat.h"

Seat::Seat()
{
	fuelCapacity = 60;
	fuelConsumtion = 100;
	rain_speed = 90;
	snow_speed = 70;
	sunny_speed = 120;
	timp = 0;
}

void Seat::setCapacity(int capacity)
{
	fuelCapacity = capacity;
}

void Seat::setComsumtion(int consumtion)
{
	fuelConsumtion = consumtion;
}

void Seat::setSpeed(int speed, Weather w)
{
	if (w == Weather::Sunny)
		sunny_speed = speed;
	else if (w == Weather::Rain)
		rain_speed = speed;
	else if (w == Weather::Snow)
		snow_speed = speed;
}

int Seat::getCapacity()
{
	return fuelCapacity;
}

int Seat::getConsumtion()
{
	return fuelConsumtion;
}

int Seat::getSpeed(Weather w)
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
std::string Seat::getName()
{
	return "Seat";
}
void Seat::setTime(int time)
{
	this->timp = time;
}

int Seat::getTime()
{
	return timp;
}