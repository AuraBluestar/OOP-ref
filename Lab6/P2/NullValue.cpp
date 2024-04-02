#include "NullValue.h"
#include "JsonValue.h"

void NullValue::print(std::ostream& os) const
{
	os << "null";
}
