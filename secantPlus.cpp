#include<iostream>
#include<math.h>
#define EPSILON 0.00001
using namespace std;
// Function
double f(double x){
    return 94* pow(cos(x),3.0)-24* cos(x)+177* pow(sin(x),2.0)-108* pow(sin(x),4.0)-72* pow(cos(x),2.0)* pow(sin(x),2.0)-65;
}
// Prints root of f(x) with error in EPSILON
void secant(double x0, double x1,double x2) {
    double x3,xm;
    // Rep counter
    int count = 0;
    if(f(x2)*f(x1)<0) {
        do {
            // calculate the intermediate value
            double q = f(x0) / f(x1);
            double r = f(x2) / f(x1);
            double s = f(x2) / f(x0);
            x3 = x2 - (r * (r - q) * (x2 - x1) + (1 - r) * s * (x2 - x0)) / ((q - 1) * (r - 1) * (s - 1));
            // update the value of interval
            x0 = x1;
            x1 = x2;
            x2 = x3;

            count++;
            // check if x3 is root of equation or not
            if (f(x3) == 0)
                break;
            xm = x2 - (r * (r - q) * (x2 - x1) + (1 - r) * s * (x2 - x0)) / ((q - 1) * (r - 1) * (s - 1));
            printf("%d.   x3= %.5f\n", count, x3);
        } while (fabs(xm - x3) >= EPSILON);
        printf("The value of the root is : %.5f\n", x3);
        cout << "count is " << count << endl;
    }
    else{
        cout << "You have not assumed right a and b";
        return;
    }
}
int main(){
    double x0=-3,x1=1,x2=2;
    secant(x0,x1,x2);
    return 0;
}