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
    const void printContainerRecent();
    const void printContainerStats();
    void addToContainer(Package &);
    const int getID();
    const int getWeight();
    const int getMaxWeight();
    const int getMaxVolume();
    const int getVolume();
    const bool canAdd(Package &);
    void removePackage(Package &);
    bool isEmpty();

 private:
    int currentWeight, maxWeight, id, currentVolume, maxVolume;
   //  std::map<std::string, Package> consMap;
   std::vector<Package> containerPackages;
};

#endif
