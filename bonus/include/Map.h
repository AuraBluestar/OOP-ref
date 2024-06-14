#pragma once
#include <vector>
#include <utility>

template <typename Key, typename Value>
class MyMap {
private:
    std::vector<std::pair<Key, Value>> data;

public:
    MyMap() = default;

    void insert(const Key& key, const Value& value) {
        for (auto& pair : data) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        data.push_back(std::make_pair(key, value));
    }

    bool find(const Key& key, Value& value) const {
        for (const auto& pair : data) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    void erase(const Key& key) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                return;
            }
        }
    }

    int getSize() const {
        return data.size();
    }
};