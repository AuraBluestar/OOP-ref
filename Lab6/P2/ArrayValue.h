#pragma once
#include "JsonValue.h"
#include <vector>
class ArrayValue : public JsonValue
{
private: 
	std::vector<JsonValue*> vector;
public:
	void add(JsonValue* val);
	void print(std::ostream& os) const;
	~ArrayValue();
};

