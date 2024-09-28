public class CommissionEmployee extends Object{
    private final String firstName;
    private final String lastName;
    private final String socialSecurityNum;
    private double grossSale;
    private double commissionRate;

    public CommissionEmployee(String firstName, String lastName, String socialSecurityNum, double grossSale, double commissionRate){     
        //invalid gross
        if (grossSale<0.0){
            throw new IllegalArgumentException("Gross sale must be >=0.0");
        }

        //invalid rate
        if (commissionRate<=0.0||commissionRate>=1.0){
            throw new IllegalArgumentException("Rate  must be >0.0 and < 1");
        }

        this.firstName=firstName;
        this.lastName=lastName;
        this.socialSecurityNum=socialSecurityNum;
        this.grossSale=grossSale;
        this.commissionRate=commissionRate;
    }

    //return values
    public String getFirstName(){
        return firstName;
    }
    public String getLastName(){
        return lastName;
    }
    public String getSocialSecurityNum(){
        return socialSecurityNum;
    }

    //set and get gross
    public void setGrossSale(double grossSale){
        if (grossSale<0.0){
            throw new IllegalArgumentException("Gross sale must be >=0.0");
        }
        this.grossSale=grossSale;
    }
    public double getGrossSale(){
        return grossSale;
    }

    //set rate
    public void setCommissionRate(double commissionRate){
        if (commissionRate<=0.0||commissionRate>=1.0){
            throw new IllegalArgumentException("Rate  must be >0.0 and < 1");
        }
        this.commissionRate=commissionRate;
    }
    public double getCommissionRate(){
        return commissionRate;
    }

    //calculate earnings
    public double earnings(){
        return getCommissionRate()*getGrossSale();
    }
    @Override
    public String toString(){
        return String.format("%s: %s %s%n%s: %.2f%n%s: %.2f", "commission employee", getFirstName(), getLastName(), "Social security number", getSocialSecurityNum(), "gross sale",
        getGrossSale(),"commission rate", getCommissionRate());
    }
}

