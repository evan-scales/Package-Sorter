/**
 * Written By Evan Scales
 */
public class Boeing757 extends Plane {
    private String dest;
    private int id, currentWeight;


    // Constructors
    public Boeing757() {
        super();
        this.containers = 17;
        this.maxWeight = 72210;
        this.dest = "";
        this.id = 0;
        this.currentWeight = 0;
    }
    public Boeing757(String nD, int nID) {
        super();
        this.containers = 17;
        this.maxWeight = 26600;
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
        return "Boeing757-200 " + this.id+ " flying to " + this.dest;
    }
}