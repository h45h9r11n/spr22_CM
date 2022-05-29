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

double d4func (int num, double x){
    if (num == 1){
        return 0;
    } else if (num == 2){
        return (8*(pow(sin(x),2) - pow(cos(x),2)));
    } else if (num == 3){
        return (16*sin(2*x)+2401*cos(7*x));
    } else if (num == 4){
        return 48;
    } else if (num == 5){
        return -96*(pow(x,4)/pow(pow(x,2)+1, 4)) + 96*(pow(x,2)/pow(pow(x,2)+1,3)) + sin(x/3)/81 -
12/(pow(pow(x,2)+1,2));
    } else if (num == 6){
        return (pow(5,x)*pow(log(5),4) + sin(x));
    } else if (num == 7){
        return (24*(5*x+2));
    }
    return 0;
}

double solve(double a, double b, int num, int n){
    double k1 = 0, k2 = 0;
    double h = (b - a) / n;
    for (int i = 1; i < n; i += 2) {
        k1 += func(num, a + i * h);
        k2 += func(num, a + (i + 1) * h);
    }
    k1 = h / 3 * (func(num,a) + 4 * k1 + 2 * k2);
    return k1;
}

double r_cal(double a, double b, int num, int n){
    double sum = 0, h = (b - a) / n;
    while (a <= b){
        sum += d4func(num, a);
        a += h;
    }
    return pow(h,5)/90 *sum;
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
