#pragma once
#include <iostream>
#include <cstring>
#include "Book.h"


class Reader
{
private:
    int id;
    static int idCounter;
    char* name;
    Book** books;
    size_t booksCount;
    size_t booksCapacity;

    void free();
    void copyFrom(const Reader& other);
    void moveFrom(Reader&& other) noexcept;
    void resizeBooks();

public:
    Reader(const char* name);
    Reader(const Reader& other);
    Reader(Reader&& other) noexcept;
    Reader& operator=(const Reader& other);
    Reader& operator=(Reader&& other) noexcept;
    ~Reader();

    friend std::ostream &operator<<(std::ostream& os, const Reader& reader);
    auto operator<=>(const Reader& other) const;
    bool operator==(const Reader& other) const;
    bool operator!() const;
    Reader& operator+=(Book* book);
    bool operator()(const char* bookTitle) const;
    Book* operator[](size_t index) const;

    const char* getName() const;

};