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
            cout << " " << std::setprecision(6) << std::fixed << a[i][j] << " \t";
        cout << "\n";
    }
}

void delete_mat(double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

bool is_zero (double a){
    if ((a > -1e-6) && (a < 1e-6))
        return true;
    else return false;
}

void solve(double ** a, double * b, int n) {     
    double x;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j != i){
                if (is_zero(a[i][i])){
                    cout << "There's no solution\n";
                    return;
                }
                x = a[j][i] / a[i][i];
                b[j] -= b[i] * x;
                for (int k = 0; k < n; k++){
                    a[j][k] -= a[i][k] * x;
                    
                }
            }
        }   
    }

    for (int i = 0; i < n; i++){
        x = a[i][i];
        b[i] = b[i] / x;
        for (int j = 0; j < n; j++){
            a[i][j] = a[i][j] / x;
            
        }
    }     
}
int main() {
    int i, j, n;
    cout << "N: ";
    cin >> n;

    double ** a = new double * [n];
    for (i = 0; i < n; i++)
        a[i] = new double[n];

    double *b = new double[n];
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
            cout << " A[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> a[i][j];
        }

        cout << " B[" << i + 1 << "] : ";
        cin >> b[i];

    }             

    solve(a,b,n);
    
    cout << "Solution" << endl;
    for (int i = 0; i < n; i++){
        cout << "x" << i + 1 << " = " << b[i] << endl;
    }

    delete_mat(a, n);
    delete[] b;

    return 0;
}