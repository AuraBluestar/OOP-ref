#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class MySet {
private:
    std::vector<T> data;

public:
    MySet() = default;

    void insert(const T& value) {
        if (std::find(data.begin(), data.end(), value) == data.end()) {
            data.push_back(value);
            std::sort(data.begin(), data.end());
        }
    }

    void erase(const T& value) {
        auto it = std::find(data.begin(), data.end(), value);
        if (it != data.end()) {
            data.erase(it);
        }
    }

    bool find(const T& value) const {
        return std::find(data.begin(), data.end(), value) != data.end();
    }

    int getSize() const {
        return data.size();
    }

    void clear() {
        data.clear();
    }

    const T& operator[](size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

