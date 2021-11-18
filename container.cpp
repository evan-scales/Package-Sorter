// Copyright 2021 Evan Scales
#include "./container.h"

Container::Container() {

}
Container::Container(int nCW, int nMW, int nID, int nMV) {
    currentWeight = nCW;
    maxWeight = nMW;
    id = nID;
    maxVolume = nMV;
    currentVolume = 0;
}
const void Container::printContainerRecent() {
    // Only print the 10 most recently added packages due to last in first out
    if (containerPackages.size() > 10) {
        for (int i = containerPackages.size() - 1; i > containerPackages.size() - 11; i--)
            containerPackages[i].printPackage();
    } else {
        for (Package p : containerPackages)
            p.printPackage();
    }
}
void Container::addToContainer(Package & p) {
    // consMap[p.getID()] = p;
    containerPackages.push_back(p);
    currentWeight += p.getWeight();
    currentVolume += p.getVolume();
}
const int Container::getID() {
    return id;
}
const int Container::getWeight() {
    return currentWeight;
}
const int Container::getVolume() {
    return currentVolume;
}
const bool Container::canAdd(Package & p) {
    int newWeight = p.getWeight() + currentWeight;
    int newVol = p.getVolume() + currentVolume;
    if (newWeight < maxWeight && newVol < maxVolume)
        return true;
    else
        return false;
}
void Container::removePackage(Package & p) {
    auto it = std::find(containerPackages.begin(), containerPackages.end(), p);
    if (it != containerPackages.end()) {
        containerPackages.erase(it);
        currentWeight = currentWeight - p.getWeight();
        currentVolume = currentVolume - p.getVolume();
    } else {
        std::cout << "Package not found, scan again\n";
    }
}
const int Container::getMaxVolume() {
    return maxVolume;
}
const int Container::getMaxWeight() {
    return maxWeight;
}
const void Container::printContainerStats() {
    std::cout << "---------------ULD STATS---------------\n";
    std::cout << "ULD number: " << id << "\n";
    std::cout << "Weight of ULD: " << currentWeight << "\tMax: " << maxWeight << "\n";
    std::cout << "Volume of ULD: " << currentVolume << "\tMax: " << maxVolume << "\n";
    std::cout << "---------------------------------------------\n\n";
}
bool Container::isEmpty() {
    if (containerPackages.empty())
        return true;
    return false;
}