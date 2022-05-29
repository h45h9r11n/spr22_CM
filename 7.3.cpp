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

double ddfunc (int num, double x){
    if (num == 1){
        return 2;
    } else if (num == 2){
        return 2 * (cos(x) * cos(x) - sin(x) * sin(x));
    } else if (num == 3){
        return -59 * cos(7 * x) - 4 * sin(2 * x);;
    } else if (num == 4){
        return 24 * x * x + 6 * x + 4;
    } else if (num == 5){
        return - 2 * (x * x - 1) / pow((x * x + 1), 2) - 1 / 9 * sin(x / 3);
    } else if (num == 6){
        return pow(5, x) * log(5) * log(5) - sin(x);
    } else if (num == 7){
        return 6 * (10 * x * x + 8 * x + 3);
    }
    return 0;
}

double solve(double a, double b, int num, int n){
    double result = 0, h = (b - a) / n;
    b = a + h;
    for(int i = 0; i < n; i++){
        result += func(num, a) + func(num, b);
        a = b;
        b += h;
    }
    return result*h*0.5;
}

double r_cal(double a, double b, int num, int n){
    double sum = 0, h = (b - a) / n;
    while (a <= b){
        sum += ddfunc(num, a);
        a += h;
    }
    return -pow(h,3)/12 *sum;
}

int main(){
    int num, n;
    double a,b;
    double err;
    cout << "Choose equation: " << endl;
    cin >> num;
    cout << "Enter interval and n: " << endl;
    cin >> a >> b >> n;
    cout << "Result " << solve(a, b, num, n) << endl;
    cout << "R = " << r_cal(a, b, num, n) << endl;
}
