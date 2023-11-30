#pragma once

#include <iostream>

class C_Book
{
protected:
    std::string title;
    std::string author;
public:
    //prototypes
    std::string getTitle();
    void setTitle(std::string);
    std::string getAuthor();
    void setAuthor(std::string);
};

//inheritance classes
class C_Fiction : public C_Book
{
private:
    int readingLevel;

public:
    int getReadingLevel();
    void setReadingLevel(int);
    void showBookInformation();
};

class C_NonFiction : public C_Book
{
private:
    int numberOfPages;

public:
    int getNumberOfPages();
    void setNumberOfPages(int);
    void showBookInformation();
};
