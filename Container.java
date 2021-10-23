import java.util.Stack;

/**
 * Written By Evan Scales
 */
// import java.util.*;
public class Container {
    private int maxWeight, currentWeight = 0, id;
    private Stack<Package> containerStack = new Stack<Package>();

    // Constructors
    public Container() {
        this.maxWeight = 3500;
        this.id = 0;
    }
    public Container(int nMW, int nID) {
        this.setMaxWeight(nMW);
        this.setId(nID);
    }
    
    // Setters and getters
    public void setMaxWeight(int nMW) {
        if (nMW != 0)
            this.maxWeight = nMW;
        else
            this.maxWeight = 0;
    }
    public void setId(int nID) {
        if (nID != 0) 
            this.id = nID;
        else
            this.id = 0;
    }
    public int getMaxWeight() {
        return this.maxWeight;
    }
    public int getCurrentWeight() {
        return this.currentWeight;
    }
    public int getId() {
        return this.id;
    }

    // Member functions
    public void printContainer() {
        for (Package val : containerStack) {
            System.out.println(val.toString());
        }
    }
    
}