#include "Book.h"

void Book::free()
{
    delete[] name;
    delete[] author;
}

void Book::copyFrom(const Book& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    author = new char[strlen(other.author) + 1];
    strcpy(author, other.author);

    readersCnt = other.readersCnt;
    pagesCnt = other.pagesCnt;
}

void Book::moveFrom(Book&& other)
{
    name = other.name;
    author = other.author;
    readersCnt = other.readersCnt;
    pagesCnt = other.pagesCnt;

    other.name = nullptr;
    other.author = nullptr;
}

Book::Book(const char* name, const char* author, int pagesCnt)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->author = new char[strlen(author) + 1];
    strcpy(this->author, author);

    this->pagesCnt = pagesCnt;
    this->readersCnt = 0;
}

Book::Book(const Book& other)
{
    copyFrom(other);
}

Book::Book(Book&& other) noexcept
{
    moveFrom(std::move(other));
}

Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Book& Book::operator=(Book&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Book::~Book()
{
    free();
}

auto Book::operator<=>(const Book& other) const
{
    return readersCnt <=> other.readersCnt;
}

bool Book::operator==(const Book& other) const
{
    return readersCnt == other.readersCnt;
}

Book& Book::operator++()
{
    ++readersCnt;
    return *this;
}

Book Book::operator++(int)
{
    Book temp = *this;
    ++readersCnt;
    return temp;
}

int Book::getReadersCnt() const
{
    return readersCnt;
}

int Book::getPagesCnt() const
{
    return pagesCnt;
}

const char* Book::getName() const
{
    return name;
}

const char* Book::getAuthor() const
{
    return author;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "Name: " << book.name << ", Author: " << book.author << ", Pages: " << book.pagesCnt << ", Readers: " << book.readersCnt;
    return os;
}
