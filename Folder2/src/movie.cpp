#include "header.h"

std::string Movie::getName() const {
    return name;
}

float Movie::getPrice() const {
    return price;
}

std::string Movie::getDay() const {
    return day;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    std::cout << "Name:  ";
    os << movie.name << "\n";
    std::cout << "Price: ";
    os << movie.price << "\n";
    std::cout << "Day:   ";
    os << movie.day << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Movie& movie) {
    std::cout << "Enter name:  ";
    std::getline(is, movie.name);
    std::cout << "Enter price: ";
    is >> movie.price;
    std::cout << "Enter day:   ";
    is >> movie.day;
    return is;
}