#ifndef CONTAINER_H_
#define CONTAINER_H_
// Copyright 2021 Evan Scales
#include "./package.h"
#include <map>
#include <vector>

class Container {
 public:
   // Constructor
   Container(int, int, int, double);

   // Member functions
   void printContainerRecent() const;
   void printContainerStats() const;
   void addToContainer(const Package &);
   int getID() const;
   int getWeight() const;
   int getMaxWeight() const;
   double getMaxVolume() const;
   double getVolume() const;
   bool canAdd(const Package &) const;
   void removePackage(const Package &);
   bool isEmpty() const;

 private:
   int currentWeight, maxWeight, id;
   double currentVolume, maxVolume;
   std::vector<Package> containerPackages;
};

#endif
