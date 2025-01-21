#include <stdio.h>
#include <math.h>
/*
 * Use C to calculate complex mathematical expressions.
 */



//Declaring Functions
double inverseFactorial(int n);
double taylorSeries(double x, int numTerms);
double integralTaylorSeries(double lowerLimit, double upperLimit, int numTerms);
double riemannSum(double lowerLimit, double upperLimit, int numRectangles);

int main(void) {
    //testing
    printf("%f\n",inverseFactorial(0));
    printf("%f\n", taylorSeries(-3,100));
    printf("%f\n", integralTaylorSeries(-2,0,3));
    printf("%f\n", riemannSum(-2,0,3000));

}

//Uses Equation (1) to evaluate the inverse factorial of an input integer
//Takes in value of n as int
//outputs inverse factorial of n
double inverseFactorial(int n) {
    //var to be outputted
    double invFact = 1;
    //loop: divide 1 by n until n = 0
    for (int i = n;i>0;i--) {
        invFact/=i;
    }
    return invFact;
}
//Uses Equation (3) to evaluate an approximation of e^x^2.
//Takes in value of x as a double, and number of terms in taylor series as integer
//outputs approximation of e^y^2 at y = x
double taylorSeries(double x, int numTerms) {
    //var to be outputted
    double num = 0;
    //loop: add n term in taylor series until n<=numTerms-1, where numTerms is N from equation (3)
    for (int n = 0; n <= numTerms-1;n++) {
        num+= inverseFactorial(n)* pow(x,2*n);
    }
    return num;
}

//Uses Equation (4) to evaluate an approximation of integral of e^x^2.
//Takes in values of lowerLimit and upperLimit as a doubles, and number of terms in taylor series as integer
//outputs approximation of integral of e^x^2 from lowerLimit to upperLimit using taylor series approximation
double integralTaylorSeries(double lowerLimit, double upperLimit, int numTerms) {
    //var to be outputted
    double num = 0;
    //loop: add n term in taylor series integral until n <= numTerms-1, where numTerms is N from equation (4)
    for (int n = 0; n <= numTerms-1;n++) {
        num+=inverseFactorial(n)*((pow(upperLimit,2*n+1))/(2*n+1)-(pow(lowerLimit,2*n+1))/(2*n+1));
    }
    return num;
}

//Uses Equation (5) to evaluate an approximation of integral of e^x^2.
//Takes in values of lowerLimit and upperLimit as a doubles, and number of rectangles in Reimann sum as integer
//outputs approximation of integral of e^x^2 from lowerLimit to upperLimit using riemann sum
double riemannSum(double lowerLimit, double upperLimit, int numRectangles) {
    //var to be outputted
    double num = 0;
    //loop: add n term in Riemann sum until n <= numRectangles, where numTerms is N from equation (5)
    for (int n = 0; n <= numRectangles-1;n++) {
        num+= taylorSeries(lowerLimit+n*((upperLimit-lowerLimit)/numRectangles),100)*((upperLimit-lowerLimit)/numRectangles);
    }
    return num;
}


