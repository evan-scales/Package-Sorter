/**
 * Written By Evan Scales
 */
public class MD11 extends Plane {
    private String dest;
    private int id, currentWeight;

    // Constructors
    public MD11() {
        super();
        this.containers = 17;
        this.maxWeight = 200000;
        this.dest = "";
        this.id = 0;
        this.currentWeight = 0;
    }
    public MD11(String nD, int nID) {
        super();
        this.containers = 32;
        this.maxWeight = 200000;
        this.setDest(nD);
        this.setId(nID);
        this.currentWeight = 0;
    }

    // Getters and setters
    public void setDest(String nD) {
        if (nD != null)
            this.dest = nD;
        else
            this.dest = "EMPTY";
    }
    public void setId(int nID) {
        if (nID != 0)
            this.id = nID;
        else
            this.id = 0;
    }
    public String getDest() {
        return this.dest;
    }
    public int getID() {
        return this.id;
    }
    public int getCurrentWeight() {
        return this.currentWeight;
    }

    // Member functions
    @Override
    public String toString() {
        return "BoeingMD-11F " + this.id+ " flying to " + this.dest;
    }
}
    
