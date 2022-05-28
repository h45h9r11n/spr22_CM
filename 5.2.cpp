#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

double x0;
void prt_arr(double *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] <<"    ";
    }
    cout << endl;
}

void delete_mat (double **a, int n){
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

int factorial(int n){
    int res = 1;
    for (int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

void delta_cal(double *x, double *y, double **delta, int n, int h){
    for (int j = 1; j < n; j++) 
        for (int i = 0; i < n - j; i++) 
            delta[i][j + 1] = delta[i + 1][j]- delta[i][j];
}

void interpolationGauss(double *x, double *y, double **delta, int h, int n){
    delta_cal(x,y,delta,n,h);
    double u, m = 1.0, y0 = 0.0;
    int i,j,z;
    for (i = 0; i < n; ++i) {
        u = (x0 - delta[i][0]) / h;
        if (0 < u && u <= 0.5) break;
    }
    if (i == n) {
        cout << "\nCondition 0 < u <= 0.5 not satisfied" << endl;
        return;
    } else z = i;
    cout << "u = " << u <<" is found at f(" << delta[z][0] << ")" <<endl;
    for (j = 1, i = 0; j <= n; j++) {
        y0 += m * delta[z - i][j];
        if (j % 2 == 1) m *= (u + double(i)) / (double)(j);
        else m *= (u - double(++i)) / (double)(j);
        if ((z - i) < 0 || (z - i) > (n - j - 1)) break;
    }
    cout << "f("<< x0 <<") = " << y0 << endl;

}

int main(){
    int i,j,h,n;
    cin >> n;
    double *x = new double[n + 1];
    double *y = new double[n + 1];
    double ** delta = new double * [n + 1];
    for (i = 0; i <= n; i++){
        delta[i] = new double[n + 1]; 
    }

    for (i = 0; i < n; i++){
        cin >> x[i];
        delta[i][0] = x[i];
    }

    for (i = 0; i < n; i++){
        cin >> y[i];
        delta[i][1] = y[i];
    }
    cin >> h;
    cin >> x0;
    interpolationGauss(x,y,delta,h,n);
    delete_mat(delta,n + 1);
    delete[] x;
    delete[] y;
    return 0;
}

