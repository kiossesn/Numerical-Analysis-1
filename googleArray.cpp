#include<iostream>
#include<conio.h>
#include <cmath>
#include <iomanip>
const int N=15,M=15;
using namespace std;

void powerMethod(float a[N][M]){
    float  b_0[15],b_new[15],z;
    float temp, l,sum=0;
    int i,j, step=1;
    /* Setting precision */
    cout<< setprecision(5)<< fixed;

    /* Initial Guess Vector b_0=[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1] */
    for(i=0;i<15;i++){
        b_0[i]=1;
    }
    /* Initializing Lambda_Old */
    l = b_0[0];

    /* Setting label for repetition */
    up:
    /* Multiplication (b_k = A * b_k-1) */
    for(i=0;i<15;i++){
        temp = 0.0;
        for(j=0;j<15;j++){
            temp = temp + a[i][j]*b_0[j];
        }
        b_new[i] = temp;
    }
    /* Replacing b_0 by b_new */
    for(i=0;i<15;i++){
        b_0[i] = b_new[i];
    }
    /* Taking the first value of b_0 */
    for(i=0;i<N;i++) {
        if (b_0[i] == 0)continue;
        else {
            z = b_0[i];
            break;
        }
    }
    /* Normalization */
    for(i=0;i<15;i++){
        b_0[i] = 1/z * b_0[i];
    }
    /* Display */
    cout<< endl<< endl<<"STEP-"<< step<< endl;
    cout<<"Eigen Value = "<< z<< endl;
    cout<<"Eigen Vector: "<< endl;
    cout<<"[";
    for(i=0;i<15;i++){
        cout<< b_0[i]<<"  ";
    }
    cout<<"\b\b\b]";
    /* Checking Accuracy */
    if(z!=1){
        l=z;
        step++;
        goto up;
    }
    /* Normalization */
    for(i=0;i<N;i++){
        sum=sum+b_0[i];
    }
    for(i=0;i<N;i++){
        b_0[i]=b_0[i]/sum;
    }
    /* Display */
    cout<< endl<< endl<<"STEP-"<< step<< endl;
    cout<<"Eigen Value = "<< z<< endl;
    cout<<"Eigen Vector: "<< endl;
    cout<<"[";
    for(i=0;i<15;i++){
        cout<< b_0[i]<<"  ";
    }
    cout<<"]";

}
int main() {
    float G[N][M],A[N][M],sum,sumj[15];
    double q = 0.15;
    int ni[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j]=0;
        }
    }
    A[0][1]=1;
    A[0][8]=1;
    A[1][2]=1;
    A[1][4]=1;
    A[1][6]=1;
    A[2][1]=1;
    A[2][5]=1;
    A[2][7]=1;
    A[3][2]=1;
    A[3][11]=1;
    A[4][0]=1;

    A[4][9]=1;

    A[5][9]=1;
    A[5][10]=1;
    A[6][9]=1;
    A[6][10]=1;
    A[7][3]=1;
    A[7][10]=3;
    A[8][4]=1;
    A[8][5]=1;
    A[8][9]=1;
    A[9][12]=1;
    A[10][14]=1;
    A[11][6]=1;
    A[11][7]=1;
    A[11][10]=3;
    A[12][8]=1;
    A[12][13]=1;
    A[13][9]=1;
    A[13][10]=1;
    A[13][12]=1;
    A[13][14]=1;
    A[14][11]=1;
    A[14][13]=1;
    //ex 3
    //A[5][4]=1;
    //A[6][4]=1;
    //A[9][4]=1;
    //A[10][4]=1;

    //find ni for every row
    for (int i = 0; i < N; i++) {
        sum=0.0;
        for (int j = 0; j < N; j++) {
            sum+=A[i][j];
        }
        ni[i]=sum;
    }
    //make array G
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j]= q/N + A[j][i]*(1-q)/ni[j];
        }
    }
    for (int j = 0; j < N; j++) {
        sum=0.0;
        for (int i = 0; i < N; i++) {
            sum = sum + G[i][j];
        }
        sumj[j]=sum;
    }
    for (int j = 0; j < N; j++) {
        cout<<sumj[j]<<" ";
    }
    cout<<endl;

    //print array A
    cout<<"A: "<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //print array G
    cout<<"G: "<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.5f ",G[i][j]);
        }
        cout<<endl;
    }
    //find max eigenvalue of G
    powerMethod(G);
}