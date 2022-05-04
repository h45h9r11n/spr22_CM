#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

bool hasinv = true;
void prt_mat(double ** a, int n) {                         //вывод матрицы
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << " " << std::setprecision(6) << std::fixed << a[i][j] << " \t";
        cout << "\n";
    }
}

void matrixE(double **e, int n){                           // единичная матрица
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j){
                e[i][j] = 1;
            } else {
                e[i][j] = 0;
            }
        }
    }
    return;
}

void delete_mat (double **a, int n){
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

void inverse(double ** a, double ** e, int n) {       //вычисление обратной матрицы на основе элементарных преобразований матрицы
    double x;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j != i){
                if (is_zero(a[i][i])){
                    cout << "\nMatrix has no inverse\n";
                    hasinv = false;
                    return;
                }
                x = a[j][i] / a[i][i];
                for (int k = 0; k < n; k++){
                    a[j][k] -= a[i][k] * x;
                    e[j][k] -= e[i][k] * x;
                }
            }
        }   
    }

    for (int i = 0; i < n; i++){
        x = a[i][i];
        for (int j = 0; j < n; j++){
            a[i][j] = a[i][j] / x;
            e[i][j] = e[i][j] / x;
        }
    }     
}

void mul(double ** a, double ** b, double ** e, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                e[i][j] += a[i][k] * b[k][j];
            }
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

    double ** save_a = new double * [n];
    for (i = 0; i < n; i++)
        save_a[i] = new double[n];

    double ** check = new double * [n];
    for (i = 0; i < n; i++)
        check[i] = new double[n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            check[i][j] = 0;
        }
    }

    double ** ret = new double * [n];
    for (i = 0; i < n; i++)
        ret[i] = new double[n];

    matrixE(ret, n);

    for (i = 0; i < n; i++)                             //ввод матрицы
        for (j = 0; j < n; j++) {
        cout << " A[" << i + 1 << "][" << j + 1 << "] : ";
        cin >> a[i][j];
        save_a[i][j] = a[i][j];
        }

    inverse(a, ret, n);                                 //вычисление обратной матрицы
   
    if(hasinv){
        mul(ret, save_a, check, n);                     //проверка
        cout << "\nChecking: " << endl;
        prt_mat(check,n);                               
        cout << "\nSolution: " << endl;
        prt_mat(ret,n);                                 //ответ
    }
    
    delete_mat (a, n);
    delete_mat (save_a, n);
    delete_mat (ret, n);
    delete_mat (check, n);
    return 0;
}