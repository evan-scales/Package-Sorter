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
void Container::printContainerRecent() {
    // Only print the 10 most recently added packages due to last in first out
    for (int i = containerPackages.size() - 1; i > containerPackages.size() - 11; i--)
        containerPackages[i].printPackage();
}
void Container::addToContainer(Package p) {
    // consMap[p.getID()] = p;
    containerPackages.push_back(p);
    currentWeight += p.getWeight();
    currentVolume += p.getVolume();
}
int Container::getID() {
    return id;
}
int Container::getWeight() {
    return currentWeight;
}
int Container::getVolume() {
    return currentVolume;
}
bool Container::canAdd(Package p) {
    int newWeight = p.getWeight() + currentWeight;
    int newVol = p.getVolume() + currentVolume;
    if (newWeight < maxWeight && newVol < maxVolume)
        return true;
    else
        return false;
}
bool Container::removePackage(Package & p) {
    auto it = std::find(containerPackages.begin(), containerPackages.end(), p);
    if (it != containerPackages.end()) {
        containerPackages.erase(it);
        return true;
    } else {
        std::cout << "Package not found, scan again\n";
        return false;
    }
}
int Container::getMaxVolume() {
    return maxVolume;
}
int Container::getMaxWeight() {
    return maxWeight;
}
