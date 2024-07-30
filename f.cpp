#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
// Function
double f(double x){
    return exp(pow(sin(x),3.0))+pow(x,6.0)-2*pow(x,4.0)-pow(x,3.0)-1;
}
// First derivative of the function
double g(double x){
    return 6*pow(x,5.0) - 8*pow(x,3.0) - 3*pow(x,2.0) + 3*exp(pow(sin(x),3.0))*cos(x)*pow(sin(x),2.0);
}
// Second derivative of the function
double h(double x){
    return 30*pow(x,4.0) - 3*exp(pow(sin(x),3.0))*pow(sin(x),3.0) - 24*pow(x,2.0) - 6*x + 6*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*sin(x) + 9*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*pow(sin(x),4.0);
}
double f2(double x){
    return 94* pow(cos(x),3.0)-24* cos(x)+177* pow(sin(x),2.0)-108* pow(sin(x),4.0)-72* pow(cos(x),3.0)* pow(sin(x),2.0)-65;
}
double g2(double x){
    return 216* pow(cos(x),2.0)* pow(sin(x),3.0)-432* cos(x)* pow(sin(x),3.0)-144* pow(cos(x),4.0)* sin(x)-282* pow(cos(x),2.0)*sin(x)+354*cos(x)*sin(x)+24*sin(x);
}
double h2(double x){
    return 30*pow(x,4.0) - 3*exp(pow(sin(x),3.0))*pow(sin(x),3.0) - 24*pow(x,2.0) - 6*x + 6*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*sin(x) + 9*exp(pow(sin(x),3.0))*pow(cos(x),2.0)*pow(sin(x),4.0);
}
// Main function
int main(){
    double x;
    cin>>x;
    printf("f(%.5f)=%.5f\n",x,f(x));
    printf("f'(%.5f)=%.5f\n",x,g(x));
    printf("f''(%.5f)=%.5f\n",x,h(x));
    printf("f2(%.5f)=%.5f\n",x,f2(x));
    printf("f2'(%.5f)=%.5f\n",x,g2(x));
    printf("f2''(%.5f)=%.5f",x,h2(x));
}