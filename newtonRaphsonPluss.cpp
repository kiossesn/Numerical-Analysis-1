#include<bits/stdc++.h>
#define EPSILON 0.00001
using namespace std;
// Function
double f(double x){
    //return exp(pow(sin(x),3.0))+pow(x,6.0)-2*pow(x,4.0)-pow(x,3.0)-1;
    return 94* pow(cos(x),3.0)-24* cos(x)+177* pow(sin(x),2.0)-108* pow(sin(x),4.0)-72* pow(cos(x),3.0)* pow(sin(x),2.0)-65;
}
// Derivative of the function
double df(double x){
    //return 6*pow(x,5.0) - 8*pow(x,3.0) - 3*pow(x,2.0) + 3*exp(pow(sin(x),3.0))*cos(x)*pow(sin(x),2.0);
    return 216* pow(cos(x),2.0)* pow(sin(x),3.0)-432* cos(x)* pow(sin(x),3.0)-144* pow(cos(x),4.0)* sin(x)-282* pow(cos(x),2.0)*sin(x)+354*cos(x)*sin(x)+24*sin(x);
}
// Second derivative of the function
double ddf(double x){
    //return 30*pow(x,4.0) - 3*exp(pow(sin(x),3.0))*pow(sin(x),3.0) - 24*pow(x,2.0) - 6*x + 6*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*sin(x) + 9*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*pow(sin(x),4.0);
    return 3* cos(x)*(216* pow(cos(x),2.0)-432* cos(x))* pow(sin(x),2.0)+ sin(x)*(576* pow(cos(x),3.0)* sin(x)+564*cos(x)*sin(x)-354*sin(x))+
                                                                          pow(sin(x),3.0)*(432* sin(x)-432*cos(x)* sin(x))+
                                                                          cos(x)*(-144* pow(cos(x),4.0)-282* pow(cos(x),2.0)+354*
                                                                                                                             cos(x)+24);
}
// Prints root of f(x) with error in EPSILON
void newtonRaphson(double x,double y){
    // Rep counter
    int count=0;
    if(f(x)*f(y)<0) {
        if(f(x)*ddf(x)>0) {
            double k= ddf(x)/ df(x);
            double h = df(x) / f(x);
            double j=1/(h-0.5*k);
            while (abs(j) >= EPSILON) {
                count++;
                h = df(x) / f(x);
                k= ddf(x)/ df(x);
                j=1/(h-0.5*k);
                // x(i+1) = x(i) - 1/( (f'(x) / f(x)) - 1/2 * f''(x)/f'(x)) .
                x = x - j;
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
int main() {
    double x0 = -0.5, x1 = -3;
    newtonRaphson(x0, x1);
    return 0;
}