#include "Sentence.h"

Sentence::Sentence(std::string name)
{
    this->name = name;
}

void Sentence::Run(std::string text)
{
    for (Procesor* procesator : procesators)
    {
        if (procesator->GetName() == text)
        {
            procesator->Compute(this->name);
        }
    }
}

void Sentence::RunAll()
{
    for (Procesor* procesator : procesators)
    {
        procesator->Compute(this->name);
    }
}

void Sentence::ListAll()
{
    for (Procesor* procesator : procesators) 
    {
        std::cout << "Name:" << procesator->GetName()<<std::endl;
    }
}

Sentence& Sentence::operator+=(Procesor* procesor)
{
    this->procesators.push_back(procesor);
    return *this;
}
