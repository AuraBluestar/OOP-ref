#pragma once
#include <vector>
#include <stdexcept>

template <typename T>
class MyStack {
private:
    std::vector<T> data;

public:
    MyStack() = default;

    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        data.pop_back();
    }

    T& top() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    int getSize() const {
        return data.size();
    }
};

