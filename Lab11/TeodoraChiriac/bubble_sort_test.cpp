//Onisor Maria-Patricia
#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) { 
                arr[j] = arr[j + 1];   
            }
        }
    }
}

int main() {
    std::vector<int> vec = { 4, 3, 2, 1 };
    bubbleSort(vec);

    bool sorted = true;
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            sorted = false;
            break;
        }
    }

    if (!sorted) {
        std::cout << "Sorting algorithm failed." << std::endl;
    }
    else {
        std::cout << "Sorting algorithm succeeded." << std::endl;
    }

    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}
