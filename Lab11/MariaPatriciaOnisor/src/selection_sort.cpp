// Onisor Maria Patricia
#include <vector>
#include <iostream>
template<typename T>
void selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);  
            }
        }
    }
}
template void selectionSort<int>(std::vector<int>&);


int main() {
    std::vector<int> vec = { 4, 3, 2, 1 };
    selectionSort(vec);
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}
