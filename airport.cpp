// Copyright 2021 Evan Scales
#include "./airport.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <vector>

Airport::Airport() {
    // TODO somehow make this work
}
Airport::Airport(int code) {
    if (code == 1) {  // CLT airport
        // Set the zipmap
        if (!setMap(zipMap, "./cltZips.csv"))
            std::cout << "Zipmap loading failed\n";
        // Make the planes
        // Philly and Louis plane
        Plane philly(1, 87000, 17, "PHL");
        Plane louis(2, 180000, 39, "SDK");
        cap = 4;
        nono = cap;
        planes[philly.getDest()] = philly;
        planes[louis.getDest()] = louis;

        // printPlanes(planes);
        initRot();
        // for(auto const pair : zipMap) {
        //     std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        // }
    }
}
void Airport::setCLT() {
    // // CLT airport
    // // Set the zipmap
    // if (!setMap(zipMap, "./cltZips.csv"))
    //     std::cout << "Zipmap loading failed\n";
    // // Make the planes
    // // Philly and Louis plane
    // Plane philly(1, 87000, 17, "PHL");
    // Plane louis(2, 180000, 39, "SDK");

    // // planes.push_back(philly);
    // // planes.push_back(louis);
    // // printPlanes(planes);
    // // for(auto const pair : zipMap) {
    // //     std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    // // }
    
}
bool Airport::setMap(std::unordered_map<std::string,std::string> & map, const std::string file) {
    std::ifstream in(file);
    std::string line, token = "";
    if(in.is_open()) {
        while (getline(in, line)) {
            std::stringstream s_line(line);
            std::vector<std::string> vect;
            while (getline(s_line, token, ',')) {
                vect.push_back(token);
            }
            std::string key = vect[0];
            std::string aCode = vect[1];
            map[key] = aCode;
        }
        return true;
    } else {
        std::cout << "No file tell evan work harder\n";
        return false;
    }
}

void Airport::printPlanes(std::vector<Plane> vect) {
    for (auto p : vect) {
        p.printPlane();
    }
}
void Airport::addPackage(Package & p) {
    std::string dest = determinePlane(p);
    // std::cout << "Dest: " << dest << "\n";

    std::queue<Container> *poop = &rot.at(dest);
    if (poop->empty()) {
        std::cout << "No ULDs in rotation\n";
        return;
    }
    Container *front = &poop->front();
    Plane *plane = &planes.at(dest);

    if(front->canAdd(p)) {
        front->addToContainer(p);
        poop->push((*front));
        poop->pop();
        std::cout << "\nAdd package " << p.getID() << " to container " << front->getID() << " heading to " << dest << "\n";
        std::cout << "---------------CONTAINER STATS---------------\n";
        std::cout << "Container number: " << front->getID() << "\n";
        std::cout << "Weight of container: " << front->getWeight() << "\tMax: " << front->getMaxWeight() << "\n";
        std::cout << "Volume of container: " << front->getVolume() << "\tMax: " << front->getMaxVolume() << "\n";
        std::cout << "---------------------------------------------\n\n";
    } else {
        std::cout << "\nCan't add package " << p.getID() << " to container " << front->getID() << " due to weight or volume\n";
        std::cout << "Add container " << front->getID() << " to plane (yes) or (no)\n";
        std::cout << "---------------CONTAINER STATS---------------\n";
        std::cout << "Container number: " << front->getID() << "\n";
        std::cout << "Weight of container: " << front->getWeight() << "\tMax: " << front->getMaxWeight() << "\n";
        std::cout << "Volume of container: " << front->getVolume() << "\tMax: " << front->getMaxVolume() << "\n";
        std::cout << "---------------------------------------------\n\n";
        std::string input;
        std::cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        if (input == "YES") {
            // Plane *addTo = &planes.at(dest);
            int over = plane->canAdd((*front));
            if (over == -1) {
                plane->addToPlane((*front));
                poop->pop();
                if (plane->getOpenPOS() != 0) {
                    std::cout << "Scan new ULD CURRENTWEIGHT,MAXWEIGHT,ID,MAXVOLUME\n";
                    std::string input;
                    std::cin >> input;
                    std::string token = "";
                    std::stringstream s_line(input);
                    std::vector<std::string> vect;
                    bool stop = false;
                    int cw, mw, id, mv;
                    while (!stop) {
                        while (getline(s_line, token, ','))
                            vect.push_back(token);
                        cw = std::stoi(vect[0]);
                        mw = std::stoi(vect[1]);
                        id = std::stoi(vect[2]);
                        mv = std::stoi(vect[3]);
                        if (conIDSet.find(id) == conIDSet.end()) {
                            stop = true;
                            conIDSet.insert(id);
                        }
                        else {
                            std::cout << "ULD already in use, get a new ULD\n";
                        }
                    }
                    Container newCon(cw, mw, id, mv);
                    poop->push(newCon);
                }
                std::cout <<"succ";
            } else {
                std::cout << "\nCan't add ULD " << front->getID() << " to plane heading to " << plane->getDest() << " due to weight\n";
                std::cout << "Overweight by " << over << " lbs\n";
                std::cout << "Remove packages until no longer overweight\n";
                std::cout << "Removed packages will be moved to LIB\n\n";

                while (over > 0) {
                    front->printContainerRecent();
                    std::cout << "\nScan package to remove it ID,ZIPCODE,WEIGHT,VOLUME\n";

                    std::string input;
                    std::cin >> input;
                    std::string token = "";
                    std::stringstream s_line(input);
                    std::vector<std::string> vect;
                    while (getline(s_line, token, ','))
                        vect.push_back(token);


                    std::string id = vect[0];
                    std::string zip = vect[1];
                    int weight = std::stoi(vect[2]);
                    int volume = std::stoi(vect[3]);

                    Package nP(id, zip, weight, volume);

                    if (front->removePackage(p))
                        over -= p.getWeight();
                }
            }
        } else {
            poop->push((*front));
            poop->pop();
        }
        // ADD CONTAINER TO PLANE
        // ADD NEW CONTAINER TO ROT
        // Scan package again
        if (p.getTIR() == cap) {
            std::cout << "Cant add package to any ULD, moving to LIB\n";
            lib.push_back(p);
        } else {
            p.upTIR();
            addPackage(p);
        }
    }


    // std::cout << "Container number: " << front.getID() << "\n";
    // std::cout << "Weight of container: " << front.getWeight() << "\n";
}
std::string Airport::determinePlane(Package & p) {
    std::string dest;
    std::string zip = p.getZip();
    // Only need first digit to determine which plane
    char findZipC = zip[0];
    std::string findZip(1,findZipC);
    
    auto search = zipMap.find(findZip);
    if (search != zipMap.end())
        dest = search->second;
    else
        std::cout << "ERROR can't find which plane to add to\n";
    return dest;
}
void Airport::initRot() {
    srand(time(NULL));
    for (auto it : planes) {
        std::queue<Container> q;
        for (int i = 0; i < cap; i++) {
            int id = rand() % 3000;
            bool stop = false;
            while (!stop) {
                if (conIDSet.find(id) == conIDSet.end()) {
                    stop = true;
                    conIDSet.insert(id);
                }
                else
                    id = rand() % 3000;
            }
            Container con(200, 5000, id, 420);
            q.push(con);
            
        }
        std::string key = it.second.getDest();
        std::cout << "Key: " << key << "\n";
        rot[key] = q;
    }

    // print all container ids
    for (auto x : conIDSet)
        std::cout << x << " ";
    std::cout << "\n";
}
void Airport::printAllContainers() {

}
