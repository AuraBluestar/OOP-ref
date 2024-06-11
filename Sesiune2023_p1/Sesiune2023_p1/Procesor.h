#pragma once
#include <iostream>
#include <vector>
#include <string>
class Procesor
{
public:
	virtual ~Procesor() = default;
	virtual std::string GetName()const = 0;
	virtual void Compute(const std::string& text) = 0;
};

