#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

void prt_mat(long double ** a, int n) {                         //вывод матрицы
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << " " << std::setprecision(6) << fixed << a[i][j] << " \t";
        cout << "\n";
    }
}

void minor(long double ** b, long double ** a, int i, int n) {  //минор матрицы а к елементу а_1i
    int j, l, h = 0, k = 0;
    for (l = 1; l < n; l++)
        for (j = 0; j < n; j++) {
            if (j == i)
                continue;
            b[h][k] = a[l][j];
            k++;
            if (k == (n - 1)) {
                h++;
                k = 0;
            }
        }
    return;
}

long double det(long double ** a, int n) {                      //вычислим определитель по теореме Лапласа
    int i;
    long double sum = 0;
    long double ** b = new long double * [n];
    for (i = 0; i < n; i++)
        b[i] = new long double[n];
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
    else
        for (i = 0; i < n; i++) {
            minor(b, a, i, n);
            sum = (long double)(sum + a[0][i] * pow(-1, i) * det(b, (n - 1)));
        }
    delete[] * b;
    return sum;
}

void matrixE(long double **e, int n){                           // создаем единичную матрицу
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

void inverse(long double ** a, long double ** e, int n) {       //вычисление обратной матрицы на основе элементарных преобразований матрицы
    long double x;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (j != i){
                x = a[j][i] / a[i][i];
                for (int k = 0; k < n; k++){
                    a[j][k] -= a[i][k] * x;
                    e[j][k] -= e[i][k] * x;
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

void mul(long double ** a, long double ** b, long double ** e, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                e[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return;
}

int main() {
    int i, j, n;
    cout << "N: ";
    cin >> n;

    long double ** a = new long double * [n];
    for (i = 0; i < n; i++)
        a[i] = new long double[n];

    long double ** save_a = new long double * [n];
    for (i = 0; i < n; i++)
        save_a[i] = new long double[n];

    long double ** check = new long double * [n];
    for (i = 0; i < n; i++)
        check[i] = new long double[n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            check[i][j] = 0;
        }
    }

    long double ** ret = new long double * [n];
    for (i = 0; i < n; i++)
        ret[i] = new long double[n];

    matrixE(ret, n);

    for (i = 0; i < n; i++)                         //ввод матрицы
        for (j = 0; j < n; j++) {
        cout << " Element[" << i + 1 << "][" << j + 1 << "] : ";
        cin >> a[i][j];
        save_a[i][j] = a[i][j];
        }

    long double deter;
    cout << "\n";
    prt_mat(a, n);
    deter = (long double) det(a, n);                //ищем определитель матрицы
    cout << "-------------------------\n";
    cout << "\nDeterm of matrix : " << deter;
    cout << "\n------------------------\n";
    
    if (deter == 0) {                               //не существует обратной матрицы особенной матрицы                                       
        cout << "\nNo inverse matrix\n";
        goto END;
    } else if (n == 1){                            
        ret[0][0] = 1/a[0][0];
    } else {                                        //неособенная матрица
        inverse(a, ret, n);
    }
    
    mul(ret, save_a, check, n);                     //проверка
    cout << "\nChecking: " << endl;
    prt_mat(check,n);                               //ответ
    cout << "\nSolution: " << endl;
    prt_mat(ret,n);

END:
    delete[] * a;
    delete[] * save_a;
    delete[] * ret;
    delete[] * check;
    return 0;
}