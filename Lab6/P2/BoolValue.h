#pragma once
#include "JsonValue.h"
class BoolValue : public JsonValue
{
private:
	bool var;
public:
	void print(std::ostream& os) const override;
	BoolValue(bool var);
};

