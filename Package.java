public class Package {
    private int id, zipcode, weight;
    private Boolean hazmat;

    // Constructors
    public Package() {
        this.id = 0;
        this.zipcode = 0;
        this.weight = 0;
        this.hazmat = false;
    }
    public Package(int nID, int nZ, int nW, int nH) {
        this.setId(nID);
        this.setZip(nZ);
        this.setWeight(nW);
        this.setHazmat(nH);
    }

    // Setters and Getters
    public void setId(int nID) {
        if (nID != 0)
            this.id = nID;
        else
            this.id = 0;
    }
    public void setZip(int nZ) {
        if (nZ != 0)
            this.zipcode = nZ;
        else
            this.zipcode = 0;
    }
    public void setWeight(int nW) {
        if (nW != 0)
            this.weight = nW;
        else
            this.weight = 0;
    }
    public void setHazmat(int nID) {
        if (nID == 0)
            this.hazmat = false;
        else
            this.hazmat = true;
    }
    public int getID() {
        return this.id;
    }
    public int getZip() {
        return this.zipcode;
    }
    public int getWeight() {
        return this.weight;
    }
    public Boolean getHazmat() {
        return this.hazmat;
    }


    // Member functions
    public String toString() {
        return "Tracking number: " +this.id+" Zipcode: "+this.zipcode+" Weight: "+this.weight+" Hazmat: "+this.hazmat;
    }
}
