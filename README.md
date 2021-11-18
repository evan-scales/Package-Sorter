# Package-Sorter 1.0
EXTREMLY simple version of UPS CLT Air Hub

Unfortunately just a console application, so you can't actually "scan" a package :(

Built to easily incorporate more airports, would just need to tweak how to determine a packages plane

# Compiling and Running
```
// Windows / Linux
g++ *.cpp && ./a.out

// Mac
g++ -std=c++2a *.cpp && ./a.out
```

# Commands
1. Scan Packages
    - Input package information 
    - ID,ZIPCODE,WEIGHT,VOLUME
    - EXAMPLE
    - `412312,12345,5,2`
    - Tells user which ULD to add package to
3. Scan new ULD
    - ULDs are stored in rotations of ULDs corresponding to their destination
    - Rotations have a max capacity 
    - Prints all destinations the air hub sends planes to
    - Choose 1 of the destinations to add a ULD to that rotation
    - Can't add ULD to rotation if capacity has been reached
    - Can't add ULD to rotation if there are 0 open positions in the corresponding plane
5. Scan LIB Packages
6. Send off a Plane
7. Add ULD to Plane
8. Remove Packages from ULD
9. Run Tests
    - NOT COMPLETE

# Questions? Comments? Concerns?
Email me!

`escales@email.sc.edu`

`evan.m.scales@gmail.com`
