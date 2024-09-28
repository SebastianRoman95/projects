public class BasePlusCommissionEmployee extends CommissionEmployee{
    private double baseSalary;

    //6 argument constructor
    public BasePlusCommissionEmployee(String firstName, String lastName, String socialSecurityNum, double grossSale, double commissionRate, double baseSalary){
        super(firstName, lastName, socialSecurityNum, grossSale, commissionRate);

        //invalid base salary
        if (baseSalary<0.0){
            throw new IllegalArgumentException("base sale must be >=0.0");
        }
    }
    
    //set and get base salary
    public void setBaseSalary(double baseSalary){
        if (baseSalary<0.0){
            throw new IllegalArgumentException("base sale must be >=0.0");
        }
        this.baseSalary=baseSalary;
    }
    public double getBaseSalary(){
        return baseSalary;
    }

    @Override
    public double earnings(){
        return baseSalary + super.earnings();
    }
    @Override
    public String toString(){
        return String.format("%s: %s %s%n%s: %.2f%n%s: %.2f", "base-salaried",  super.toString(), "base salary", getBaseSalary());
    }

}