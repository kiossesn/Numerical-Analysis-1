#include <bits/stdc++.h>
using namespace std;
const int N=10,M=10;

float** cholesky(float matrix[N][M],int n){
    // Print matrix
    cout<<"Matrix: "<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if(matrix[i][j]<0 || matrix[i][j]>9)cout<< matrix[i][j]<<"  ";
            else cout<< matrix[i][j]<<"   ";
        cout<<endl;
    }
    // Make lower matrix
    float** lower = new float*[n+1];
    for (int i = 1; i <= n; i++) {
        lower[i] = new float[N];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
         lower[i][j]=0.0;
    }

    // Transform matrix into Lower Triangular
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            float sum = 0.0;

            if (j == i){
                for (int k = 1; k < j; k++)
                    sum += pow(lower[j][k], 2.0);
                lower[j][j] = sqrt(matrix[j][j] -sum);
            }
            else {
                // Find L(i, j) using L(j, j)
                for (int k = 1; k < j; k++)
                    sum += (lower[i][k] * lower[j][k]);
                lower[i][j] = (matrix[i][j] - sum) /lower[j][j];
            }
        }
    }
    return lower;
}

// Main function
int main(){
    int n,i,j;
    /* Reading number of unknowns */
    cout<<"Enter number of unknowns: ";
    cin>>n;
    float A[N][M];

    /* Reading Values */
    cout<<"Enter values of matrix A: "<< endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<"a["<< i<<"]"<< j<<"]= ";
            cin>>A[i][j];
        }
    }

    /* Calling cholesky */
    float **L=cholesky(A,n);

    /* Displaying Lower Triangular and its Transpose */
    cout<< "Solution: "<<endl;
    for (i = 1; i <= n; i++) {
        if(L[i][1]>=0)cout<<" ";
        for (j = 1; j <= n; j++) {
            if (L[i][j+1] < 0 || L[i][j] > 9)cout << L[i][j] <<"  ";
            else cout << L[i][j] << "   ";
        }
        cout<<endl;
    }

    return 0;
}