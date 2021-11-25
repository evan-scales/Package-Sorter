#ifndef AIRPORT_H_
#define AIRPORT_H_
#include "./plane.h"
#include "./package.h"
// Copyright 2021 Evan Scales
#include <unordered_map>
#include <queue>
#include <set>

class Airport {
 public:
    // Constructors
    Airport();
    explicit Airport(int);
    
    // Member functions
    bool setMap(std::unordered_map<std::string,std::string> &, const std::string);
    void printPlanes(std::unordered_map<std::string, Plane>);
    void addPackage(Package &);
    std::string determinePlane(const Package &);
    void setCLT();
    void initRot();
    void printAllContainers();
    void scanLIB();
    void addULDToPlane(int choice, int sID = -1);
    void sendPlane();
    void scanULD();
    void removePULD(int choice, int sID = -1);

 private:
   std::unordered_map<std::string, Plane> planes;
   std::unordered_map<std::string, std::string> zipMap;
   std::set<int> conIDSet;
   std::unordered_map<std::string, std::queue<Container> > rot;
   int cap;
   std::vector<Package> lib;
};

#endif
