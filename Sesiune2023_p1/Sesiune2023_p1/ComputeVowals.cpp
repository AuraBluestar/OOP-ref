#include "ComputeVowals.h"

ComputeVowals::ComputeVowals(const std::string name)
{
	this->name = name;
}

std::string ComputeVowals::GetName() const
{
	return name;
}

void ComputeVowals::Compute(const std::string& text)
{
	int count = 0;
	for (char ch : text)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			count++;
	}
	std::cout << "Name:" << name << " => " << count<<std::endl;
}
