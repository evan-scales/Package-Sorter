#ifndef PLANE_H_
#define PLANE_H_
// Copyright 2021 Evan Scales
#include <string>
#include "./container.h"
#include <vector>

class Plane {
 public:
   // Constructor
   Plane();
   explicit Plane(int, int, int, std::string);

   // Member functions
   void printPlane() const;
   std::string getDest() const;
   int getOpenPOS() const;
   void addToPlane(const Container &);
   int canAdd(const Container &) const;
   int getID() const;


 private:
   int id, maxWeight, currentWeight, numContainers, openPos;
   std::string dest;
   std::vector<Container> ULDs;
};



#endif
