#ifndef PACKAGE_H_
#define PACKAGE_H_
// Copyright 2021 Evan Scales
#include <iostream>

class Package {
 public:
    // Constructors
    Package();
    explicit Package(std::string, std::string, int, int);
    
    // // Destructor
    // ~Package();

    // // Member Functions
    std::string getID();
    std::string getZip();
    int getWeight();
    int getVolume();
    bool getHazmat();
    void printPackage();
    int getTIR();
    void upTIR();

    bool operator==(const Package &) const;

 private:
    int weight, volume, tir;
    std::string zipcode, id;
    bool hazmat;

};

#endif
