#include "NumberValue.h"

NumberValue::NumberValue(double nr)
{
	number = nr;
}

void NumberValue::print(std::ostream& os) const
{
	os << number;
}
