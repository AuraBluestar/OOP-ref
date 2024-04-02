#pragma once
#include "Weather.h"
#include <string>
#include <string.h>
#include <string>
class Car
{
private:
	int fuelCapacity=0, fuelConsumtion=0;
	int rain_speed=0, snow_speed=0, sunny_speed=0;
	int timp=0;
public:
	virtual void setCapacity(int capacity) =0;
	virtual void setComsumtion(int consumtion)=0;
	virtual void setSpeed(int speed, Weather w)=0;
	virtual void setTime(int time)=0;
	virtual int getCapacity()=0;
	virtual int getConsumtion()=0;
	virtual int getSpeed(Weather w)=0;
	virtual int getTime()=0;
	virtual std::string getName() = 0;
};