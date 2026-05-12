#include "Library.h"

void Library::free() {
    delete[] name;
    for (size_t i = 0; i < readersCount; i++) {
        delete readers[i];
    }
    delete[] readers;
    for (size_t i = 0; i < booksCount; i++) {
        delete books[i];
    }
    delete[] books;
}

void Library::copyFrom(const Library& other) {
    id = other.id;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    readersCount = other.readersCount;
    booksCount = other.booksCount;
    readersCapacity = other.readersCapacity;
    booksCapacity = other.booksCapacity;

    readers = new Reader*[readersCapacity];
    for (size_t i = 0; i < readersCount; i++) {
        readers[i] = new Reader(*other.readers[i]);
    }

    books = new Book*[booksCapacity];
    for (size_t i = 0; i < booksCount; i++) {
        books[i] = new Book(*other.books[i]);
    }
}

void Library::moveFrom(Library&& other) noexcept {
    id = other.id;
    name = other.name;
    readers = other.readers;
    books = other.books;
    readersCount = other.readersCount;
    booksCount = other.booksCount;
    readersCapacity = other.readersCapacity;
    booksCapacity = other.booksCapacity;

    other.name = nullptr;
    other.readers = nullptr;
    other.books = nullptr;
    other.readersCount = 0;
    other.booksCount = 0;
    other.readersCapacity = 0;
    other.booksCapacity = 0;
}

void Library::resizeReaders() {
    readersCapacity *= 2;
    Reader** newReaders = new Reader*[readersCapacity];
    for (size_t i = 0; i < readersCount; i++) {
        newReaders[i] = readers[i];
    }
    delete[] readers;
    readers = newReaders;
}

void Library::resizeBooks() {
    booksCapacity *= 2;
    Book** newBooks = new Book*[booksCapacity];
    for (size_t i = 0; i < booksCount; i++) {
        newBooks[i] = books[i];
    }
    delete[] books;
    books = newBooks;
}

Library::Library(const char* name) : id(idCounter++), readersCount(0), booksCount(0), readersCapacity(2), booksCapacity(2)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    readers = new Reader*[readersCapacity];
    books = new Book*[booksCapacity];
}

Library::Library(const Library& other) {
    copyFrom(other);
}

Library::Library(Library&& other) noexcept {
    moveFrom(std::move(other));
}

Library& Library::operator=(const Library& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Library& Library::operator=(Library&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}


Library::~Library() {
    free();
}

Library& Library::operator+=(Reader* reader)
{
    if (readersCount == readersCapacity) {
        resizeReaders();
    }
    readers[readersCount++] = reader;
    return *this;
}

Library& Library::operator+=(Book* book)
{
    if (booksCount == booksCapacity) {
        resizeBooks();
    }
    books[booksCount++] = book;
    return *this;
}

Library& Library::operator-=(Reader* reader)
{
    for (size_t i = 0; i < readersCount; i++) {
        if (readers[i] == reader) {
            delete readers[i];
            for (size_t j = i; j < readersCount - 1; j++) {
                readers[j] = readers[j + 1];
            }
            readers[--readersCount] = nullptr;
            break;
        }
    }
    return *this;
}

Library& Library::operator-=(Book* book)
{
    for (size_t i = 0; i < booksCount; i++) {
        if (books[i] == book) {
            delete books[i];
            for (size_t j = i; j < booksCount - 1; j++) {
                books[j] = books[j + 1];
            }
            books[--booksCount] = nullptr;
            break;
        }
    }
    return *this;
}

double Library::averageReadersPerBook() const {
    if (booksCount == 0) {
        return 0.0;
    }
    int totalReaders = 0;
    for (size_t i = 0; i < booksCount; i++) {
        totalReaders += books[i]->getReadersCnt();
    }
    return totalReaders * 1.0 / booksCount;
}

Reader* Library::mostActiveReader() const {
    if (readersCount == 0) {
        return nullptr;
    }
    Reader* mostActive = readers[0];
    for (size_t i = 1; i < readersCount; i++) {
        if (*readers[i] > *mostActive) {
            mostActive = readers[i];
        }
    }
    return mostActive;
}

Book* Library::mostReadBook() const {
    if (booksCount == 0) {
        return nullptr;
    }
    Book* mostRead = books[0];
    for (size_t i = 1; i < booksCount; i++) {
        if (*books[i] > *mostRead) {
            mostRead = books[i];
        }
    }
    return mostRead;
}

void Library::findBooksByPages(int minPages, int maxPages) const {
    for (size_t i = 0; i < booksCount; i++) {
        if (books[i]->getPagesCnt() >= minPages && books[i]->getPagesCnt() <= maxPages) {
            std::cout << *books[i] << std::endl;
        }
    }
}

void Library::findBooksByReaders(int minReaders, int maxReaders) const {
    for (size_t i = 0; i < booksCount; i++) {
        if (books[i]->getReadersCnt() >= minReaders && books[i]->getReadersCnt() <= maxReaders) {
            std::cout << *books[i] << std::endl;
        }
    }
}

void Library::findBooksByAuthor(const char* author) const {
    for (size_t i = 0; i < booksCount; i++) {
        if (strcmp(books[i]->getAuthor(), author) == 0) {
            std::cout << *books[i] << std::endl;
        }
    }
}

void Library::findBooksByName(const char* name) const {
    for (size_t i = 0; i < booksCount; i++) {
        if (strcmp(books[i]->getName(), name) == 0) {
            std::cout << *books[i] << std::endl;
        }
    }
}

void Library::printBooksByName() const {
    Book** sortedBooks = new Book*[booksCount];
    for (size_t i = 0; i < booksCount; i++) {
        sortedBooks[i] = books[i];
    }

    for (size_t i = 0; i < booksCount - 1; i++) {
        for (size_t j = 0; j < booksCount - i - 1; j++) {
            if (strcmp(sortedBooks[j]->getName(), sortedBooks[j + 1]->getName()) > 0) {
                std::swap(sortedBooks[j], sortedBooks[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < booksCount; i++) {
        std::cout << *sortedBooks[i] << std::endl;
    }

    for (size_t i = 0; i < booksCount; i++) {
        sortedBooks[i] = nullptr;
    }
    delete[] sortedBooks;
}

void Library::printBooksByReaders() const {
    Book** sortedBooks = new Book*[booksCount];
    for (size_t i = 0; i < booksCount; i++) {
        sortedBooks[i] = books[i];
    }

    for (size_t i = 0; i < booksCount - 1; i++) {
        for (size_t j = 0; j < booksCount - i - 1; j++) {
            if (*sortedBooks[j] < *sortedBooks[j + 1]) {
                std::swap(sortedBooks[j], sortedBooks[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < booksCount; i++) {
        std::cout << *sortedBooks[i] << std::endl;
    }

    for (size_t i = 0; i < booksCount; i++) {
        sortedBooks[i] = nullptr;
    }
    delete[] sortedBooks;
}

void Library::printBooksByPages() const {
    Book** sortedBooks = new Book*[booksCount];
    for (size_t i = 0; i < booksCount; i++) {
        sortedBooks[i] = books[i];
    }

    for (size_t i = 0; i < booksCount - 1; i++) {
        for (size_t j = 0; j < booksCount - i - 1; j++) {
            if (sortedBooks[j]->getPagesCnt() > sortedBooks[j + 1]->getPagesCnt()) {
                std::swap(sortedBooks[j], sortedBooks[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < booksCount; i++) {
        std::cout << *sortedBooks[i] << std::endl;
    }

    for (size_t i = 0; i < booksCount; i++) {
        sortedBooks[i] = nullptr;
    }
    delete[] sortedBooks;
}

void Library::printReadersByName() const {
    Reader** sortedReaders = new Reader*[readersCount];
    for (size_t i = 0; i < readersCount; i++) {
        sortedReaders[i] = readers[i];
    }

    for (size_t i = 0; i < readersCount - 1; i++) {
        for (size_t j = 0; j < readersCount - i - 1; j++) {
            if (strcmp(sortedReaders[j]->getName(), sortedReaders[j + 1]->getName()) > 0) {
                std::swap(sortedReaders[j], sortedReaders[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < readersCount; i++) {
        std::cout << *sortedReaders[i] << std::endl;
    }

    for (size_t i = 0; i < readersCount; i++) {
        sortedReaders[i] = nullptr;
    }
    delete[] sortedReaders;
}


void Library::printReadersByReadBooks() const {
    Reader** sortedReaders = new Reader*[readersCount];
    for (size_t i = 0; i < readersCount; i++) {
        sortedReaders[i] = readers[i];
    }

    for (size_t i = 0; i < readersCount - 1; i++) {
        for (size_t j = 0; j < readersCount - i - 1; j++) {
            if (*sortedReaders[j] < *sortedReaders[j + 1]) {
                std::swap(sortedReaders[j], sortedReaders[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < readersCount; i++) {
        std::cout << *sortedReaders[i] << std::endl;
    }

    for (size_t i = 0; i < readersCount; i++) {
        sortedReaders[i] = nullptr;
    }
    delete[] sortedReaders;
}