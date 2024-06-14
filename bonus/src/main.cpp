#include "Map.h"
#include "Vector.h"
#include "Stack.h"
#include "Deque.h"
#include "Set.h"
#include <iostream>


int main() {

    std::cout << "Exemplu vector: "<<std::endl;
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Elementele din vector: ";
    for (int i = 0; i < vec.getSize(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    vec.pop_back();

    std::cout << "Elementele din vector dupa pop: ";
    for (int i = 0; i < vec.getSize(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    vec[0] = 100;
    std::cout << "Elementele din vectorul modificat: ";
    for (int i = 0; i < vec.getSize(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;


    std::cout << "Exemplu map: "<<std::endl;
    MyMap<int, std::string> myMap;

    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");
    std::cout << "Elementele din map:\n";
    for (int i = 1; i <= 3; i++) {
        std::string value;
        if (myMap.find(i, value)) {
            std::cout << i << ": " << value << std::endl;
        }
    }

    myMap.erase(2);

    std::cout << "Elementele din map dupa stergerea elementului de pe pozitia 2:\n";
    for (int i = 1; i <= 3; ++i) {
        std::string value;
        if (myMap.find(i, value)) {
            std::cout << i << ": " << value << std::endl;
        }
        else {
            std::cout << i << ": not found" << std::endl;
        }
    }


    std::cout << "Exemplu deque: "<<std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);
    deque.push_front(2);

    std::cout << "Elementele din deque: ";
    for (int i = 0; i < deque.getSize(); ++i) {
        std::cout << deque.front() << " ";
        deque.pop_front();
    }
    std::cout << std::endl;

    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);
    deque.push_front(2);
    deque.pop_back();
    deque.pop_front();

    std::cout << "Elementele din deque dupa pop_back&pop_front: ";
    for (int i = 0; i < deque.getSize(); ++i) {
        std::cout << deque.front() << " ";
        deque.pop_front();
    }
    std::cout << std::endl;

    std::cout << "Exemplu stack: "<<std::endl;
    MyStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Elementul top: " << stack.top() << std::endl;
    std::cout << "Dimensiune stackului: " << stack.getSize() << std::endl;
    stack.pop();
    std::cout << "Elementul top dupa pop: " << stack.top() << std::endl;
    std::cout << "Dimensiunea stackului dupa pop: " << stack.getSize() << std::endl;
    stack.pop();
    stack.pop();
    std::cout << "Stack-ul este gol: " << (stack.empty() ? "Da" : "Nu") << std::endl;


    std::cout << "Exemplu set: "<<std::endl;
    MySet<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); 

    std::cout << "Elementele din set: ";
    for (int i = 0; i < mySet.getSize(); ++i) {
        std::cout << mySet[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elementul 20 este in set: " << (mySet.find(20) ? "Da" : "Nu") << std::endl;
    std::cout << "Elementul 40 este in set: " << (mySet.find(40) ? "Da" : "Nu") << std::endl;

    mySet.erase(20);
    std::cout << "Elementele din set dupa stergerea lui 20: ";
    for (int i = 0; i < mySet.getSize(); i++) {
        std::cout << mySet[i] << " ";
    }
    std::cout << std::endl;
    mySet.clear();
    std::cout << "Dimensiunea setului dupa golire: " << mySet.getSize() << std::endl;


    return 0;
}
