#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void minor(double ** b, double ** a, int i, int n) {    
    int j, k, p = 0, q = 0;
    for (j = 1; j < n; j++)
        for (k = 0; k < n; k++) {
            if (k == i)
                continue;
            b[p][q] = a[j][k];
            p++;
            if (p == (n - 1)) {
                q++;
                p = 0;
            }
        }
    return;
}

void delete_mat(double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

double det(double ** a, int n) {                    
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
    else{
        double sum = 0;
        double ** b = new double * [n];
        for (int i = 0; i < n; i++)
            b[i] = new double[n];

        for (int i = 0; i < n; i++) {
            minor(b, a, i, n);
            sum = (double)(sum + a[0][i] * pow(-1, i) * det(b, (n - 1)));
        }

        delete_mat (b,n);
        return sum;
    }
}

void swap(double **a, int n, int index, double *b){
    double tmp;
    for (int i = 0; i < n; i++){
        tmp = a[i][index];
        a[i][index] = b[i];
        b[i] = tmp;
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

    double detA, det_i;
    cout << "\n";
    detA = det(a, n);                            
    cout << "\ndetA = " << detA;
    cout << endl;
    double *x = new double[n];
    for (int i = 0; i < n; i++){
        swap(a, n, i, b);
        det_i = det(a, n);
        swap(a, n, i, b);
        x[i] = det_i/detA;
    }

    for (int i = 0; i < n; i++){
        cout << "x" << i << " = " << x[i] << endl;
    }

    delete_mat(a, n);
    delete[] b;
    delete[] x;
    return 0;
}