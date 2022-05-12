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

void prt_arr(double *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] <<"    ";
    }
    cout << endl;
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

bool converge(double **a, int n){                  
    double sum;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < n; ++j) sum += std::abs(a[i][j]);
        sum -= std::abs(a[i][i]);
        if (sum > abs(a[i][i])) return false;
    }
    return true;
}

int seidel(double **a, double *b, double *prev, int n, double eps) {    
    if (!converge(a,n)){                                               
        return 1;
    }
    double normb = 0.0;
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

    double *curs = new double[n];
    
    double err = 1.0, ax;
    int count = 0;
    while (err > eps){
        count ++;
        err = 0.0;
        for (int i = 0; i < n; i++){
            ax = 0;
            for (int j = 0; j < i; j++){
                ax += a[i][j]*curs[j];
            }

            for (int j = i; j < n; j++){
                ax += a[i][j]*prev[j];
            }
            curs[i] = b[i] + ax;               
            err += std::abs(curs[i] - prev[i]);     
            prev[i] = curs[i];                      
        }
    }

    cout << "Solution" << endl;
    prt_arr(curs,n);

    cout << "Number of iterations: " << count;
    
    delete[] curs;

    return 0;
}

int main() {
    int i, j, n;
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
    }         

    double eps;
    cin >> eps;    

    if (seidel(a,b,x,n,eps)){
        cout << "The procedure does not converge\n";
    } else {
        mul_mat(save_a,x,b,n);              //Проверка 
        cout << "\nChecking" << endl;
        prt_arr(b,n);
    }

    del_mat(a, n);
    del_mat(save_a, n);
    delete[] b;
    delete[] x;
    return 0;
}