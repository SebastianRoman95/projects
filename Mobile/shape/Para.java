public class Para extends Quadrilateral{

    //var
    public Para(double numX, double numY, double numX2, double numY2, double numX3, double numY3, double numX4, double numY4){
        super(numX, numY, numX2, numY2, numX3, numY3, numX4, numY4);

    }

    //width
    public double getWidthP(){
        double left=0;
        left = Math.abs(getNumX()-getNumX2());
        return left;
    }

     //height 
     public double getHeightP(){
        double high=0;
        double low=0;

        //high
        if(super.getNumX()>=super.getNumX2()&&super.getNumX()>=super.getNumX3()&&super.getNumX()>=super.getNumX4()){
            high=super.getNumX();//point 1
        }
        else if(super.getNumX2()>=super.getNumX()&&super.getNumX2()>=super.getNumX3()&&super.getNumX2()>=super.getNumX4()){
            high=super.getNumX2();//point 2
        }
        else if(super.getNumX3()>=super.getNumX2()&&super.getNumX3()>=super.getNumX()&&super.getNumX3()>=super.getNumX4()){
            high=super.getNumX3();//point 3
        }
        else if(super.getNumX4()>=super.getNumX2()&&super.getNumX4()>=super.getNumX3()&&super.getNumX()>=super.getNumX4()){
            high=super.getNumX4();//point 4
        }
        //low
        if(super.getNumX()<=super.getNumX2()&&super.getNumX()<=super.getNumX3()&&super.getNumX()<=super.getNumX4()){
            low=super.getNumX();//point 1
        }
        else if(super.getNumX2()<=super.getNumX()&&super.getNumX2()<=super.getNumX3()&&super.getNumX2()<=super.getNumX4()){
            low=super.getNumX2();//point 2
        }
        else if(super.getNumX3()<=super.getNumX2()&&super.getNumX3()<=super.getNumX()&&super.getNumX3()<=super.getNumX4()){
            low=super.getNumX3();//point 3
        }
        else if(super.getNumX4()<=super.getNumX2()&&super.getNumX4()<=super.getNumX3()&&super.getNumX()<=super.getNumX4()){
            low=getNumX4();//point 4
        }
        return high - low;
    }

    //area
    public double areaP(){
        return getHeightP()*getWidthP();
    }

    //print
    @Override
    public String toString(){
        return String.format(super.toString(), "Width: ", getWidthP(), "Height: ", getHeightP(), "Area: ", areaP());
    }
}
