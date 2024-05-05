#include <iostream>
template< typename K, typename V>

class Map
{
private:
    struct Pair {
        K key;
        V value;
    };

    Pair* data;
    size_t size;
    size_t capacity;
public:
    Map() {
        capacity = 10;
        size = 0;
        data = new Pair[capacity];
    }

    ~Map() {
        delete[] data;
    }

    void Set(const K& key, const V& value) {
        // If key already exists in map, replace its value
        for (size_t i = 0; i < size; i++) {
            if (data[i].key == key) {
                data[i].value = value;
                return;
            }
        }

        // If key doesn't exist in map, add new pair
        if (size == capacity) {
            capacity *= 2;
            Pair* newData = new Pair[capacity];
            for (size_t i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

        data[size].key = key;
        data[size].value = value;
        size++;
    }

    bool Get(const K& key, V& value) const {
        for (size_t i = 0; i < size; i++) {
            if (data[i].key == key) {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }

    size_t Count() const {
        return size;
    }

    void Clear() {
        size = 0;
    }

    bool Delete(const K& key) {
        for (size_t i = 0; i < size; i++) {
            if (data[i].key == key) {
                data[i] = data[size - 1]; // replace with last pair in array
                size--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const {
        for (size_t i = 0; i < other.size; i++) {
            V value;
            if (!Get(other.data[i].key, value) || value != other.data[i].value) {
                return false;
            }
        }
        return true;
    }

    // Iterator class for iterating over Map using range-based for loop
    class Iterator {
    private:
        Pair* ptr;

    public:
        Iterator(Pair* p) : ptr(p) {}

        Iterator operator++() {
            ptr++;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        auto operator*() const {
            return std::make_tuple(ptr->key, ptr->value, std::distance(data, ptr));
        }
    };

    Iterator begin() const {
        return Iterator(data);
    }

    Iterator end() const {
        return Iterator(data + size);
    }

    V& Map<K, V>::operator[](const K& key)
    {
        auto it = find_key(key);
        if (it == data.end()) {
            // key not found, insert a new element
            data.push_back(std::make_pair(key, V{}));
            return data.back().second;
        }
        else {
            // key found, return the corresponding value
            return it->second;
        }
    }
};


int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
