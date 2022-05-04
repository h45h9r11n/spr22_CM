#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

double f1(double x){ return 2*log10(x) - cos(x);}
double df1(double x){ return 2 / (x * log(10)) + sin(x);}

double f2(double x){ return 2 * pow(x, 3) - 5 * pow(x, 2) - 1;}
double df2(double x){ return 6 * pow(x, 2) - 10 * x;}

double f3(double x){ return 2 * pow(sin(2 * x), 3) - cos(x);}
double df3(double x){ return 12 * pow(sin(2 * x), 2) * cos(2 * x) + sin(x);}

double f4(double x){ return pow(x, 5) - 3 * pow(x, 4) + 8 * pow(x, 2) + 2 * x - 7;}
double df4(double x){ return 5 * pow(x, 4) - 12 * pow(x, 3) + 16 * x + 2;}

double f5(double x){ return 0.5 * pow(x, 2) + 5 * cos(2 * x) - 2;}
double df5(double x){ return x - 10 * sin(2 * x);}

double newton(double (*f)(double), double (*df)(double), double x0, double err){
    
    double x1 = x0 - f(x0)/df(x0);
    int count = 0;
    while (fabs(x0 - x1) >= err){
        x0 = x1;
        x1 = x0 - f(x0)/df(x0);
        count++;
    }
    cout << "Root: "<< x1 << endl;
    cout << "Number of loops: "<< count << "\n" << endl;
    return x1;
}

int main(){
    double err, x0;
    cout << "Initial approximation : ";
    cin >> x0;
    cout << "Accuracy: ";
    cin >> err;
    cout << "\f1: ";
    newton(f1,df1,x0,err);
    cout << "Initial approximation : ";
    cin >> x0;
    cout << "Accuracy: ";
    cin >> err;
    cout << "\nf2: ";
    newton(f2,df2,x0,err);
    cout << "Initial approximation : ";
    cin >> x0;
    cout << "Accuracy: ";
    cin >> err;
    cout << "\nf3: ";
    newton(f3,df3,x0,err);
    cout << "Initial approximation : ";
    cin >> x0;
    cout << "Accuracy: ";
    cin >> err;
    cout << "\nf4: ";
    newton(f4,df4,x0,err);
    cout << "Initial approximation : ";
    cin >> x0;
    cout << "Accuracy: ";
    cin >> err;
    cout << "\nf5: ";
    newton(f5,df5,x0,err);

    return 0;
}