#ifndef CONTAINER_H_
#define CONTAINER_H_
// Copyright 2021 Evan Scales
#include "./package.h"
#include <map>
#include <vector>

class Container {
 public:
    // Constructors
    Container();
    explicit Container(int, int, int, int);

   //  bool operator<(const Container &) const;

    // Member functions
    void printContainerRecent();
    void addToContainer(Package);
    int getID();
    int getWeight();
    int getMaxWeight();
    int getMaxVolume();
    int getVolume();
    bool canAdd(Package);
    bool removePackage(Package &);

 private:
    int currentWeight, maxWeight, id, currentVolume, maxVolume;
   //  std::map<std::string, Package> consMap;
   std::vector<Package> containerPackages;
};

#endif
