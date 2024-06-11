#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "Procesor.h"

class CountLetter: public Procesor
{
private:
    std::string name;
    std::function<bool(char)> predicate;

public:
    CountLetter(const std::string& name, std::function<bool(char)> predicate);
    std::string GetName() const override;
    void Compute(const std::string& text) override;
};

