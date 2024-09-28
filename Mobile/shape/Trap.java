public class Trap extends Quadrilateral{
    //var
    public Trap(double numX, double numY, double numX2, double numY2, double numX3, double numY3, double numX4, double numY4){
        super(numX, numY, numX2, numY2, numX3, numY3, numX4, numY4);
    }

    //width 
    public double getWidthT(){
        double left=0;
        double right=0;
        left = Math.abs(super.getNumX()-super.getNumX2());
        right = Math.abs(super.getNumX3()-super.getNumX4());
        return left+right;
    }

    //height 
    public double getHeightT(){
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
    public double areaT(){
        return (getHeightT()*getWidthT())/2;
    }

    //print
    @Override
    public String toString(){
        return String.format(super.toString(), "Height: ", getHeightT(), "Area: ", areaT());
    }
}
