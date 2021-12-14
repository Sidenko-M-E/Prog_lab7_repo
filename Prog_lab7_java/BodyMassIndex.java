package Prog_lab7_java;

import java.lang.Math;

public class BodyMassIndex {
    static int calculate(int height, double weight)
    {
            return ((int)Math.round(weight/Math.pow(((double)height)/100 , 2)));
    }
}
