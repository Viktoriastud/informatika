#include "header.h"

int main() {
    const std::string PATH = "./data/data.txt";
    CinemaDB db(PATH);

    bool run = true;
    while (run)
    {
        std::cout <<  "1 - Add movie     \n";
        std::cout <<  "2 - Remove movie  \n";
        std::cout <<  "3 - Movie editing \n";
        std::cout <<  "4 - Search by name\n";
        std::cout <<  "5 - Print database\n";
        std::cout <<  ">>> ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            Menu::addMovie(db);
            break;
        case 2:
            Menu::deleteMovieByNumber(db);
            break;
        case 3:
            Menu::editingMovieByNumber(db);
            break;
        case 4: 
            Menu::searchMovieByName(db);
            break;
        case 5:
            Menu::printDB(db);
            break;
        default:
            run = false;
        }

        std::cout << "Press Enter to continue...";
        std::cin.get();
        system("clear");
    }

    return 0;
}