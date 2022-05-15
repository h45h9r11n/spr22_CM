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

void delta_cal(double *x, double *y, double **delta, int n){
    for (int j = 1; j < n; j++){
        for (int i = 0; i < n - j; i++){
            delta[i][j] = delta[i + 1][j-1] - delta[i][j-1];
        }
    }
}

void gen_val1(double *a, double *x, int n){
    double step = (x[n - 1] - x[0])/10;
    double valx = x[0], valy, mul;
    for (int i = 0; i < 10; i++){
        valx += step;
        valy = 0;
        for (int j = 0; j < n; j++){
            mul = a[j];
            for (int k = 0; k < j; k++){
                mul *= valx - x[k];
            }
            valy += mul;
        }
        cout << valx << " " << valy << endl;    
    }
}

void gen_val2(double *a, double *x, int n){
    double step = (x[n - 1] - x[0])/10;
    double valx = x[0], valy, mul;
    for (int i = 0; i < 10; i++){
        valx += step;
        valy = 0;
        for (int j = 0; j < n; j++){
            mul = a[j];
            for (int k = n - 1; k > n - j - 1; k--){
                mul *= valx - x[k];
            }
            valy += mul;
        }
        cout << valx << " " << valy << endl;    
    }
}

void interpolationNewton(double *x, double *y, double **delta, int h, int n){
    delta_cal(x,y,delta,n);
    double *a = new double[n];
    for (int i = 0; i < n; i++){
        a[i] = delta[0][i]/(factorial(i)*pow(h,i));
    }
    
    cout << "Newton forward" << endl;
    prt_arr(a,n);
    gen_val1(a,x,n);
    
    for (int i = 0; i < n; i++){
        a[i] = delta[n - i - 1][i]/(factorial(i)*pow(h,i));
    }
    
    cout << "Newton backward" << endl;
    prt_arr(a,n);
    gen_val2(a,x,n);
    delete[] a;
}

int main(){
    int i,j,h,n;
    cin >> n;
    n++;
    double *x = new double[n];
    double *y = new double[n];
    double ** delta = new double * [n];
    for (i = 0; i < n; i++){
        delta[i] = new double[n]; 
    }

    for (i = 0; i < n; i++){
        cin >> x[i];
    }

    for (i = 0; i < n; i++){
        cin >> y[i];
        delta[i][0] = y[i];
    }
    cin >> h;
    
    interpolationNewton(x,y,delta,h,n);
    
    delete_mat(delta,n);
    delete[] x;
    delete[] y;
    return 0;
}