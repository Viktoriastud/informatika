#pragma once
#include "header.h"

class CinemaDB {
public:
    CinemaDB(const std::string& path);

    void read (const std::string& path);
    void write(const std::string& path);

    void addMovie(Movie movie);
    void removeMovieById(int id);
    void editingByNumber(int id);
    void searchByName(std::string name);

    void print();

    template<typename T, typename GetField, typename Action>
    void searchByField(const T target, GetField getField, Action action);

    template<typename Condition, typename Action>
    void searchByCondition(Condition condition, Action action);

    ~CinemaDB();

private:
    std::string path;
    Movie*      movies = nullptr;
    int         size   = 0;
};

namespace Menu {
    void addMovie(CinemaDB& db);
    void printDB(CinemaDB& db);
    void deleteMovieByNumber(CinemaDB& db);
    void editingMovieByNumber(CinemaDB& db);
    void searchMovieByName(CinemaDB& db);
}