#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

void prt_mat(double ** a, int n) {            //Вывод матрицы
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

void del_mat(double **a, int n){            //Удаление матрицы
    for (int i = 0; i < n; i ++){
        delete[] a[i];
    }
    delete[] a;
}

void mul_mat(double **a, double *x, double *res, int n){ //Умножение матриц
    for (int i = 0; i < n; i++){
        res[i] = 0.0;
        for (int j = 0; j < n; j++){
            res[i] += a[i][j] * x[j];
        }
    }
}

double norm_mat(double **a, int n){                     //Нахождение l-нормы матрицы 
    double sum, max = -1.0;
    for (int i = 0; i < n; i ++){
        sum = 0.0;
        for (int j = 0; j < n; j++){
            sum += std::abs(a[j][i]);
        }
        if (sum > max){
            max = sum;
        }
    }
    return max;
}

int iter(double **a, double *b, double *prev, int n, double eps) {     //Метод итераций
    double normb = 0.0;
    for (int i = 0; i < n; i++){                                    // матрица бета
        b[i] = b[i]/a[i][i];
        prev[i] = b[i];
        normb += std::abs(b[i]);
    }

    for (int i = 0; i < n; i++){                                    // матрица альфа
        for (int j = 0; j < n; j++){
            if (i != j){
                a[i][j] = -a[i][j]/a[i][i];
            } 
        }
        a[i][i] = 0.0;
    }

    double norma = norm_mat(a, n);
    cout << "Matrix alpha\n";
    prt_mat(a,n);
    cout << "Matrix alpha norm: " << norma << endl;
    if (norma >= 1){                                                //проверка сходимости
        return 1;
    }
    cout << "Matrix beta\n";
    prt_arr(b,n);
    cout << "Matrix beta norm: " << normb << endl;
    
    double *curs = new double[n];
    double *ax = new double[n];

    double err = 1.0;
    int count = 0;
    while (err > eps){
        count ++;
        err = 0.0;
        for (int i = 0; i < n; i++){
            mul_mat(a,prev,ax,n);                   //ax = a*x_(k-1)
            curs[i] = b[i] + ax[i];                 //xk = b + a*x_(k-1)
            err += std::abs(curs[i] - prev[i]);     //Погрешность
            prev[i] = curs[i];                      //Подготовка к следующему шагу
        }
    }

    cout << "\nSolution" << endl;
    prt_arr(curs,n);

    cout << "\nNumber of iterations: " << count;
    cout << "\nTheoretical number of iterations: " << log(eps/(normb/(1-norma)))/log(norma) - 1 << endl;
    
    delete[] curs;
    delete[] ax;
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

    if (iter(a,b,x,n,eps)){
        cout << "The iterative procedure does not converge\n";
    } else {
        mul_mat(save_a,x,b,n);              //Проверка 
        cout << "\Checking" << endl;
        prt_arr(b,n);
    }

    del_mat(a, n);
    del_mat(save_a, n);
    delete[] b;
    delete[] x;
    return 0;
}