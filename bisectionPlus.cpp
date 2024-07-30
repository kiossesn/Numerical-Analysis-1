#include <iostream>
#include <math.h>
using namespace std;
#define EPSILON 0.00001
// Function
double f(double x){
    //return exp(pow(sin(x),3.0))+pow(x,6.0)-2*pow(x,4.0)-pow(x,3.0)-1;
    return 94* pow(cos(x),3.0)-24* cos(x)+177* pow(sin(x),2.0)-108* pow(sin(x),4.0)-72* pow(cos(x),3.0)* pow(sin(x),2.0)-65;
}
// Prints root of f(x) with error in EPSILON
void bisection(double a, double b){
    // Rep counter
    int count=0;
    if (f(a) * f(b) >= 0){
        cout << "You have not assumed right a and b";
        return;
    }
    if(f(a)==0){
        printf("The value of the root is : %.5f\n", a);
        cout<<"count is "<<count<<endl;
        return;
    }
    if(f(b)==0){
        printf("The value of the root is : %.5f\n", b);
        cout<<"count is "<<count<<endl;
        return;
    }
    double c = a;
    while ((b-a) >= EPSILON){
        count++;
        // Find random point between a and b
        double num = (double)rand() / RAND_MAX;
        c= a + num * (b - a);
        cout<<count<<".  a= "<<a<<"  b= "<<b<<"   c= "<<c<<endl;
        // Check if c is root
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
    double a =-1.5, b =-1;
    bisection(a, b);
    return 0;
}