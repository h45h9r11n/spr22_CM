#include <iostream>
#include <math.h>
#include <numbers>
using std::cout;
using std::cin;
using std::endl;

double infunc (int num, double x){
    if (num == 1){
        return 2 * pow(x,3) + pow(x,2) - 7;
    }
    if (num == 2){
        return 5*cos(3*x) + x/2 - 2;
    }

    if (num == 3){
        return pow(x,5) - 2*pow(x,4) + 6*pow(x,2) + 2*x - 4;
    }
    if (num == 4){
        return pow(x, 3) - 0.2 * pow(x, 2) - 0.2 * x - 1.2;
    }
    if (num == 5){
        return log(abs(pow(x, 3)) + 1) + pow(x, 3) - 2;
    }
}

void solve(double (*f)(int, double), double a, double b, double err, int num){
    double fa = f(num, a), fb = f(num, b);
    if (fa*fb > 0){
        cout << "There is no solution in the given interval." << endl;
    } else {
        double x;
        while (b - a > err){
            x = (a + b)/2;
            if (f(num, x)*fa < 0){
                b = x;
                fb = f(num, x);
            } else if (f(num, x)*fb < 0){
                a = x;
                fa = f(num, x);
            }
        }
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
    solve(infunc, a, b, err, num);
}