public class AutoPolicy{
    private int accountNumber;
    private String makeAndModel;
    private String state;

    public AutoPolicy(int accountNumber, String makeAndModel, String state){
        this.accountNumver = accountNumber;
        this.makeAndModel= makeAndModel;
        this.state =state;
    }

    //accountNumber
    public void setAccountNumber(int accountNumber){
        this.accountNumber = accountNumber;
    }

    public int getAccountNumber(){
        return accountNumber;
    }

    //makeModel
    public void setMakeAndModel(String makeAndModel){
        this.makeAndModel =makeAndModel;  
    }

    public String getMakeAndModel(){
        return makeAndModel;
    }

    //state
    public void setState(String state){
        this.state =state;
    }

    public String getState(){
        return state;
    }

    //fault
    public boolean isNoFaultState(){
        boolean noFaultState;
    
    switch(getState()){
        case "MA": case "NJ": case "PA":
        noFaultState = true;
        break;
        default:
        noFaultState = false;
        break;
    }

    return noFaultState;
    }
}

public class AutoPolictyTest{
    public static void main(String[] args){
        AutoPolicy policy1 = new AutoPolicy(1111111, "Toyota Camry", "NJ");
        AutoPolicy policy2 = new AutoPolicy(22222222, "Ford Fusion", "ME");

        policyInNoFaultState(policy1);
        policyInNoFaultState(policy2);
    }

    public static void policyInNoFaultState(AutoPolicy policy){
        System.out.println("The auto policy:");
        System.out.printf("Account #: %d; Car: %s;%nState %s %s a no-fault state%n%n", policy.getAccountNumber(), policy.getMakeAndModel(),policy.getState(),(policy.isNoFaultState()?"is": "is not"));
    }
}

/*
public class BreakTest{
    public static void main(String[] args){
        int count;

        for(count=1;count <=10; count++){
            if(count==5){
                break;
            }

            System.out.printf("%d", count);
        }
        System.out.printf("%nBroke out of loop at count =%d%n", count);
    }
}
*/

