#include "ObjectValue.h"
#include <utility>

ObjectValue::~ObjectValue()
{
	for (auto& element : vector) 
		delete element.second;
	vector.clear();
}

void ObjectValue::add(const std::string& name, JsonValue* val)
{
	if (vector.size() < 16)
	{
		std::pair<std::string, JsonValue*> temp;
		temp.first = name;
		temp.second = val;
		vector.push_back(temp);
	}
}

void ObjectValue::print(std::ostream& os) const
{
    os << "{";
    if (!vector.empty()) {
        os << "\"" << vector[0].first << "\": ";
        vector[0].second->print(os); 
        for (size_t i = 1; i < vector.size(); ++i) {
            os << ", "; 
            os << "\"" << vector[i].first << "\": ";
            vector[i].second->print(os); 
        }
    }
    os << "}";
}
