#include "header.h"

CinemaDB::CinemaDB(const std::string& path) : path(path) {
    read(path);
}

void CinemaDB::read(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        std::cerr << "Unable to open file: " << path << '\n';
        return;
    }

    in >> size;
    in.ignore();
    movies = new Movie[size];
    for (int i = 0; i < size; ++i) {
        in >> movies[i];
        in.ignore();
        std::cout << "\r" << std::string(50, ' ') << "\r";
    }
    std::cout << size << " values loaded!\n";
    
    in.close();
}

void CinemaDB::write(const std::string& path) {
    std::ofstream out(path);
    if (!out.is_open()) {
        std::cerr << "Unable to open file: " << path << '\n';
        return;
    }

    out << size << '\n';
    for (int i = 0; i < size; ++i) {
        out << movies[i];
        std::cout << "\r" << std::string(50, ' ') << "\r";
    }
    std::cout << "Save DB!\n";

    out.close();
}

void CinemaDB::addMovie(Movie movie) {
    size++;
    Movie* temp = new Movie[size];

    for (int i = 0; i < size - 1; ++i) {
        temp[i] = movies[i];
    }
    temp[size - 1] = movie;

    delete[] movies;
    movies = temp;
}

void CinemaDB::removeMovieById(int id) {
    if (id < 0 || id >= size) {
        std::cout << "Invalid movie ID!" << std::endl;
        return;
    }

    Movie* temp = new Movie[size - 1];
    for (int i = 0; i < id; ++i) {
        temp[i] = movies[i];
    }
    for (int i = id + 1; i < size; ++i) {
        temp[i - 1] = movies[i];
    }

    delete[] movies;
    
    movies = temp;
    size--;
}

void CinemaDB::editingByNumber(int id) {
    if (id < 0 || id >= size) {
        std::cout << "Invalid movie ID!" << std::endl;
        return;
    }
    std::cout << "last\n";
    std::cout << movies[id];
    std::cout << "new\n";
    std::cin >> movies[id];
    std::cin.ignore();
}

void CinemaDB::searchByName(std::string name) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (name == movies[i].getName()) {
            std::cout << "№ " << i + 1 << "\n";
            std::cout << movies[i];
            found = true;
        }
    }
    if (!found) {
        std::cout << "Nothing found!!!\n";
    }
}

void CinemaDB::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << "№ " << i + 1 << '\n';
        std::cout << movies[i];
    }
}

CinemaDB::~CinemaDB() {
    write(path);
    delete[] movies;
}

void Menu::addMovie(CinemaDB& db) {
    Movie newMovie;
    std::cin >> newMovie;
    std::cin.ignore();
    db.addMovie(newMovie);
}

void Menu::printDB(CinemaDB& db) {
    db.print();
}

void Menu::deleteMovieByNumber(CinemaDB& db) {
    std::cout << "Enter the movie number: ";
    int id;
    std::cin >> id;
    std::cin.ignore();
    db.removeMovieById(id - 1);
}

void Menu::editingMovieByNumber(CinemaDB& db) {
    std::cout << "Enter the movie number: ";
    int id;
    std::cin >> id;
    std::cin.ignore();
    db.editingByNumber(id - 1);
}

void Menu::searchMovieByName(CinemaDB& db) {
    std::cout << "Enter the movie name: ";
    std::string name;
    getline(std::cin, name);
    db.searchByName(name);
}