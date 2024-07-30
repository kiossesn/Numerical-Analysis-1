#include <iostream>
#include <math.h>
using namespace std;
#define EPSILON 0.00001
// Function
double f(double x){
    return exp(pow(sin(x),3.0))+pow(x,6.0)-2*pow(x,4.0)-pow(x,3.0)-1;
}
// Prints root of f(x) with error in EPSILON
void bisection(double a, double b){
    if (f(a) * f(b) >= 0){
        cout << "You have not assumed right a and b";
        return;
    }
    double c = a;
    // Rep counter
    int count=0;
    while ((b-a) >= EPSILON){
        count++;
        // Find middle point
        c = (a+b)/2;
        cout<<count<<".   c= "<<c<<endl;
        // Check if middle point is root
        if (f(c) == 0.0)
            break;
        // Decide the side to repeat the steps
        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("The value of the root is : %.5f\n", c);
    cout<<"count is "<<count<<endl;
}
// Main function
int main(){
    double a =-2, b = -0.5;
    bisection(a, b);
    return 0;
}