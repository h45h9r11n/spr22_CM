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

void delete_mat (double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

void solve(double ** a, int n) {       
    double x;
    double det = 1;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            x = a[j][i] / a[i][i];
            for (int k = 0; k < n; k++){
                a[j][k] -= a[i][k] * x;
            }
        }
        det *= a[i][i];
    }
    cout << endl;
    prt_mat(a, n);
    
    cout << "detA = " << det << endl;
}


int main() {
    int i, j, n;
    cout << "N: ";
    cin >> n;

    double ** a = new double * [n];
    for (i = 0; i < n; i++)
        a[i] = new double[n];

    for (i = 0; i < n; i++)                   
        for (j = 0; j < n; j++) {
        cout << " A[" << i + 1 << "][" << j + 1 << "] : ";
        cin >> a[i][j];
        }


    cout << "\n";
    prt_mat(a, n);
    solve(a,n);

    delete_mat(a,n);
    return 0;
}