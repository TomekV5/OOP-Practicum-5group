#include <iostream>
#include "Reader.h"
#include "Book.h"

class Library {
private:
    int id;
    static int idCounter;
    char* name;
    Reader** readers;
    Book** books;
    size_t readersCount;
    size_t booksCount;
    size_t readersCapacity;
    size_t booksCapacity;

    void free();
    void copyFrom(const Library& other);
    void moveFrom(Library&& other) noexcept;
    void resizeReaders();
    void resizeBooks();
public:
    Library(const char* name);
    Library(const Library& other);
    Library(Library&& other) noexcept;
    Library& operator=(const Library& other);
    Library& operator=(Library&& other) noexcept;
    ~Library();

    Library& operator+=(Reader* reader);
    Library& operator+=(Book* book);
    Library& operator-=(Reader* reader);
    Library& operator-=(Book* book);
    double averageReadersPerBook() const;
    Reader* mostActiveReader() const;
    Book* mostReadBook() const;
    void findBooksByPages(int minPages, int maxPages) const;
    void findBooksByReaders(int minReaders, int maxReaders) const;
    void findBooksByAuthor(const char* author) const;
    void findBooksByName(const char* name) const;
    void printBooksByName() const;
    void printBooksByReaders() const;
    void printBooksByPages() const;
    void printReadersByName() const;
    void printReadersByReadBooks() const;
};