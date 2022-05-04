#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void prt_mat(double ** a, int n) {                        
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << " " << std::setprecision(10) << std::fixed << a[i][j] << " \t";
        cout << "\n";
    }
}

void del_mat(double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

void mul_mat(double **a, double *x, double *res, int n){
    for (int i = 0; i < n; i++){
        res[i] = 0.0;
        for (int j = 0; j < n; j++){
            res[i] += a[i][j] * x[j];
        }
    }
}

void solve(double **a, double *b, double *prev, int n, double eps) {     
    double *curs = new double[n];
    double *ax = new double[n];

    for (int i = 0; i < n; i++){
        b[i] = b[i]/a[i][i];
        prev[i] = b[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j){
                a[i][j] = -a[i][j]/a[i][i];
            } 
        }
        a[i][i] = 0.0;
    }
    
    prt_mat(a,n);
    
    double err = 1.0;
    while (err > eps){
        err = 0.0;
        for (int i = 0; i < n; i++){
            mul_mat(a,prev,ax,n);
            curs[i] = b[i] + ax[i];
            err += std::abs(curs[i] - prev[i]);
            prev[i] = curs[i];
        }
    }

    cout << "\nSolution" << endl;
    for (int i = 0; i < n; i++){
        cout << "x" << i + 1 << " = " << curs[i] << endl;
    }

    delete[] curs;
    delete[] ax;
}

int main() {
    int i, j, n;
    cout << "N: ";
    cin >> n;

    double ** a = new double * [n];
    for (i = 0; i < n; i++)
        a[i] = new double[n];

    double ** save_a = new double * [n];
    for (i = 0; i < n; i++)
        save_a[i] = new double[n];

    double *b = new double[n];
    double *save_b = new double[n];
    double *x = new double[n];

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
            save_a[i][j] = a[i][j];
        }
        cin >> b[i];
        save_b[i] = b[i];
    }         

    double eps;
    cin >> eps;    

    solve(a,b,x,n,eps);  
    mul_mat(save_a,x,b,n);
    for (int i = 0; i < n; i++){
        cout << "b" << i + 1 << " = " << b[i] << endl;
    }

    del_mat(a, n);
    del_mat(save_a, n);
    delete[] b;
    delete[] save_b;
    delete[] x;
    return 0;
}