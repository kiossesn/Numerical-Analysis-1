#include<iostream>
#include<conio.h>
#include <cmath>
using namespace std;

float* gauss_seidel(float **A,float *b,int n){
    int flag=0,count=1;
    float *x=new float[n+1];
    float y[n+1],k;

    /* Set precision */
    cout.precision(8);
    cout.setf(ios::fixed);

    cout<<"\n----------------------------------------------------------------------"<<endl;

    /* Perform iterations to calculate x1,x2,...xn */
    do{
        //cout<<count<<".";
        for (int i = 1; i <= n; i++){
            //k takes the initial x[i] value
            k=x[i];
            //y[i] takes b/value of diag element
            y[i] = (b[i] / A[i][i]);
            for (int j = 1; j <= n; j++){
                if (j == i)
                    continue;
                //y[i] takes last y[i] - element(not diag)/diag element * last x value
                y[i] = y[i] - ((A[i][j] / A[i][i]) * x[j]);
                //x[i] takes new value
                x[i] = y[i];
            }
            //cout<<"     x"<<i<<" = "<<y[i]<<endl;
            //Compare the new value with the last value
            if (abs(x[i]-k) <= 0.0001) flag++;
        }
        cout <<endl;
        count++;
        //If the values of all the variables don't differ from their previous values with error more than 0.005 then flag must be n --> stop the loop
    }while(flag<n);

    return x;
}

/* Make matrix A(nxn) */
float** makeMatrixA(int n){
    float **A=new float* [n+1];
    for(int i=1;i<=n;i++){
        A[i]=new float[n+1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)A[i][j]=-5;
            else if(j==i+1||j==i-1)A[i][j]=-2;
            else A[i][j]=0;
        }
    }
    return A;
}

/* Make matrix b(n) */
float* makeMatrixb(int n){
    float *b=new float[n+1];
    for(int i=1;i<=n;i++){
        if(i==1||i==n)b[i]=3;
        else b[i]=1;
    }
    return b;
}

/* Print the solution */
void printSolution(float *x,int n) {
    cout << "\n The solution is as follows:\n";
    for (int i = 1; i <= n; i++)
        cout << "x" << i << " = " << x[i] << endl;
}

int main() {
    int n1=10,n2=10000,n3=3;

    float **A1= makeMatrixA(n1);
    float *b1= makeMatrixb(n1);
    float **A2= makeMatrixA(n2);
    float *b2= makeMatrixb(n2);

    /* Call gauss_seidel */
    cout<<"call gauss seidel"<<endl;
    float* x=gauss_seidel(A2,b2,n2);

    printSolution(x,n2);
    return 0;
}