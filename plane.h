#ifndef PLANE_H_
#define PLANE_H_
// Copyright 2021 Evan Scales
#include <string>
#include "./container.h"
#include <vector>

class Plane {
 public:
    // Constructors
    Plane();
    explicit Plane(int, int, int, std::string);

    // Member functions
    const void printPlane();
    const std::string getDest();
    int getOpenPOS();
    void addToPlane(Container &);
    const int canAdd(Container &);
    int getID();


 private:
   int id, maxWeight, currentWeight, numContainers, openPos;
   std::string dest;
   std::vector<Container> ULDs;
};



#endif
