// Chiriac Teodora
#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n; j+) {
            if (arr[j] < arr[j + 1]) { 
                arr[j] = arr[j + 1];   
            }
        }
    }
}

int main() {
    std::vector<int> vec = { 5, 10, 2, 1 };
    bubbleSort(vec);
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}
