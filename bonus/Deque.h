#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class MyDeque {
private:
    T* data;
    int capacity;
    int frontIndex;
    int backIndex;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[(frontIndex + i) % capacity];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
        frontIndex = 0;
        backIndex = size - 1;
    }

public:
    MyDeque() : capacity(4), frontIndex(0), backIndex(0), size(0) {
        data = new T[capacity];
    }

    ~MyDeque() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        backIndex = (backIndex + 1) % capacity;
        data[backIndex] = value;
        ++size;
    }

    void push_front(const T& value) {
        if (size == capacity) {
            resize();
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = value;
        ++size;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        backIndex = (backIndex - 1 + capacity) % capacity;
        --size;
    }

    void pop_front() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        --size;
    }

    T& front() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return data[frontIndex];
    }

    T& back() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return data[backIndex];
    }

    int getSize() const {
        return size;
    }
};
