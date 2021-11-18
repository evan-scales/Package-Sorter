#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
// Copyright 2021 Evan Scales
#include "./package.h"
#include "./container.h"
#include "./plane.h"
#include "./airport.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

// Variables
Airport airport(1);
int CAPICITY = 4;

// Prototypes
void greet();
void printOptions();
void scanPackages();
void scanLIBs();
void scanULD();
void addULD();
void removePackages();
void sendPlane();

// Start Functions
void greet() {
    std::cout << "Welcome to package sorter 1.0" << "\n";
    // std::cout << "Please select your airport" << "\n";
}
// void selectAirport() {
//     std::cout << "Enter 1 for CLT" << "\n";
//     bool option = false;
//     while (!option) {
//         int input;
//         std::cin >> input;
//         if (input == 1) {
//             airport = Airport(1);
//             option = true;
//         } else {
//             std::cout << "Please choose an airport\n";
//         }
//     }
// }
void printOptions() {
    std::cout << "Enter 1 to scan packages" << "\n";
    std::cout << "Enter 2 to scan new ULD" << "\n";
    std::cout << "Enter 3 to scan LIB packages" << "\n";
    std::cout << "Enter 4 to send off a plane" << "\n";
    std::cout << "Enter 5 to add ULD to plane" << "\n";
    std::cout << "Enter 6 to remove packages from ULD" << "\n";
    std::cout << "Enter 7 to run tests" << "\n";
    std::cout << "Enter 0 to quit" << "\n";
    // airport.printAllContainers();
}
void scanPackages() {
    bool scan = true;
    std::cout << "Enter O(or o) to stop and return to options\n";
    while(scan) {
        std::cout << "Scan package ID,ZIPCODE,WEIGHT,VOLUME\n";
        std::string input;
        std::cin >> input;
        if (input != "O" && input != "o") {
            try {
                std::string token = "";
                std::stringstream s_line(input);
                std::vector<std::string> vect;
                while (getline(s_line, token, ',')) {
                    vect.push_back(token);
                }

                std::string id = vect[0];
                std::string zip = vect[1];
                int weight = std::stoi(vect[2]);
                int volume = std::stoi(vect[3]);

                Package p(id, zip, weight, volume);
                // p.printPackage();
                airport.addPackage(p);
            } catch (...) {
                std::cout << "ERROR: Not a valid package\n";
            }
            
        } else {
            std::cout << "Returning to menu\n";
            scan = false;
        }
    }
}
void scanLIBs() {
    airport.scanLIB();
}
void scanULD() {
    airport.scanULD();
}
void addULD() {
    airport.addULDToPlane(1);
}
void removePackages() {
    airport.removePULD(1);
}
void sendPlane() {
    airport.sendPlane();
}



#endif
