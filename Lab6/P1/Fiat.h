#pragma once
#include "Car.h"
#include "Weather.h"
class Fiat : public Car
{
private:
	int fuelCapacity, fuelConsumtion;
	int rain_speed, snow_speed, sunny_speed;
	int timp;
public:
	Fiat();
	void setCapacity(int capacity);
	void setComsumtion(int consumtion);
	void setSpeed(int speed, Weather w);
	void setTime(int time);
	int getTime();
	int getCapacity();
	int getConsumtion();
	int getSpeed(Weather w);
	std::string getName();
};