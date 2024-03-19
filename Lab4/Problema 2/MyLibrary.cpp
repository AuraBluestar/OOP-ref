#include "MyLibrary.h"
#include<iostream>
#include<ostream>
#include<cstdlib>
#include <cstdarg>


MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream) 
{
    books_count = 0;
    books=new int[books_count];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream)
{
    this->books_count = books_count;
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++)
    {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream)
{
    this->books_count = books_count;
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++)
    {
        this->books[i] = min + rand() % (max - min);
    }
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout)
{
    books_count = v.size();
    books = new int[books_count];
    std::copy(v.begin(), v.end(), books);
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    int book[1000]{};
    int count_books = 0;
    int nr = 0;
    for (int i = 0; i < std::strlen(books_values); i++)
    {
        if (books_values[i] != ';')
        {
            nr = nr * 10 + (books_values[i]-'0');
        }
        else
        {
            book[count_books++] = nr;
            nr = 0;
        }
        
    }
    book[count_books++] = nr;
    books = new int[count_books];
    for (int i = 0; i < count_books; i++)
    {
        books[i] = book[i];
    }
    books_count = count_books;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream)
{
    va_list args;
    va_start(args, books_count);
    this->books_count = books_count;
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++) 
    {
        books[i] = va_arg(args, int);
    }
    va_end(args);
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() const
{
    if(books_count==0)
        this->output_stream << "Found -1 books"<<std::endl;
    else
    {
        this->output_stream << "Found " << books_count << " books"<<std::endl;

        for (int i = 0; i < books_count; i++)
        {
            this->output_stream << " id: "<< books[i] << std::endl;
        }
        this->output_stream << std::endl;
    }

}

int MyLibrary::get_books_count() const
{
    return this->books_count;
}

int MyLibrary::get_book_id_by_index(int index) const
{
    if(index<books_count)
        return this->books[index];
    return -1;
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id)
{
    books[book_index] = book_id;
}

MyLibrary::MyLibrary(const MyLibrary& other): output_stream(other.output_stream), books_count(other.books_count) {
    books = new int[books_count];
    for (unsigned i = 0; i < books_count; ++i) {
        books[i] = other.books[i];
    }
}
