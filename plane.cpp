// Copyright 2021 Evan Scales
#include "./plane.h"

Plane::Plane() {
    // TODO make plane default idk tbh
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
void Plane::printPlane() {
    std::cout << "Plane " << id << " heading to " << dest << "\n";
}
std::string Plane::getDest() {
    return dest;
}
void Plane::addToPlane(Container & c) {
    openPos--;
    currentWeight += c.getWeight();
    ULDs.push_back(c);
}
int Plane::getOpenPOS() {
    return openPos;
}
int Plane::canAdd(Container & c) {
    int newWeight = c.getWeight() + currentWeight;
    if (newWeight < maxWeight)
        return -1;
    else
        return newWeight - maxWeight;
    
        
}