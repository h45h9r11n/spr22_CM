#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void prt_mat(double ** a, int n) {   
    cout << "\n";
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << " " << std::setprecision(2) << std::fixed << a[i][j] << " \t";
        cout << "\n";
    }
}

void delete_mat(double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

void cholesky(double **a, double **b1, double **c, double *b, double *x, double *y, int n){
    double sum;
    for (int i = 1; i <= n; i++){
        c[i][i] = 1;
    }
    for (int i = 1; i <= n; i++){
        b1[i][1] = a[i][1];
    }

    for (int j = 1; j <= n; j++){
        c[1][j] = a[1][j]/b1[1][1];
    }


    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= i; j++){
            sum = 0;
            for (int k = 1; k < j; k++){
                sum += b1[i][k] * c[k][j];
            }

            b1[i][j] = a[i][j] - sum;
            
        }

        for (int j = i + 1; j <= n; j++){
            sum = 0;
            for (int k = 1; k < i; k++){
                sum += b1[i][k] * c[k][j];
            }

            c[i][j] = 1/b1[i][i]*(a[i][j] - sum);
            
        }
    }
    
    cout << "\nA = B*C" << endl;
    cout << "\nMatrix B" << endl;
    prt_mat(b1,n);
    cout << "\nMaxtrix C" << endl;
    prt_mat(c,n);
    
    y[1] = b[1]/b1[1][1];
    for (int i = 2; i <= n; i++){
        sum = 0;
        for (int k = 1; k < i; k++){
            sum += b1[i][k]*y[k];
        }
        y[i] = 1/b1[i][i] * (b[i] - sum);
        
    }

    x[n] = y[n];
    for (int i = 3; i >= 1; i--){
        sum = 0;
        for (int k = i + 1; k <= n; k++){
            sum += c[i][k]*x[k];
        }

        x[i] = y[i] - sum;
    }
    
    cout << endl;
    for (int i = 1; i <= n; i++){
         cout << "y" << i << " = " << y[i] << endl;
    }
    
    cout << "\nSolution" << endl;
    for (int i = 1; i <= n; i++){
         cout << "x" << i << " = " << x[i] << endl;
    }
    
    
}

int main(){
    int i, j, n;
    cout << "N: ";
    cin >> n;
    n++;

    double ** a = new double * [n];
    for (i = 0; i < n; i++)
        a[i] = new double[n];

    double *b = new double[n];
    for (i = 1; i < n; i++){
        for (j = 1; j < n; j++) {
            cout << " A[" << i << "][" << j << "] : ";
            cin >> a[i][j];
        }

        cout << " B[" << i << "] : ";
        cin >> b[i];
    }      

    double ** b1 = new double * [n];
    for (i = 0; i < n; i++)
        b1[i] = new double[n];

    double ** c = new double * [n];
    for (i = 0; i < n; i++)
        c[i] = new double[n];        
    
    double *x = new double[n];
    double *y = new double[n];
    cholesky(a,b1,c,b,x,y,n - 1);

    return 0;
}