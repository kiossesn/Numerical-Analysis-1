#include<bits/stdc++.h>
#define EPSILON 0.00001
using namespace std;
// Function
double f(double x){
    return exp(pow(sin(x),3.0))+pow(x,6.0)-2*pow(x,4.0)-pow(x,3.0)-1;
}
// Derivative of the function
double df(double x){
    return 6*pow(x,5.0) - 8*pow(x,3.0) - 3*pow(x,2.0) + 3*exp(pow(sin(x),3.0))*cos(x)*pow(sin(x),2.0);
}
// Second derivative of the function
double ddf(double x){
    return 30*pow(x,4.0) - 3*exp(pow(sin(x),3.0))*pow(sin(x),3.0) - 24*pow(x,2.0) - 6*x + 6*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*sin(x) + 9*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*pow(sin(x),4.0);
}
// Prints root of f(x) with error in EPSILON
void newtonRaphson(double x,double y){
    // Rep counter
    int count=0;
    if(f(x)*f(y)<0) {
        if(f(x)*ddf(x)>0) {
            double h = f(x) / df(x);
            while (abs(h) >= EPSILON) {
                count++;
                h = f(x) / df(x);
                // x(i+1) = x(i) - f(x) / f'(x)
                x = x - h;
                printf("%d.   x= %.5f   h=%.5f\n", count, x, h);
            }
            printf("The value of the root is : %.5f\n", x);
            cout << "count is " << count << endl;
        }
        else{
            cout << "You have not assumed right x0";
            return;
        }
    }
    else{
        cout << "You have not assumed right x0 and x1";
        return;
    }
}
// Main function
int main(){
    double x0 = -0.5,x1=-2;
    newtonRaphson(x0,x1);
    return 0;
}