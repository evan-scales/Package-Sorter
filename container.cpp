// Copyright 2021 Evan Scales
#include "./container.h"

Container::Container(int nCW, int nMW, int nID, double nMV) {
    currentWeight = nCW;
    maxWeight = nMW;
    id = nID;
    maxVolume = nMV;
    currentVolume = 0;
}
void Container::printContainerRecent() const {
    // Only print the 10 most recently added packages due to last in first out
    if (containerPackages.size() > 10) {
        for (int i = containerPackages.size() - 1; i > containerPackages.size() - 11; i--)
            containerPackages[i].printPackage();
    } else {
        for (Package p : containerPackages)
            p.printPackage();
    }
}
void Container::addToContainer(const Package & p) {
    // consMap[p.getID()] = p;
    containerPackages.push_back(p);
    currentWeight += p.getWeight();
    currentVolume += p.getVolume();
}
int Container::getID() const {
    return id;
}
int Container::getWeight() const {
    return currentWeight;
}
double Container::getVolume() const {
    return currentVolume;
}
bool Container::canAdd(const Package & p)const {
    int newWeight = p.getWeight() + currentWeight;
    double newVol = p.getVolume() + currentVolume;
    if (newWeight < maxWeight && newVol < maxVolume)
        return true;
    else
        return false;
}
void Container::removePackage(const Package & p) {
    auto it = std::find(containerPackages.begin(), containerPackages.end(), p);
    if (it != containerPackages.end()) {
        containerPackages.erase(it);
        currentWeight = currentWeight - p.getWeight();
        currentVolume = currentVolume - p.getVolume();
        std::cout << "Package removed from ULD " << id << "\n\n";
        printContainerStats();
    } else {
        std::cout << "Package not found, scan again\n";
    }
}
double Container::getMaxVolume() const {
    return maxVolume;
}
int Container::getMaxWeight() const {
    return maxWeight;
}
void Container::printContainerStats() const {
    std::cout << "---------------ULD STATS---------------------\n";
    std::cout << "ULD number: " << id << "\n";
    std::cout << "Weight of ULD: " << currentWeight << "\tMax: " << maxWeight << "\n";
    std::cout << "Volume of ULD: " << currentVolume << "\tMax: " << maxVolume << "\n";
    std::cout << "---------------------------------------------\n\n";
}
bool Container::isEmpty() const {
    if (containerPackages.empty())
        return true;
    return false;
}