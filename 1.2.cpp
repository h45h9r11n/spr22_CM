#include <iostream>
#include <math.h>
#include <numbers>
using std::cout;
using std::cin;
using std::endl;

double infunc (int num, double x){
    if (num == 1){
        return pow(5, x) * sqrt(pow(8, (x - 1))) - 189;
    }

    if (num == 2){
        return pow(x, 3) - pow(x, 2) + 2 * x - 5;
    }

    if (num == 3){
        return 2 * log10(pow(x, 2)) - 5 * pow(log10(x), 2) + 4;
    }
    if (num == 4){
        return 2 * sin(2 * x) - cos(3 * x) - 0.5;
    }
    if (num == 5){
         return 2 * pow(x, 3) - 7 * pow(x, 2) - 7 * x - 2.5;
    }
}

double dfunc(int num, double x) {
    if (num == 1){
        return sqrt(2) * pow(5, x) * (pow(log(8), 2) + 4 * pow(log(5), 2) + 4 * log(5) *log(8)) * sqrt(pow(8, x)) / 16;
    }
    if (num == 2){
        return 6 * x - 2;
    }
    if (num == 3){
        return (2 * (5 * log10(x) - 5 / log(10)) - 2) / (pow(x, 2) * log(10));
    }
    if (num == 4){
        return (-8 * sin(2 * x) + 9 * cos(3 * x));
    }
    if (num == 5){
        return (2 * (6 * x - 7));
    }
}

void solve(double (*f)(int, double), double (*df)(int, double), double a, double b, double err, int num){
    double fa = f(num, a), fb = f(num, b);
    if (fa*fb > 0){
        cout << "There is no solution in the given interval." << endl;
    } else {
        double x, x0;
        if (df(num, b) * f(num, b) < 0) x = a;
        if (df(num, a) * f(num, a) < 0) x = b;
        do {
            x0 = x;
            x = a - f(num, a) * (b - a)/(f(num, b) - f(num, a));
            if (f(num, x)*f(num, a) < 0){
                b = x;  
            } else if (f(num, x)*f(num, b) < 0){
                a = x;
            }
        } while (fabs(x0 - x) > err);
        cout << "Solution: " << x << endl;  
    }
}

int main(){
    int num;
    double a,b;
    double err;
    cout << "Choose equation: " << endl;
    cin >> num;
    cout << "Enter interval: " << endl;
    cin >> a >> b;
    cout << "Accuracy: ";
    cin >> err;
    solve(infunc, dfunc, a, b, err, num);
}
