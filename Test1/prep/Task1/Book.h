#pragma once
#include <iostream>
#include <cstring>

class Book
{
private:
    char* name;
    char* author;
    int readersCnt;
    int pagesCnt;

    void free();
    void copyFrom(const Book& other);
    void moveFrom(Book&& other);

public:
    Book(const char* name, const char* author, int pagesCnt);
    Book(const Book& other);
    Book(Book&& other) noexcept;
    Book& operator=(const Book& other);
    Book& operator=(Book&& other) noexcept;
    ~Book();

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    auto operator<=>(const Book& other) const;
    bool operator==(const Book& other) const;
    Book& operator++();   // prefix
    Book operator++(int); // postfix
    int getReadersCnt() const;
    int getPagesCnt() const;
    const char* getName() const;
    const char* getAuthor() const;
};