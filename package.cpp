// Copyright 2021 Evan Scales
#include "./package.h"

Package::Package(std::string nID, std::string nZ, int nW, double nV) {
    id = nID;
    zipcode = nZ;
    weight = nW;
    volume = nV;
    tir = 0;
}
void Package::printPackage() const {
    std::cout << "Tracking number: " << id << " Shipping to (zipcode): " << zipcode << " Weight: " << weight << " Volume (cubic feet): " << volume << "\n";
}
std::string Package::getID() const {
    return id;
}
bool Package::getHazmat() const {
    return hazmat;
}
std::string Package::getZip() const {
    return zipcode;
}
int Package::getWeight() const {
    return weight;
}
double Package::getVolume() const {
    return volume;
}
int Package::getTIR() const {
    return tir;
}
void Package::upTIR() {
    tir++;
}
bool Package::operator==(const Package & rhs) const {
    if ((id == rhs.id) && (zipcode == rhs.zipcode) && (weight == rhs.weight) && (volume == rhs.volume))
        return true;
    return false;
}
void Package::resetTIR() {
    tir = 0;
}