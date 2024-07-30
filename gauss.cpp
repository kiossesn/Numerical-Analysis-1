#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
const int N=10,M=10;

using namespace std;

float* gauss(float A[N][M],float b[N],int n){
    float ratio;
    float *x=new float [n];
    int i,j,k;

    /* Setting precision. */
    cout<< setprecision(3)<< fixed;

    /* Make Augmented Matrix. */
    for(i=1;i<=n;i++){
        A[i][n+1]=b[i];
    }

    /* Applying Gauss Elimination */
    for(i=1;i<=n-1;i++){
        if(A[i][i] == 0.0){
            cout<<"Mathematical Error!";
            exit(0);
        }
        for(j=i+1;j<=n;j++){
            ratio = A[j][i]/A[i][i];
            for(k=1;k<=n+1;k++){
                A[j][k] = A[j][k] - ratio*A[i][k];
            }
        }
    }

    /* Obtaining Solution by Back Substitution Method */
    x[n] = A[n][n+1]/A[n][n];
    for(i=n-1;i>=1;i--){
        x[i] = A[i][n+1];
        for(j=i+1;j<=n;j++){
            x[i] = x[i] - A[i][j]*x[j];
        }
        x[i] = x[i]/A[i][i];
    }

    return x;
}
// Main function
int main(){
    int n,i,j;
    /* Reading number of unknowns */
    cout<<"Enter number of unknowns: ";
    cin>>n;
    float A[N][M],b[N];

    /* Reading Values */
    cout<<"Enter values of matrix A: "<< endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<"a["<< i<<"]"<< j<<"]= ";
            cin>>A[i][j];
        }
    }
    cout<<"Enter values for matrix b:"<<endl;
    for(i=1;i<=n;i++){
        cout<<"b["<< i<<"]= ";
        cin>>b[i];
    }
    /* Calling gauss */
    float *x=gauss(A,b,n);

    /* Displaying Solution */
    cout<< endl<<"Solution: "<< endl;
    for(i=1;i<=n;i++){
        cout<<"x["<< i<<"] = "<< x[i]<< endl;
    }
}