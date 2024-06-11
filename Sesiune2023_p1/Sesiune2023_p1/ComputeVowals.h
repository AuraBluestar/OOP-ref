#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Procesor.h"

class ComputeVowals : public Procesor
{
private:
	std::string name;
public:
	ComputeVowals(const std::string name);
	std::string GetName() const override;
	void Compute(const std::string& text) override;
};

