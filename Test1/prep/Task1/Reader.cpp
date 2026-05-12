#include "Reader.h"

void Reader::free()
{
    delete[] name;
    for (size_t i = 0; i < booksCount; ++i)
    {
        delete books[i];
    }
    delete[] books;
}

void Reader::copyFrom(const Reader &other)
{
    id = other.id;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    booksCount = other.booksCount;
    booksCapacity = other.booksCapacity;
    books = new Book *[booksCapacity];
    for (size_t i = 0; i < booksCount; ++i)
    {
        books[i] = new Book(*other.books[i]);
    }
}

void Reader::moveFrom(Reader &&other) noexcept
{
    id = other.id;
    name = other.name;
    books = other.books;
    booksCount = other.booksCount;
    booksCapacity = other.booksCapacity;

    other.name = nullptr;
    other.books = nullptr;
    other.booksCount = 0;
    other.booksCapacity = 0;
}

void Reader::resizeBooks()
{
    booksCapacity *= 2;
    Book **newBooks = new Book *[booksCapacity];
    for (size_t i = 0; i < booksCount; ++i)
    {
        newBooks[i] = books[i];
    }
    delete[] books;
    books = newBooks;
}

Reader::Reader(const char *name) : id(idCounter++), booksCount(0), booksCapacity(2)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    books = new Book *[booksCapacity];
}

Reader::Reader(const Reader &other)
{
    copyFrom(other);
}

Reader::Reader(Reader &&other) noexcept
{
    moveFrom(std::move(other));
}

Reader &Reader::operator=(const Reader &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Reader &Reader::operator=(Reader &&other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Reader::~Reader()
{
    free();
}

std::ostream &operator<<(std::ostream &os, const Reader &reader)
{
    os << "Name: " << reader.name << ", Books Count: " << reader.booksCount;
    return os;
}

auto Reader::operator<=>(const Reader &other) const
{
    return booksCount <=> other.booksCount;
}

bool Reader::operator==(const Reader &other) const
{
    return booksCount == other.booksCount;
}

bool Reader::operator!() const
{
    return booksCount;
}

Reader &Reader::operator+=(Book *book)
{
    if (booksCount == booksCapacity)
    {
        resizeBooks();
    }
    books[booksCount++] = book;
    return *this;
}

bool Reader::operator()(const char *bookTitle) const
{
    for (size_t i = 0; i < booksCount; ++i)
    {
        if (strcmp(books[i]->name, bookTitle) == 0)
        {
            return true;
        }
    }
    return false;
}

Book *Reader::operator[](size_t index) const
{
    if (index >= booksCount)
    {
        return nullptr;
    }
    return books[index];
}

const char *Reader::getName() const
{
    return name;
}