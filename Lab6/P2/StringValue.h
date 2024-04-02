#pragma once
#include "JsonValue.h"
class StringValue : public JsonValue
{
private:
	std::string sir;
public:
	StringValue(std::string sir);
	void print(std::ostream& os) const override;
};

