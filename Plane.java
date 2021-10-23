import java.util.ArrayList;

/**
 * Written By Evan Scales
 */
public class Plane {
    protected int containers, maxWeight;
    protected Container[] containerArray;

    // Constructors
    public Plane() {
        this.containers = 0;
        this.maxWeight = 0;
        containerArray = new Container[this.containers];
    }
    public Plane(int nC, int nMW) {
        this.setContainers(nC);
        this.setMaxWeight(nMW);
        containerArray = new Container[this.containers];
    }

    // Getters and Setters
    public void setContainers(int nC) {
        if (nC != 0)
            this.containers = nC;
        else
            this.containers = 0;
    }
    public void setMaxWeight(int nMW) {
        if (nMW != 0)
            this.maxWeight = nMW;
        else
            this.maxWeight = 0;
    }
    public int getContainers() {
        return this.containers;
    }
    public int getMaxWeight() {
        return this.maxWeight;
    }

    // Member Functions
    public void printPlaneContents() {
        for (Container val : containerArray) {
            val.printContainer();
        }
    }
    public void addPackage() {
        
    }
    
}