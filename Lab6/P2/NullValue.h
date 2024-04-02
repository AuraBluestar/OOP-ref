#pragma once
#include "JsonValue.h"
class NullValue : public  JsonValue
{
public:
	void print(std::ostream& os) const override;
};

