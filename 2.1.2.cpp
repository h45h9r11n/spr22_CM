#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void delete_mat (double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

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

    double detA;
    cout << "\n";

    detA = det(a, n);                            

    cout << "\ndetA = " << detA;
    cout << endl;

    delete_mat (b, n);
    return 0;
}