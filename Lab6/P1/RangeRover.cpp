#include "RangeRover.h"

RangeRover::RangeRover()
{
	fuelCapacity = 60;
	fuelConsumtion = 10;
	rain_speed = 90;
	snow_speed = 70;
	sunny_speed = 120;
	timp = 0;
}

void RangeRover::setCapacity(int capacity)
{
	fuelCapacity = capacity;
}

void RangeRover::setComsumtion(int consumtion)
{
	fuelConsumtion = consumtion;
}

void RangeRover::setSpeed(int speed, Weather w)
{
	if (w == Weather::Sunny)
		sunny_speed = speed;
	else if (w == Weather::Rain)
		rain_speed = speed;
	else if (w == Weather::Snow)
		snow_speed = speed;
}

int RangeRover::getCapacity()
{
	return fuelCapacity;
}

int RangeRover::getConsumtion()
{
	return fuelConsumtion;
}

int RangeRover::getSpeed(Weather w)
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
std::string RangeRover::getName()
{
	return "RangeRover";
}
void RangeRover::setTime(int time)
{
	this->timp = time;
}

int RangeRover::getTime()
{
	return timp;
}