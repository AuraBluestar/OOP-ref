#pragma once
#include<iostream>
#include <ostream>

// implementati constructorii si functiile de mai jos
// toti constructorii care primesc id-uri ar trebuie sa aloce memorie dinamic si sa le copieze
// adaugati urmatoarele functii:
//       - get_books_count         -> returneaza numarul de carti
//       - get_book_id_by_index    -> returneaza cartea de pe indexul dat ca parametru, sau -1 daca nu exista
//       -> cele 2 functii ar trebuie sa faca codul de la final sa compileze

class MyLibrary {
    std::ostream& output_stream; // referinta la obiectul de afisare
    unsigned books_count;        // cate carti avem in vector, -1 daca nu avem nimic
    int* books;                  // vector de carti alocat dinamic

public:
    MyLibrary(std::ostream& output_stream);

    MyLibrary(std::ostream& output_stream, unsigned books_count, int* books);

    MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max);

    MyLibrary(std::ostream& output_stream, const char* books_values);

    MyLibrary(std::ostream& output_stream, unsigned books_count, ...);

    // initializeaza id-urile cu cele din initializer_list, si output_stream-ul cu std::cout
    MyLibrary(std::initializer_list<int> v);

    // nu modificati destructorul
    ~MyLibrary();

    // printeaza numarul de carti si id-urile cartilor in `output_stream`, NU LA CONSOLA
    // daca nu exista nicio carte, printeaza ca numarul de carti e -1

    void print_books() const ;

    // updateaza cartea de pe index-ul dat cu id-ul nou
    // nu face nimic daca indexul nu exista

    void update_book_id_by_index(unsigned book_index, int book_id);

    int get_books_count() const;

    int get_book_id_by_index(int index) const;

    MyLibrary(const MyLibrary& other);
};