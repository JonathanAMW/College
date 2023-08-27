#include <iostream>

#include "Book.h"

int main()
{
    C_Fiction book_1;
    std::cout << "Book 1: \n";
    book_1.setTitle("Kastil Terbalik");
    book_1.setAuthor("Arunika");
    book_1.setReadingLevel(100);
    book_1.showBookInformation();

    std::cout << "\n";

    C_NonFiction book_2;
    std::cout << "Book 2: \n";
    book_2.setTitle("Autobiografi Alex");
    book_2.setAuthor("Alex Sumaleks");
    book_2.setNumberOfPages(90);
    book_2.showBookInformation();

    return 0;
}