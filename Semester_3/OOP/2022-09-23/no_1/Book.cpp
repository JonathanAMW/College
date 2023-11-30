#include <iostream>

#include "Book.h"

//class book methods
std::string C_Book::getTitle()
{
    return this->title;
}

void C_Book::setTitle(std::string title)
{
    this->title = title;
}

std::string C_Book::getAuthor()
{
    return this->author;
}

void C_Book::setAuthor(std::string author)
{
    this->author = author;
}


//class fiction methods
int C_Fiction::getReadingLevel()
{
    return this->readingLevel;
}

void C_Fiction::setReadingLevel(int readingCount)
{
    this->readingLevel = readingCount;
}

void C_Fiction::showBookInformation()
{
    std::cout << "Judul             : "<< getTitle() << "\n";
    std::cout << "Penulis           : "<< getAuthor() << "\n";
    std::cout << "Tingkat Membaca   : "<< getReadingLevel() << "\n";
}


//class non fiction methods
int C_NonFiction::getNumberOfPages()
{
    return this->numberOfPages;
}

void C_NonFiction::setNumberOfPages(int numberOfPages)
{
    this->numberOfPages = numberOfPages;
}

void C_NonFiction::showBookInformation()
{
    std::cout << "Judul             : "<< getTitle() << "\n";
    std::cout << "Penulis           : "<< getAuthor() << "\n";
    std::cout << "Jumlah Halaman    : "<< getNumberOfPages() << "\n";
}