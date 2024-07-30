#include<iostream>
#include<math.h>
#define EPSILON 0.00001
using namespace std;
// Function
double f(double x){
    return exp(pow(sin(x),3.0))+pow(x,6.0)-2*pow(x,4.0)-pow(x,3.0)-1;
}
// Prints root of f(x) with error in EPSILON
void secant(double b, double c){
    double a,xm;
    // Rep counter
    int count=0;
    if(f(b)*f(c)<0) {
        do {
            // calculate the intermediate value
            a= c - f(c) * (c - b) / (f(c) - f(b));
            // update the value of interval
            b = c;
            c = a;

            count++;
            // check if a is root of equation or not
            if (f(a) == 0)
                break;
            xm = c - f(c) * (c - b) / (f(c) - f(b));
            printf("%d.   c= %.5f\n", count, a);
        } while (fabs(xm - a) >= EPSILON);
        printf("The value of the root is : %.5f\n", a);
        cout << "count is " << count << endl;
    }
    else {
        cout << "You have not assumed right a and b";
        return;
    }
}
int main(){
   double a=-2,b=-0.5;
   secant(a,b);
   return 0;
}