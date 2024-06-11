#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Procesor.h"
class Sentence
{
private:
	std::vector <Procesor*> procesators;
	std::string name;
public:
	Sentence(std::string name);
	void Run(std::string text);
	void RunAll();
	void ListAll();
	Sentence& operator+=(Procesor* procesor);
};

