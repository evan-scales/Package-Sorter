#ifndef PACKAGE_H_
#define PACKAGE_H_
// Copyright 2021 Evan Scales
#include <iostream>

class Package {
 public:
   // Constructor
   Package(std::string, std::string, int, int);

   // Member Functions
   std::string getID() const;
   std::string getZip() const;
   int getWeight() const;
   int getVolume() const;
   bool getHazmat() const;
   void printPackage() const;
   int getTIR() const;
   void upTIR();
   void resetTIR();

   bool operator==(const Package &) const;

 private:
    int weight, volume, tir;
    std::string zipcode, id;
    bool hazmat;

};

#endif
