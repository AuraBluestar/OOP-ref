#include "StringValue.h"

StringValue::StringValue(std::string sir)
{
	if(sir.size()<=255)
		this->sir = sir;
}

void StringValue::print(std::ostream& os) const
{
	os <<sir;
}
