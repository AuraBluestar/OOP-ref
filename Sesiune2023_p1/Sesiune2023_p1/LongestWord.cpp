#include "LongestWord.h"

LongestWord::LongestWord(const std::string& name)
{
	this->name = name;
}

std::string LongestWord::GetName() const
{
	return name;
}

void LongestWord::Compute(const std::string& text)
{
	int longest = 0;
	int count = 0;
	for (char ch : text)
	{
		if(ch != ' ') 
		{
			count++;
		}
		else 
		{
			if (count > longest)
				longest = count;
			count = 0;
		}		
	}
	std::cout << "Name:" << name << " => " << longest << std::endl;
}


