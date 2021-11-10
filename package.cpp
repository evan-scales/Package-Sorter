// Copyright 2021 Evan Scales
#include "./package.h"

Package::Package() {
    id = weight = 0;
    zipcode = "0";
    hazmat = false;
}
Package::Package(std::string nID, std::string nZ, int nW, int nV) {
    id = nID;
    zipcode = nZ;
    weight = nW;
    volume = nV;
    tir = 0;
}
void Package::printPackage() {
    std::cout << "Tracking number: " << id << " Shipping to (zipcode): " << zipcode << " Weight: " << weight << " Volume (cubic feet): " << volume << "\n";
}
std::string Package::getID() {
    return id;
}
bool Package::getHazmat() {
    return hazmat;
}
std::string Package::getZip() {
    return zipcode;
}
int Package::getWeight() {
    return weight;
}
int Package::getVolume() {
    return volume;
}
int Package::getTIR() {
    return tir;
}
void Package::upTIR() {
    tir++;
}

bool Package::operator==(const Package & rhs) const {
    if ((id == rhs.id) && (zipcode == rhs.zipcode) && (weight == rhs.weight) && (volume == rhs.volume))
        return true;
    else
        return false;
}
