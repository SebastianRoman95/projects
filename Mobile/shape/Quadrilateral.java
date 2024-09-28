public class Quadrilateral extends Object{
    //var
    private double numX;
    private double numY;
    private double numX2;
    private double numY2;
    private double numX3;
    private double numY3;
    private double numX4;
    private double numY4;

    //set
    public Quadrilateral(double numX, double numY, double numX2, double numY2, double numX3, double numY3, double numX4, double numY4){
        this.numX=numX;
        this.numY=numY;
        this.numX2=numX2;
        this.numY2=numY2;
        this.numX3=numX3;
        this.numY3=numY3;
        this.numX4=numX4;
        this.numY4=numY4;
    }

    //pair 1
    public double getNumX(){
        return numX;
    }
    public double getNumY(){
        return numY;
    }
    //pair 2
    public double getNumX2(){
        return numX2;
    }
    public double getNumY2(){
        return numY2;
    }
    //pair 3
    public double getNumX3(){
        return numX3;
    }
    public double getNumY3(){
        return numY3;
    }
    //pair 4
    public double getNumX4(){
        return numX4;
    }
    public double getNumY4(){
        return numY4;
    }

        @Override
        public String toString(){
            return String.format("%.2f %.2f%n %.2f %.2f%n %.2f %.2f%n %.2f %.2f%n", getNumX(), getNumY(), getNumX2(), getNumY2(),
           getNumX3(), getNumY3(), getNumX4(), getNumY4());
        }
}
