# Package-Sorter 1.0
EXTREMELY simple version of UPS CLT Air Hub

Unfortunately just a console application, so you can't actually "scan" a package :(

Built to easily incorporate more airports, would just need to tweak how to determine a packages plane

Program takes in package information and returns to user which ULD to add package to

Real life implementation could be used to automatically sort packages on a conveyer belt 

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
    - EXAMPLE: `412312,12345,5,2`
    - Tells user which ULD to add package to
2. Scan new ULD
    - ULDs are stored in rotations of ULDs corresponding to their destination
    - Rotations have a max capacity 
    - Prints all destinations the air hub sends planes to
    - Choose 1 of the destinations to add a ULD to that rotation
    - Can't add ULD to rotation if capacity has been reached
    - Can't add ULD to rotation if there are 0 open positions in the corresponding plane
    - Input ULD information
    - CURRENTWEIGHT,MAXWEIGHT,ID,MAXVOLUME
    - EXAMPLE: `200,5000,2337,430`
3. Scan LIB Packages
    - If a package can't be added to a ULD it is moved to LIB
    - User can look at these packages and try to add them to a ULD again
    - Input package information 
    - ID,ZIPCODE,WEIGHT,VOLUME
    - EXAMPLE: `412312,12345,5,2`
4. Send off a Plane
    - Print all planes and their stats
    - Enter a planes ID to send it to its destination
    - EXAMPLE: `1`
5. Add ULD to Plane
    - Prints all ULDs in rotation
    - Input ULD ID
    - ID
    - EXAMPLE: `626`
    - Adds ULD to plane
6. Remove Packages from ULD
    - Prints the 10 most recent packages added to ULD to simulate not being able to see the packages in the very back of the ULD
    - Input package information 
    - ID,ZIPCODE,WEIGHT,VOLUME
    - EXAMPLE: `412312,12345,5,2`
    - Removed packages are moved to LIB

# How to make this better
1. Add hazmat packages
2. When adding ULD to plane, tell what position it will be in
3. In order to do that need to create types of planes due to differemt loading processes of planes

# Questions? Comments? Concerns?
Email me!

`escales@email.sc.edu`

`evan.m.scales@gmail.com`
