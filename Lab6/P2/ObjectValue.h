#pragma once
#include "JsonValue.h"
#include <vector>
#include <utility>
class ObjectValue : public JsonValue
{
private:
    std::vector<std::pair<std::string, JsonValue*>> vector;
public:
    ~ObjectValue();
    void add(const std::string& name, JsonValue* val);
    void print(std::ostream& os) const override;
};

