#include "BMW.h"
BMW::BMW()
{
	fuelCapacity = 60;
	fuelConsumtion = 10;
	rain_speed = 90;
	snow_speed = 70;
	sunny_speed = 120;
	timp = 0;
}

void BMW::setCapacity(int capacity)
{
	fuelCapacity = capacity;
}

void BMW::setComsumtion(int consumtion)
{
	fuelConsumtion = consumtion;
}

void BMW::setSpeed(int speed, Weather w)
{
	if (w == Weather::Sunny)
		sunny_speed = speed;
	else if (w == Weather::Rain)
		rain_speed = speed;
	else if (w == Weather::Snow)
		snow_speed = speed;
}

void BMW::setTime(int time)
{
	this->timp = time;
}

int BMW::getTime()
{
	return timp;
}

int BMW::getCapacity()
{
	return fuelCapacity;
}

int BMW::getConsumtion()
{
	return fuelConsumtion;
}

int BMW::getSpeed(Weather w)
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

std::string BMW::getName()
{
	return "BMW";
}
