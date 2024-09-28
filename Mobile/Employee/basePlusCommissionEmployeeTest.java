public class basePlusCommissionEmployeeTest {
    public static void main(String[] args){
        CommissionEmployee employee1 = new CommissionEmployee("Sue", "Jones", "222-22-2222", 10000, 0.06);
        BasePlusCommissionEmployee employee2 = new BasePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);

        //commission
        System.out.println("Employee information obtained by get methods:");
        System.out.printf("%n%s %s%n", "First name is", employee.getFirstName());//first
        System.out.printf("%n%s %s%n", "Last name is", employee.getLastName());//last
        System.out.printf("%n%s %s%n", "Social security number is", employee.getSocialSecurityNum());//social
        System.out.printf("%n%s %s%n", "gross salary is", employee.getGrossSale());//gross
        System.out.printf("%n%s %s%n", "commission rate is", employee.getCommissionRate());//rate

        employee.setGrossSale(5000);
        employee.setCommissionRate(0.1);

        System.out.printf("%n%s:%n%n%s%n", "Update employee information obtained by to string", employee2);

        //base
        System.out.println("Employee information obtained by get methods:");
        System.out.printf("%n%s %s%n", "First name is", employee2.getFirstName());//first
        System.out.printf("%n%s %s%n", "Last name is", employee2.getLastName());//last
        System.out.printf("%n%s %s%n", "Social security number is", employee2.getSocialSecurityNum());//social
        System.out.printf("%n%s %s%n", "gross salary is", employee2.getGrossSale());//gross
        System.out.printf("%n%s %s%n", "commission rate is", employee2.getCommissionRate());//rate
        System.out.printf("%n%s %s%n", "base salary is", employee2.getBaseSalary());//base salary 

        employee2.setBaseSalary(1000);

        System.out.printf("%n%s:%n%n%s%n", "Update employee information obtained by to string", employee2.toString());
    }
}
