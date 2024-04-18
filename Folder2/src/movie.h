#pragma once
#include "header.h"

class Movie {
private:
	std::string name;
	float       price;
	std::string day;

public:
    std::string getName () const;
    float       getPrice() const;
    std::string getDay  () const;

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    friend std::istream& operator>>(std::istream& is,       Movie& movie);
};