#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void prt_arr(double *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] <<"    ";
    }
    cout << endl;
}

void prt_mat(double ** a, int n) {          
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << " " << std::setprecision(1) << std::fixed << a[i][j] << " \t";
        cout << "\n";
    }
}

void delete_mat (double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

double scalar(double *a, double *b, int n) {
    double res;
    for (int i = 0; i < n; i++){
        res += a[i]*b[i];
    }
    return res;
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

void vector_mul(double **a, int n){
    double *res = new double[n];
    double ** sub_mat = new double * [n];
    for (int i = 0; i < n; i++)
        sub_mat[i] = new double[n]; 

    for (int i = 0; i < n; i++){
        minor(sub_mat, a, i, n);
        res[i] = pow(-1, i)* det(sub_mat, n - 1);
    }

    cout << "Cross product " << endl;
    
    for (int i = 0; i < n; i++){
        cout << res[i] << "\t";
    }
    
    cout << "\nChecking\n";
    for (int i = 0; i < n; i++){
        cout << scalar(a[i], res,n) << "\t";
    }
    
    delete[] res;
    delete_mat(sub_mat,n);
}

int main() {
    int i,j, n;
    cin >> n;

    double ** matrix = new double * [n];
    for (i = 0; i < n; i++)
        matrix[i] = new double[n]; 

    for (i = 0; i < n; i++){
        matrix[0][i] = 0;
    }
    for (i = 1; i < n; i++)                   
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }

    cout << "Scalar multiply: " << scalar(matrix[1], matrix[2], n) << endl;
    vector_mul(matrix, n);
    delete_mat(matrix, n);
    return 0;
} 