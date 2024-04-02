#include "ArrayValue.h"

void ArrayValue::add(JsonValue* val)
{
	if(vector.size()<16)
		vector.push_back(val);
}

void ArrayValue::print(std::ostream& os) const
{
    os << "[";
    if (!vector.empty()) {
        vector[0]->print(os); 
        for (size_t i = 1; i < vector.size(); ++i) {
            os << ", ";
            vector[i]->print(os); 
        }
    }
    os << "]";
}

ArrayValue::~ArrayValue()
{
	for (auto& element : vector) {
		delete element;
	}
	vector.clear();
}
