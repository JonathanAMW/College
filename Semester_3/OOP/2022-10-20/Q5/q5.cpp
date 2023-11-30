#include <iostream>


class DateTime
{
private:
    int day, month, year, hours, minutes, seconds;

public:
    void SetValue(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void SetValue(int day, int month, int year, int hours)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hours = hours;
    }

    void SetValue(int day, int month, int year, int hours, int minutes)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hours = hours;
        this->minutes = minutes;
    }

    void SetValue(int day, int month, int year, int hours, int minutes, int seconds)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
};