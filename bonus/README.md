# Rezolvarea temei bonus in valoare de 5 puncte
Am făcut 5 containere stl:
- vector
- map
- set
- stack
- deque

# Echipa:
- Chiriac Teodora
- Doltu Teodora - Eliza
- Onișor Maria-Patricia
- Panaite Alexandra-Mihaela

# Organizare in foldere:
- include:
  1. Map.h
  2. Vector.h
  3. Set.h
  4. Stack.h
  5. Deque.h
- src:
  1. main.cpp
- tests:
  1. Deque_TEST.cc
  2. Map_TEST.cc
  3. Vector_TEST.cc
  4. Set_TEST.cc
  5. Stack_TEST.cc

## Materials
- Documents :
    > - [`Quickstart: CMake`](https://google.github.io/googletest/quickstart-cmake.html)

## Commands:
- cmake -S . -B build
- cmake --build build
- ctest --verbose 
