import java.util.ArrayList;
import java.util.Scanner;

/**
 * Written By Evan Scales
 */
public class PackageSorterManager {
    private static Scanner keyboard = new Scanner(System.in);
    private Boeing757 phillyPlane;
    private MD11 louisPlane;


    // Constructor
    public PackageSorterManager() {
        phillyPlane = new Boeing757("PHL", 23723);
        louisPlane = new MD11("SDF", 48404);
    }
    
    // Boeing757 phillyPlane = new Boeing757("PHL", 23723);
    // MD11 louisPlane = new MD11("SDF", 48404);


    // Member functions
    public void add(Package nP) {
        int zipcode = nP.getZip();
        int[] phillyZips = {19, 29, 30, 45, 32, 21, 7, 39, 20, 38, 8, 46, 48, 40, 10};
        

    }

    
}