#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Procesor.h"

class LongestWord : public Procesor
{
private:
	std::string name;
public:
	LongestWord(const std::string& name);
	std::string GetName() const override;
	void Compute(const std::string& text) override;
};

