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
const void Plane::printPlane() {
    std::cout << "\n---------------PLANE STATS---------------\n";
    std::cout << "Plane ID: " << id << "\n";
    std::cout << "Plane dest: " << dest << "\n";
    std::cout << "Weight: " << currentWeight << "\tMax: " << maxWeight << "\n";
    std::cout << "Open positions: " << openPos << "\n";
    std::cout << "-----------------------------------------\n\n";

}
const std::string Plane::getDest() {
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
const int Plane::canAdd(Container & c) {
    int newWeight = c.getWeight() + currentWeight;
    if (newWeight < maxWeight)
        return -1;
    else
        return newWeight - maxWeight;
    
        
}
int Plane::getID() {
    return id;
}