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
    if (planes.find(dest) == planes.end()) {
        std::cout << "No plane to add package to. Adding package to LIB\n";
        lib.push_back(p);
        return;
    }
    std::queue<Container> * rotP = &rot.at(dest);
    Plane * plane = &planes.at(dest);
    Container * front = &rotP->front();
    

    if (rotP->empty()) {
        std::cout << "No ULDs in rotation\n";
        return;
    }

    if (front->canAdd(p)) {
        std::cout << "\nAdd package " << p.getID() << " to container " << front->getID() << " heading to " << dest << "\n";
        front->addToContainer(p);
        front->printContainerStats();
        rotP->push((*front));
        rotP->pop();
    } else {
        std::cout << "\nCan't add package " << p.getID() << " to container " << front->getID() << " due to weight or volume\n";
        std::cout << "Add container " << front->getID() << " to plane heading to " << dest << " (yes) or (no)\n";
        front->printContainerStats();
        std::string input;
        try {
            std::cin >> input;
            transform(input.begin(), input.end(), input.begin(), ::toupper);
        } catch (...) {
            std::cout << "Not a valid input, returning to menu\n";
            return;
        }
        // Asking if user would like to add ULD to plane 
        if (input == "YES") {
            // Add to plane
            addULDToPlane(0,front->getID());
        } else if (input == "NO") {
            // Dont add to plane
            rotP->push((*front));
            rotP->pop();
        } else {
            // Not a valid input
            std::cout << "Not a valid input\n";
        }
        // If package has been tried to place in multiple containers move to LIB
        if (p.getTIR() == cap) {
            std::cout << "Cant add package to any ULD, moving to LIB\n";
            p.resetTIR();
            lib.push_back(p);
        } else {
            p.upTIR();
            addPackage(p);
        }
    }
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
    std::string id, zip;
    id = "1231231";
    zip = "12345";
    Package test(id,zip,1,1);
    lib.push_back(test);
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
    for (auto it : rot) {
        std::queue<Container> * rot2 = &it.second;
        while (!rot2->empty()) {
            rot2->front().printContainerStats();
            rot2->pop();
        }
    }
}
void Airport::scanLIB() {
    bool scan = true;
    std::cout << "Enter O(or o) to stop and return to options\n";
    while (scan) {
        if (!lib.empty()) {
            for (auto p : lib)
                p.printPackage();
            std::cout << "Scan package ID,ZIPCODE,WEIGHT,VOLUME\n";
            std::string input;
            std::cin >> input;
            if (input != "O" && input != "o") {
                std::string token = "";
                std::stringstream s_line(input);
                std::vector<std::string> vect;

                try {
                    while (getline(s_line, token, ','))
                        vect.push_back(token);
                    std::string id = vect[0];
                    std::string zip = vect[1];
                    int weight = std::stoi(vect[2]);
                    int volume = std::stoi(vect[3]);

                    Package p(id, zip, weight, volume);
                    auto it = std::find(lib.begin(), lib.end(), p);
                    if (it != lib.end()) {
                        lib.erase(it);
                        addPackage(p);
                    }
                    else {
                        std::cout << "Package not found scan again\n";
                    }
                } catch (...) {
                    std::cout << "ERROR: Not a valid package\n";
                }
                
            } else {
                std::cout << "Returning to menu\n";
                scan = false;
            }
        } else {
            scan = false;
            std::cout << "LIB is empty\nReturning to menu\n";
        }
    }
    
}
void Airport::scanULD() { // DONE
    std::string dest;
    std::cout << "Choose one of the dests\n";
    int i = 1;
    for (auto it : planes) {
        std::cout << "Enter " << i++ << " for " << it.second.getDest() << "\n"; 
    }
    std::cout << "Enter 0 to return to menu\n";
    int choice;
    std::string input;
    try {
        std::cin >> input;
        choice = std::stoi(input);
    } catch (...) {
        std::cout << "Not a valid option\nReturning to menu\n";
        return;
    }
    if (choice == 0)
        return;
    int k = 1;
    for (auto it : planes) {
        if (k++ == choice) {
            dest = it.second.getDest();
        } 
    }
    if (dest.empty()) {
        std::cout << "No dest chosen\nReturning to menu\n";
        return;
    }

    // There are open pos
    // Cap has not been reached
    std::queue<Container> *rotP = &rot.at(dest);
    Plane *plane = &planes.at(dest);
    // std::cout << "rot size: " << rotP->size() << "\n";
    if (plane->getOpenPOS() != 0 && rotP->size() != cap) {
        bool stop = false;
        int cw, mw, id, mv;
        while (!stop) {
            std::cout << "Scan new ULD CURRENTWEIGHT,MAXWEIGHT,ID,MAXVOLUME\n";
            std::cout << "Enter O(or o) to stop and return to options\n";
            std::string input;
            std::cin >> input;
            if (input == "O" || input == "o") {
                std::cout << "Returning to menu\n";
                return;
            }
            std::string token = "";
            std::stringstream s_line(input);
            std::vector<std::string> vect;
            while (getline(s_line, token, ','))
                vect.push_back(token);
            cw = std::stoi(vect[0]);
            mw = std::stoi(vect[1]);
            id = std::stoi(vect[2]);
            mv = std::stoi(vect[3]);
            if (conIDSet.find(id) == conIDSet.end()) {
                stop = true;
                conIDSet.insert(id);
                std::cout << "ULD succuesfully scanned\n";
            }
            else {
                std::cout << "ULD already in use, get a new ULD\n";
            }
        }
        Container newCon(cw, mw, id, mv);
        rotP->push(newCon);
    } else if (plane->getOpenPOS() == 0) {
        std::cout << "0 open pos\n";
    } else {
        std::cout << "cap reached\n";
    }

}
void Airport::addULDToPlane(int choice, int sID) {
    int id;
    if (choice == 1) {
        try { 
            printAllContainers();
            std::cout << "Scan the ULD to add it to the plane\nEnter ULD ID to scan it\n";
            std::cout << "Enter O(or o) to stop and return to options\n";
            std::string input;
            std::cin >> input;
            if (input == "O" || input == "o") {
                std::cout << "Returning to menu\n";
                return;
            }
            id = std::stoi(input);
            if (conIDSet.find(id) == conIDSet.end()) {
                std::cout << "ULD not found. Returning to menu\n";
            }
        } catch (...) {
            std::cout << "Not a valid ID. Returning to menu\n";
            return;
        }
    }
    if (sID != -1)
        id = sID;
    

    for (auto it : rot) {
        std::string dest = it.first;
        std::queue<Container> *rotP = &rot.at(dest);
        Plane * plane = &planes.at(dest);
        for (int i = 0; i < rotP->size(); i++) {
            Container *search = &rotP->front();
            if (search->getID() == id) {
                int over = plane->canAdd((*search));
                if (over == -1) {
                    rotP->pop();
                    // std::cout << "rot size: " << rotP->size() << "\n";
                    plane->addToPlane((*search));
                    std::cout << "Adding ULD to plane heading to " << dest << "\n";
                    // std::cout << "rot size: " << rotP->size() << "\n";
                    plane->printPlane();
                    if (plane->getOpenPOS() != 0) {
                        std::cout << "Scan in a new ULD\n";
                        scanULD();
                    }
                } else {
                    std::cout << "\nCan't add ULD " << search->getID() << " to plane heading to " << dest << " due to weight\n";
                    std::cout << "Overweight by " << over << " lbs\n";
                    std::cout << "Remove packages until no longer overweight\n";
                    removePULD(0, search->getID());
                }
            } else {
                rotP->pop();
                rotP->push((*search));
            }
        }
    }
}
void Airport::removePULD(int choice, int sID) {
    int id;
    if (choice == 1) {
        try { 
            printAllContainers();
            std::cout << "Scan the ULD to remove packages\nEnter ULD ID to scan it\n";
            std::cout << "Enter O(or o) to stop and return to options\n";
            std::string input;
            std::cin >> input;
            if (input == "O" || input == "o") {
                std::cout << "Returning to menu\n";
                return;
            }
            id = std::stoi(input);
            if (conIDSet.find(id) == conIDSet.end()) {
                std::cout << "ULD not found. Returning to menu\n";
            }
        } catch (...) {
            std::cout << "Not a valid ID. Returning to menu\n";
        }
    }
    // std::cout << "TEST";
    if (sID != -1)
        id = sID;
    for (auto it : rot) {
        std::string dest = it.first;
        std::queue<Container> * rotP = &rot.at(dest);
        int size = rotP->size();
        for (int i = 0; i < size; i++) {
            Container * uld = &rotP->front();
            // std::cout << "ID: " << id << "\n";
            // std::cout << uld->getID() << "\n";
            if (uld->getID() == id) {
                bool scan = true;
                while (scan) {
                    if (uld->isEmpty()) {
                        std::cout << "ULD is empty\nReturning to menu\n";
                        return;
                    }
                    uld->printContainerRecent();
                    std::cout << "\nRemoved packages will be moved to LIB\n";
                    std::cout << "Scan package to remove it ID,ZIPCODE,WEIGHT,VOLUME\n";
                    std::cout << "Enter O(or o) to stop and return to options\n";
                    try {
                        std::string input;
                        std::cin >> input;
                        if (input == "O" || input == "o") {
                            scan = false;
                            break;
                        }
                        std::string token = "";
                        std::stringstream s_line(input);
                        std::vector<std::string> vect;
                        while (getline(s_line, token, ','))
                            vect.push_back(token);

                        std::string pID = vect[0];
                        std::string zip = vect[1];
                        int weight = std::stoi(vect[2]);
                        int volume = std::stoi(vect[3]);

                        Package nP(pID, zip, weight, volume);
                        uld->removePackage(nP);
                        lib.push_back(nP);
                    } catch (...) {
                        std::cout << "ERROR: Not a valid package\n";
                    }
                }
            } else {
                rotP->pop();
                rotP->push((*uld));
            }
        }
    }
}
void Airport::sendPlane() {
    // Print all plane stats
    for (auto p : planes)
        p.second.printPlane();
    if (planes.empty()) {
        std::cout << "No planes on ramp\nReturning to menu\n";
        return;
    }
    int pID;
    std::cout << "Enter the planes ID to send it to its dest\n";
    std::cout << "Enter O(or o) to stop and return to options\n";
    std::string input;
    try {
        std::cin >> input;
        if (input == "O" || input == "o")
            return;
        pID = std::stoi(input);
    } catch (...) {
        std::cout << "ERROR: Returning to menu\n";
        return;
    }
    std::string dest;
    for (auto p : planes) {
        if (p.second.getID() == pID) {
            dest = p.second.getDest();
            std::cout << "Sending plane " << pID << " to " << dest << "\n";
            // Delete plane from rot and planes and zipmap
            planes.erase(dest);
            rot.erase(dest);
            zipMap.erase(dest);
            return;
        }
    }
    std::cout << "No plane found. Returning to menu\n";
}