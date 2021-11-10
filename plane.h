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
    void printPlane();
    std::string getDest();
    int getOpenPOS();
    void addToPlane(Container &);
    int canAdd(Container &);


 private:
   int id, maxWeight, currentWeight, numContainers, openPos;
   std::string dest;
   std::vector<Container> ULDs;
};



#endif
