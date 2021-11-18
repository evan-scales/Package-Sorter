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
4. Scan LIB Packages
5. Send off a Plane
6. Add ULD to Plane
7. Remove Packages from ULD
8. Run Tests
    - NOT COMPLETE
