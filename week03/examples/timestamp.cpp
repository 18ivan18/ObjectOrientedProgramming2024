#include <iostream>
#include <cassert>

/*
 * Реализирайте клас, представящ времева марка (Timestamp) с полета за часове, минути и секунди.
 * Напишете функции за създаване на времева марка по подадени секунди, извеждане във формат HH:MM:SS,
 * събиране на две времеви марки, преобразуване на времева марка обратно в секунди.
 */

class Timestamp
{
public:
    void setFromSeconds(const unsigned int seconds)
    {
        // 3750 / 3600 = 1
        // 3750 % 3600 = 150
        // 150 / 60 = 2
        // 150 % 60 = 30

        this->hours = seconds / this->SECONDS_IN_HOUR;
        int seconds_left = seconds % this->SECONDS_IN_HOUR;
        this->minutes = seconds_left / this->SECONDS_IN_MINUTE;
        this->seconds = seconds_left % this->SECONDS_IN_MINUTE;
    }

    void print() const
    {
        this->prettyPrint(this->hours);
        std::cout << ":";
        this->prettyPrint(this->minutes);
        std::cout << ":";
        this->prettyPrint(this->seconds);
        std::cout << '\n';
    }

    void add(const Timestamp &other)
    {
        unsigned int seconds_in_first = this->toSeconds();
        unsigned int second_in_second = other.toSeconds();

        this->setFromSeconds(seconds_in_first + second_in_second);
    }

    unsigned int toSeconds() const
    {
        return this->hours * this->SECONDS_IN_HOUR + this->minutes * this->SECONDS_IN_MINUTE + this->seconds;
    }

private:
    void prettyPrint(unsigned int timeToPrint) const
    {
        if (timeToPrint < 10)
        {
            std::cout << "0";
        }
        std::cout << timeToPrint;
    }
    const int SECONDS_IN_HOUR = 3600;
    const int SECONDS_IN_MINUTE = 60;
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};

int main()
{
    Timestamp t1, t2;
    t1.setFromSeconds(420);
    t2.setFromSeconds(69);
    t1.print();
    t2.print();
    t1.add(t2);
    assert(t1.toSeconds() == 489);
}