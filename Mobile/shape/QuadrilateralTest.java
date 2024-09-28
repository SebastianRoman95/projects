public class QuadrilateralTest {
    public static void main(String[] args){
        Quadrilateral quadril1 = new Quadrilateral(1.1, 1.2, 6.6, 2.8, 6.2, 9.9, 2.2, 7.4);
        Trap quadril5 = new Trap(0, 0, 10, 0, 8, 5, 3.3, 5);
        Para quadril2 = new Para(5, 5, 11, 5, 12, 20, 6, 20);
        Rec quadril3 = new Rec(17, 14, 30, 14, 30, 28, 17, 28);
        Square quadril4 = new Square(4, 0, 8, 0, 8, 4, 4, 4);

//quad
        System.out.println("Coordinates of Quadrilateral are:");
        System.out.println(quadril1);

        //Trap
        System.out.println("Coordinates of Trap are:");
        System.out.println(quadril5);
        System.out.printf("%n%s %.2f%n", "Height is: ", quadril5.getHeightT());
        System.out.printf("%n%s %.2f%n", "Area is: ", quadril5.areaT());

        //para
        System.out.println("Coordinates of Parallelogram are:");
        System.out.println(quadril2);
        System.out.printf("%n%s %s%n", "Height is: ", quadril2.getHeightP());
        System.out.printf("%n%s %s%n", "Width is: ", quadril2.getWidthP());
        System.out.printf("%n%s %s%n", "Area is: ", quadril2.areaP());

        //Rec
        System.out.println("Coordinates of Rectangle are:");
        System.out.println(quadril3);
        System.out.printf("%n%s %s%n", "Height is: ", quadril3.getHeightR());
        System.out.printf("%n%s %s%n", "Width is: ", quadril3.getWidthR());
        System.out.printf("%n%s %s%n", "Area is: ", quadril3.areaR());

        //Square
        System.out.println("Coordinates of Square are:");
        System.out.println(quadril4);
        System.out.printf("%n%s %s%n", "Side is: ", quadril4.getSide());
        System.out.printf("%n%s %s%n", "Area is: ", quadril4.areaS());

  }
}
