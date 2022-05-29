#include <iostream>
#include <math.h>
#include <numbers>
using std::cout;
using std::cin;
using std::endl;

double func (int num, double x){
    if (num == 1){
        return x*x;
    } else if (num == 2){
        return sin(x)*sin(x);
    } else if (num == 3){
        return sin(2*x) + cos(7*x) + 8;
    } else if (num == 4){
        return 2*pow(x,4) + pow(x,3) + 2*pow(x,2) + 3*x + 24;
    } else if (num == 5){
        return log(pow(x,2) + 1) + sin(x/3) + 17;
    } else if (num == 6){
        return (5,x) + sin(x) + x + 11;
    } else if (num == 7){
        return pow(x,5) + 2*pow(x,4) + 3*pow(x,3) + 4*pow(x,2) + 5*x + 6;
    }
    return 0;
}

double solve(double (*f)(int, double), double a, double b, int num, int n){
    double result = 0, h = (b - a) / n;
    for(int i = 0; i < n; i++) {
        result += func(num, a + h * i);
    }
    result *= h;
    return result;
}

int main(){
    int num, n;
    double a,b;
    double err;
    cout << "Choose equation: " << endl;
    cin >> num;
    cout << "Enter interval and n: " << endl;
    cin >> a >> b >> n;
    cout << "Result " << solve(func, a, b, num, n) << endl;
}
