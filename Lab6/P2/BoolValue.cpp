#include "BoolValue.h"

void BoolValue::print(std::ostream& os) const
{
	os << var ;
}

BoolValue::BoolValue(bool var)
{
	this->var = var;
}
