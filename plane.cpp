// Copyright 2021 Evan Scales
#include "./plane.h"

Plane::Plane() {
    // Make it so user can make their own plane
}
Plane::Plane(int nID, int nMW, int nNC, std::string nD) {
    id = nID;
    maxWeight = nMW;
    numContainers = nNC;
    currentWeight = 0;
    dest = nD;
    ULDs.reserve(numContainers);
    openPos = nNC;
}
void Plane::printPlane() const {
    std::cout << "\n---------------PLANE STATS---------------\n";
    std::cout << "Plane ID: " << id << "\n";
    std::cout << "Plane dest: " << dest << "\n";
    std::cout << "Weight: " << currentWeight << "\tMax: " << maxWeight << "\n";
    std::cout << "Open positions: " << openPos << "\n";
    std::cout << "-----------------------------------------\n\n";

}
std::string Plane::getDest() const {
    return dest;
}
void Plane::addToPlane(const Container & c) {
    openPos--;
    currentWeight += c.getWeight();
    ULDs.push_back(c);
}
int Plane::getOpenPOS() const {
    return openPos;
}
int Plane::canAdd(const Container & c) const {
    int newWeight = c.getWeight() + currentWeight;
    if (newWeight < maxWeight)
        return -1;
    else
        return newWeight - maxWeight;
    
        
}
int Plane::getID() const {
    return id;
}