// Copywrite 2021 Evan Scales

#include <iostream>
#include "./functions.h"
// #include "./package.h"
// #include "./container.h"
// #include "./plane.h"
#include <unordered_map>
#include <string>
#include <iostream>

using std::string;


int main(int argc, char const *argv[])
{
    bool quit = false;
    greet();
    // selectAirport();
    while(!quit) {
        printOptions();
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            scanPackages();

            break;
        case 0:
            quit = true;
            std::cout << "Exiting" << "\n";
            break;
            default:
                std::cout << "Invalid option, try again" << "\n";
        }
    }

    return 0;
}