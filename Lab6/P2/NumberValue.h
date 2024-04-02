#pragma once
#include "JsonValue.h"
class NumberValue : public JsonValue
{
private:
	double number;
public:
	NumberValue(double nr);
	void print(std::ostream& os) const override;
};

